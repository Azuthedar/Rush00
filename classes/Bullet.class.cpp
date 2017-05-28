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
	this->_damage = 2;
	this->_shape = "|";
	this->_type = "Bullet";
}

Bullet &	Bullet::operator=(Bullet const & rhs)
{
	this->_damage = rhs._damage;
	return (*this);
}

void		Bullet::doDamage(Enemy enemy)
{
	enemy.takeDamage(this->_damage);
}

void		Bullet::collision(Enemy *enemy, int maxEnemies)
{
	int i = 0;
	int enemyX, enemyY;

	while (i < maxEnemies)
	{
		enemyX = enemy[i].getXPos();
		enemyY = enemy[i].getYPos();
		if (enemyX == this->_xPos && (enemyY == this->_yPos || enemyY == this->_yPos - 1))
		{
			doDamage(enemy[i]);
			delete this;
		}
		i++;
	}
	if(this->_yPos == 1)
	{
		//this = nullptr;
	}
}

void		Bullet::movement()
{
	this->_yPos -= 1;
	if (this->_yPos < 2)
	{
		//this = nullptr;
	}
}