#include "point.h"

tPoint::tPoint()
{
    srand(time(NULL) * rand());
    setX(rand() % 400);
    setY(rand() % 400);
    setVecX(-100 + rand () % 100);
    setVecY(-100 + rand () % 100);
    setR(1);
    setG(0);
    setB(0);
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

void tPoint::setR(float r)
{
    this->_r = r;
}

void tPoint::setG(float g)
{
    this->_g = g;
}

void tPoint::setB(float b)
{
    this->_b = b;
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

float tPoint::getR()
{
    return this->_r;
}

float tPoint::getG()
{
    return this->_g;
}

float tPoint::getB()
{
    return this->_b;
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

void tPoint::chMove()
{
    srand(time(NULL) * rand());
    float fMax = 2;
    float fMin = -2;
    float f = (float) rand() / RAND_MAX;
    float r = fMin + f * (fMax - fMin);
    this->setX(this->getX() + r);
    f = (float) rand() / RAND_MAX;
    r = fMin + f * (fMax - fMin);
    this->setY(this->getY() + r);
}
