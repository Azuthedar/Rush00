/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:34:40 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:34:40 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy()
{
	this->_lives = 100;
	this->_shape = "@";
	return ;
}

Enemy::Enemy(int hp, std::string shape)
{
	this->_lives = hp;
	this->_shape = shape;
	srand(clock());
	int randomIndex = std::rand() % (getmaxx(stdscr) - 2);
	if (randomIndex < 2)
		randomIndex = 2;
	this->_xPos = randomIndex;
	this->_yPos = 2;
	return ;
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
	return ;
}

Enemy::~Enemy()
{
	return ;
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	this->_type = rhs._type;
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_shape = rhs._shape;
	this->_lives = this->_lives;
	return (*this);
}

void	Enemy::render()
{
	mvprintw(this->_xPos, this->_yPos, this->_shape.c_str());	
}

void	Enemy::movement()
{
	this->_yPos += 1;
}

