#pragma once

#include "../main.hpp"


class Bullet : public AGameObject
{
	public:
		Bullet();
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