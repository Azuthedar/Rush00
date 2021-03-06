/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 08:35:03 by jbuys             #+#    #+#             */
/*   Updated: 2017/05/27 08:35:04 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "AGameObject.class.hpp"
#include "Enemy.class.hpp"
#include "../main.hpp"
#include "Bullet.class.hpp"

class Enemy;
class Bullet;
class Player : public AGameObject
{
	public:

		Player();
		Player(Player const & src);
		~Player();

		Player& 		operator=(Player const & src);
		
		void 			render();
		void			collision(Enemy *enemy, int maxEnemies);
		void 			movement();
		void			fire(int i);
		Bullet*			getBullet(int i);
		virtual bool	movement(int ch, Enemy *enemy, int maxEnemies);

	private:
		Bullet* _bullet[50];//changing bullet amount increase bulelt burst
};
