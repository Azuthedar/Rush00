/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:34:56 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:34:57 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player()
{
	this->_shape = "A";
	this->_lives = 3;
	this->_xPos = BORDERSIZEX / 2;
	this->_yPos = BORDERSIZEY - 2;
	this->_type = "Player";
}

Player::Player(Player const & src)
{
	*this = src;
}

Player::~Player()
{

}

Player & Player::operator=(Player const & src)
{
	this->_shape = src.getShape();
	this->_lives = src.getLives();
	this->_xPos = src.getXPos();
	this->_yPos = src.getYPos();
	this->_type = src.getType();

	return (*this);
}

void Player::render()
{
   mvprintw(this->_yPos, this->_xPos, this->_shape.c_str());
}

void Player::Fire()
{

}

void Player::collision(Enemy *enemy, int maxEnemies)
{
	int i = 0;
	int enemyX, enemyY;

	while (i < maxEnemies)
	{
		enemyX = enemy[i].getXPos();
		enemyY = enemy[i].getYPos();

		if (this->_xPos == enemyX && this->_yPos == enemyY)
		{
			if (this->_lives > 0)
			{
				this->_lives--;
				this->_xPos = BORDERSIZEX / 2;
				this->_yPos = BORDERSIZEY - 2;
			}
			else
				delete this;
		}

		i++;
	}
}

void Player::movement()
{}

bool Player::movement(int ch, Enemy *enemy, int maxEnemies)
{
		switch (ch)
		{
			case KEY_LEFT: /* user pressed backspace */
		  		if (this->_xPos > 1)
			 		this->_xPos -= 1;
				break;
			case KEY_UP:  /* user pressed up arrow key */
		 		if (this->_yPos > 1)
			 		this->_yPos -= 1;
			 	break;
			case KEY_DOWN:  /* user pressed up arrow key */
		  		if (this->_yPos < BORDERSIZEY - 1)
			 		this->_yPos += 1;
			 	break;
		  	case KEY_RIGHT:   /* user pressed right arrow */
		  		if (this->_xPos < BORDERSIZEX - 1)
					 this->_xPos += 1;
			 	break;
			case 27:
				return (FALSE);
	 }
	 collision(enemy, maxEnemies);
	 return (TRUE);
}