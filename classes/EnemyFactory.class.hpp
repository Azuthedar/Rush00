#pragma once

#include "../main.hpp"
#include "Enemy.class.hpp"

class EnemyFactory
{
	public:
		EnemyFactory();
		EnemyFactory(int maxAmount);
		EnemyFactory(EnemyFactory const & src);
		~EnemyFactory();
	
		EnemyFactory &		operator=(EnemyFactory const & rhs);

		void				randomEnemy();
		void				create(int i);

	private:
		Enemy 	*_enemy;
		int		_maxAmount;

};