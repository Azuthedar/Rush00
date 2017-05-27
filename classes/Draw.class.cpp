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
}

void Draw::drawBox()
{
	this->_win = newwin(_winY, _winX, _startY, _startX);
    box(_win, 0,0);
    wrefresh(_win);
}
