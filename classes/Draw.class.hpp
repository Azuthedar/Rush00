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

class Draw
{
	public:
		Draw();
		Draw(Draw const & src);
		~Draw();

		Draw &	operator=(Draw const & rhs);

		void	initScreen();
		void	destroyWindow();
		int		getWinX();
		int		getWinY();
		
	private:

		int			_winX;
		int			_winY;
		std::string	winName;
		
};

#endif