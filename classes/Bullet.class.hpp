#pragma once

#include "../main.hpp"


class Bullet : public AGameObject
{
	public:
		Bullet();
		Bullet(Bullet const & src);
		~Bullet();

		Bullet &	operator=(Bullet const & rhs);
		
		void		doDamage();
		void		collision();

	private:
		int	_damage;
		Enemy &_enemy;

}