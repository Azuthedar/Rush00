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
	this->destroyWindow();
}

Draw &		operator=(Draw const & rhs)
{
	this->_winX = rhs._winX;
	this->_winY = rhs._winY;
	this->_winName = rhs._winName;
}

void		Draw::initScreen()
{
	initscr();
	noecho();
	curs_set(false);
}
