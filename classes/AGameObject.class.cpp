#include "AGameObject.class.hpp"

AGameObject::AGameObject()
{

}

AGameObject::AGameObject(AGameObject const & src)
{
    *this = src;
}

AGameObject::~AGameObject()
{

}

std::string AGameObject::getType()const
{
    return this->_type;
}

void AGameObject::setType(std::string type)
{
    this->_type = type;
}

int AGameObject::getXPos()const
{
    return this->_xPos;
}

void AGameObject::setXPos(int x)
{
    this->_xPos = x;
}

int AGameObject::getYPos()const
{
    return this->_yPos;
}

void AGameObject::setYPos(int y)
{
    this->_yPos = y;
}

int AGameObject::getLives()const
{
    return this->_lives;
}

void AGameObject::setLives(int life)
{
    this->_lives =life;
}

std::string AGameObject::getShape()const
{
    return this->_shape;
}

void AGameObject::setShape(std::string name)
{
    this->_shape = name;
}

AGameObject& AGameObject::operator=(AGameObject const & src)
{
    this->_shape = src.getShape();
    this->_lives = src.getLives();
    this->_yPos = src.getYPos();
    this->_xPos = src.getXPos();
    this->_type = src.getType();

    return (*this);
}