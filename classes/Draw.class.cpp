/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:34:28 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:34:29 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.hpp"


Draw::Draw()
{
	this->_winX = 80;
	this->_winY = 50;
	this->_startX = 100;
	this->_startY = 5;
	// Ratio to use for window 1:2
	this->initScreen();
	return ;
}

Draw::Draw(Draw const & src)
{
	*this = src;
	return ;
}

Draw::~Draw()
{
	return;
}

Draw &	Draw::operator=(Draw const & rhs)
{
	this->_winX = rhs._winX;
	this->_winY = rhs._winY;
	this->_winName = rhs._winName;
	return *this;
}
WINDOW* 	Draw::getWin(){
	return this->_win;
}

void		Draw::initScreen()
{
	initscr();
	noecho();
	curs_set(false);
	this->_win = newwin(this->_winY, this->_winX, this->_startY, this->_startX);
}

void Draw::drawBox()
{
	getmaxyx(this->_win, this->_winY, this->_winX);
	if (this->_winY > 50 || this->_winX > 80)
	{
		clear();
		box(this->_win, 40,60);
		wrefresh(this->_win);
	}
	else
	{
		printw("The screen is too small");
	}
}
