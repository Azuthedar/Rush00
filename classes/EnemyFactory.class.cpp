#include "EnemyFactory.class.hpp"

EnemyFactory::EnemyFactory()
{
	return ;
}

EnemyFactory::EnemyFactory(int maxAmount) : _maxAmount(maxAmount)
{
	this->_enemy = new Enemy[this->_maxAmount];
	return ;
}

EnemyFactory::EnemyFactory(EnemyFactory const & src)
{
	*this = src;
	return ;
}

EnemyFactory::~EnemyFactory()
{
	return ;
}

EnemyFactory &		EnemyFactory::operator=(EnemyFactory const & rhs)
{
	this->_enemy = rhs._enemy;
	this->_maxAmount = rhs._maxAmount;
	return (*this);
}

void				EnemyFactory::create(int i)
{
	srand(clock());
	int randomIndex;
	randomIndex = std::rand() % 15;
	if (randomIndex <= 5)
	{
		this->_enemy[i].setShape("@");
	}
	else if (randomIndex > 5 && randomIndex <= 10)
	{
		this->_enemy[i].setShape("Y");
		this->_enemy[i].setLives(200);
	}
	else
		this->_enemy[i].setShape("U");
		this->_enemy[i].setLives(150);
}