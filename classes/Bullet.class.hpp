#pragma once

#include "../main.hpp"
#include "Enemy.class.hpp"

class Enemy;

class Bullet : virtual public AGameObject
{
	public:
		Bullet();
		Bullet(int x, int y);
		Bullet(Bullet const & src);
		~Bullet();

		Bullet &	operator=(Bullet const & rhs);
		
		void		doDamage(Enemy enemy);
		void		collision(Enemy *enemy, int maxEnemies);
		void		movement();
		void		render();

	private:
		int	_damage;

};