#include "main.hpp"
#include <time.h>

void update();
void render();
void initScreen();
void movement();
void drawBox();

bool loop = TRUE;
int step = 0;
int maxEnemies = 50;


Player	*player = new Player();
Enemy	*enemies = new Enemy[maxEnemies];

int main()
{
	int winX, winY;

	initScreen();
	while (loop == TRUE)
	{
		step++;
		if (step > 100000)
			step = 0;
		if (player->getLives() > 0)
		{
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
			usleep(800);
		}
		else
		{
			clear();
			printw("You have died:\nGAME OVER");
			usleep(1000);
			loop = FALSE;
			refresh();
		}
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
	static int i = 0;
    srand(time(NULL));
    if (i < maxEnemies && step % 500 == 0)
    {
        enemies[i].setYPos(2);
        enemies[i].randXPos();
        i++;
    }
    for (int j = 0; j < maxEnemies; j++)
        enemies[j].render();
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
	srand(clock());
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
		loop = player->movement(getch(), enemies, maxEnemies);
	if (step % 200 == 0)
	{
		i = 0;
		while (player->getBullet(i) != nullptr && i < 50)
		{
			i++;
		}
		player->fire(i);
	}
	if(step % 10 == 0)
	{
		i = 0;
		while (i < 10)
		{
			if (player->getBullet(i) != nullptr)
			{
				if (player->getBullet(i)->getYPos() != 0)
				{
					player->getBullet(i)->movement(enemies, maxEnemies);
				}
			}
			i++;
		}
	}
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
