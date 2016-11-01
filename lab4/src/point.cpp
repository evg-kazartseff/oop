#include "point.h"

tPoint::tPoint()
{
    setX(200);
    setY(200);
    setVecX(-100 + rand () % 100);
    setVecY(-100 + rand () % 100);
    setSize(3);
}

void tPoint::setX(float x)
{
    this->_x = x;
}

void tPoint::setY(float y)
{
    this->_y = y;
}

void tPoint::setSize(float size)
{
    this->_size = size;
}

float tPoint::getX()
{
    return this->_x;
}

float tPoint::getY()
{
    return this->_y;
}

float tPoint::getSize()
{
    return this->_size;
}

void tPoint::setVecX(float vecX)
{
    this->_vecX = vecX;
}

void tPoint::setVecY(float vecY)
{
    this->_vecY = vecY;
}

float tPoint::getVecX()
{
    return this->_vecX;
}

float tPoint::getVecY()
{
    return this->_vecY;
}

void tPoint::move()
{
    this->setX(this->getX() + (this->getVecX() * 0.01));
    this->setY(this->getY() + (this->getVecY() * 0.01));
}
