#include "main.hpp"

void update();
void render();
void initScreen();
void movement();
void drawBox();

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
		if (winY < BORDERSIZEY || winX < BORDERSIZEX)
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
	endwin();
	system("clear");
	std::cout << "Your game has finished!" << std::endl;
	return 0;
}

void update()
{
	clear();
	movement();
	drawBox();
	usleep(1000);
}

void render()
{
	int i = 0;
	srand(time(NULL));
	while (i < maxEnemies)
	{
		if (enemies[i].getLives() != 0)
		{
			enemies[i].setShape("@");
			enemies[i].render();
			enemies[i].randomiseXPos();
		}
		i++;
	}
	player->setShape("A");
	player->render();
	refresh();
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
	if (step % 300 == 0)
	{
		while (i < maxEnemies)
		{
			//MAKE CHECK TO SEE IF ENEMIES EXIST.
			enemies[i].movement();
			i++;

		}
	}
	if (step % 10 == 0)
		player->movement(getch());
}

void	drawBox()
{
	for (int yWin = 0; yWin <= BORDERSIZEY; yWin++)
	{
		for (int xWin = 0; xWin <= BORDERSIZEX; xWin++)
		{
			if (xWin == 0 || xWin == BORDERSIZEX)
				mvprintw(xWin, yWin, "-");
			else if (yWin == 0 || yWin == BORDERSIZEY)
				mvprintw(xWin, yWin, "|");
		}
	}
}