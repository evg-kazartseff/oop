#include "ellipse.h"

tEllipse::tEllipse(float A, float B)
{
    setA(A);
    setB(B);
}

void tEllipse::setA(float A)
{
    this->_A = A;
}

void tEllipse::setB(float B)
{
    this->_B = B;
}

void tEllipse::setAngle(float Angle)
{
    this->_Angle = Angle;
}

void tEllipse::setR()
{
    this->_R = (getA() * getB()) / (sqrt(pow(getB(), 2) * pow(cos(getAngle()), 2) + pow(getA(), 2) * pow(sin(getAngle()), 2)));
}

void tEllipse::settX()
{
    this->_tX = getX() + getR() * cos(getAngle());
}

void tEllipse::settY()
{
    this->_tY = getY() + getR() * sin(getAngle());
}

float tEllipse::getA()
{
    return this->_A;
}

float tEllipse::getB()
{
    return this->_B;
}

float tEllipse::getR()
{
    return this->_R;
}

float tEllipse::getAngle()
{
    return this->_Angle;
}

float tEllipse::gettX()
{
    return this->_tX;
}

float tEllipse::gettY()
{
    return this->_tY;
}
