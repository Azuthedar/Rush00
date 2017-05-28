#include "Bullet.class.hpp"

Bullet::Bullet()
{
	this->_enemy = 
	this->_damage = 80;
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

void		Bullet::doDamage();
{
	enemy.takeDamage();
}