#pragma once 

#include <iostream>
#include <curses.h>
#include <string>

class AGameObject //Generic Abstract Class for all entities in the game
{
	public:
	
		AGameObject();
		AGameObject(AGameObject const & src);
		virtual ~AGameObject();

		AGameObject& operator=(AGameObject const & src);

		std::string getType()const;
		void setType(std::string type);
		int getXPos()const;
		void setXPos(int x);
		int getYPos()const;
		void setYPos(int y);
		std::string getShape()const;
		void setShape(std::string shape);
		int getLives()const;
		void setLives(int life);

		virtual void movement()=0;

	protected:

		std::string _type;
		int _xPos;
		int _yPos;
		std::string _shape;
		int _lives;
};