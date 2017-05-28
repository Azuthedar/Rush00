/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:34:42 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:34:43 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../main.hpp"
#include <curses.h>

class Enemy : public AGameObject
{
	public:
		Enemy();
		Enemy(int hp, std::string shape);
		Enemy(Enemy const & src);
		~Enemy();

		Enemy &			operator=(Enemy const & rhs);

		virtual void	render();
		virtual void	movement();
		void			randXPos();
		void			takeDamage(int amount);
		void			create();
		
	private:


};
