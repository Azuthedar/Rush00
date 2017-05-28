#include "Bullet.class.hpp"

Bullet::Bullet()
{
}

Bullet::Bullet(Bullet const & src)
{
	*this = src;
}

Bullet::~Bullet()
{
	return ;
}

Bullet::Bullet(int x, int y)
{
	this->_xPos = x;
	this->_yPos = y;
	this->_damage = 1000000000;
	this->_shape = "|";
	this->_type = "Bullet";
}

Bullet &	Bullet::operator=(Bullet const & rhs)
{
	this->_damage = rhs._damage;
	return (*this);
}

int		Bullet::doDamage(Enemy enemy)
{
	return(enemy.takeDamage(this->_damage));
}

void		Bullet::movement()
{}

void		Bullet::collision(Enemy *enemy, int maxEnemies)
{
	int i = 0;
	int j;
	int enemyX, enemyY;
	Enemy *en;

	while (i < maxEnemies)
	{
		enemyX = enemy[i].getXPos();
		enemyY = enemy[i].getYPos();
		if (enemyX == this->_xPos && (enemyY == this->_yPos || enemyY == this->_yPos - 1))
		{
			j = doDamage(enemy[i]);
			if (j == 0)
			{
				int randomIndex = std::rand() % 3;
				if (randomIndex == 0)
					en = new Enemy(50, "@");
				if (randomIndex <= 3)
					en = new Enemy(150, "U");
				if (randomIndex <= 5)
					en = new Enemy(150, "Y");
				enemy[i] = *en;
				enemy[i].setLives(100);
			}
		}
		i++;
	}
}

void		Bullet::movement(Enemy *enemy, int maxEnemies)
{
	this->_yPos -= 1;
	collision(enemy, maxEnemies);

}