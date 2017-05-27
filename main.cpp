#include "main.hpp"

void update();
void render();
void initScreen();
void movement();

int step = 0;
int maxEnemies = 10;


Player	*player = new Player();
Enemy	*enemies = new Enemy[maxEnemies];

int main()
{
	bool loop = TRUE;
	int winX, winY;

	initScreen();
	while (loop)
	{
		step++;
		if (step > 100000)
			step = 0;
		getmaxyx(stdscr, winY, winX);
		if (winY < 30 || winX < 50)
		{
			clear();
			printw("Screen is too small");
			usleep(1000);
			refresh();
		}
		else
		{
			update();
			render();
		}
		usleep(1000);
	}
	system("clear");
	std::cout << "Your game has finished!" << std::endl;
	endwin();
	return 0;
}

void update()
{
	clear();
	movement();
	usleep(1000);
	refresh();
}

void render()
{
	int i = 0;
	while (i < maxEnemies)
	{
		enemies[i].render();
		i++;
	}
	player->render();
}

void initScreen()
{
	initscr();
	noecho();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

void movement()
{
	int i = 0;

	while (i < maxEnemies)
	{
		//MAKE CHECK TO SEE IF ENEMIES EXIST.
		enemies[i].movement();
	}
	if (player->getLives() > 0)
		player->movement();
}

void	drawBox()
{
	for (int yWin = 0; yWin <= 40; yWin++)
	{
		
		for (int xWin = 0; xWin <= 40; xWin++)
		{
			if (xWin == 0 || xWin == 40)
				printw("|");
			else
				printw("-");
		}
	}
}