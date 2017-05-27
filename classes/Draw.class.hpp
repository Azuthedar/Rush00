/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:34:35 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:34:36 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DRAW_CLASS_HPP
#define DRAW_CLASS_HPP

#include "../main.hpp"
#include <string>
#include <ncurses.h>
class Draw
{
	public:
		Draw();
		Draw(Draw const & src);
		~Draw();

		Draw &	operator=(Draw const & rhs);

		void	initScreen();		
		void 	drawBox();
		int		getWinX();
		int		getWinY();
		WINDOW* getWin();
		
	private:

		int			_winX;
		int			_winY;
		int			_startY;
		int			_startX;
		std::string	_winName;
		WINDOW * 	_win;
		
};

#endif