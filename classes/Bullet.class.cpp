#include "Bullet.class.hpp"

Bullet::Bullet()
{
	this->_damage = 80;
	this->_shape = "|";
	this->_type = "Bullet";
	return ;
}

Bullet::Bullet(Bullet const & src)
{
	*this = src;
}

Bullet::~Bullet()
{
	return ;
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
}

void		Bullet::movement()
{
	this->_yPos -= 1;
	if (this->_yPos < 2)
	{
		delete this;
	}
}