#include "rectangle.h"

tRectangle::tRectangle(float a, float b)
{
    setR(a, b);
    setFi(a, b);
    setXtl(this->getX(), 0);
    setYtl(this->getY(), 0);
    setXtr(this->getX(), 0);
    setYtr(this->getY(), 0);
    setXbl(this->getX(), 0);
    setYbl(this->getY(), 0);
    setXbr(this->getX(), 0);
    setYbr(this->getY(), 0);
}

void tRectangle::setR(float a, float b)
{
    this->_R = sqrt(pow(a, 2) + pow(b, 2)) / 2;
}

void tRectangle::setFi(float a, float b)
{
    this->_Fi = atan(b / a);
}

void tRectangle::setXtl(float c, float fi)
{
    this->_Xtl = c + (this->getR() * cos(M_PI - this->getFi() + fi));
}

void tRectangle::setYtl(float c, float fi)
{
    this->_Ytl = c + (this->getR() * sin(M_PI - this->getFi() + fi));
}

void tRectangle::setXtr(float c, float fi)
{
    this->_Xtr = c + (this->getR() * cos(this->getFi() + fi));
}

void tRectangle::setYtr(float c, float fi)
{
    this->_Ytr = c + (this->getR() * sin(this->getFi() + fi));
}

void tRectangle::setXbl(float c, float fi)
{
    this->_Xbl = c + (this->getR() * cos(M_PI + this->getFi() + fi));
}

void tRectangle::setYbl(float c, float fi)
{
    this->_Ybl = c + (this->getR() * sin(M_PI + this->getFi() + fi));
}

void tRectangle::setXbr(float c, float fi)
{
    this->_Xbr = c + (this->getR() * cos(0 - this->getFi() + fi));
}

void tRectangle::setYbr(float c, float fi)
{

    this->_Ybr = c + (this->getR() * sin(0 - this->getFi() + fi));
}

float tRectangle::getR()
{
    return this->_R;
}

float tRectangle::getFi()
{
    return this->_Fi;
}

float tRectangle::getXtl()
{
    return this->_Xtl;
}

float tRectangle::getYtl()
{
    return this->_Ytl;
}

float tRectangle::getXtr()
{
    return this->_Xtr;
}

float tRectangle::getYtr()
{
    return this->_Ytr;
}

float tRectangle::getXbl()
{
    return this->_Xbl;
}

float tRectangle::getYbl()
{
    return this->_Ybl;
}

float tRectangle::getXbr()
{
    return this->_Xbr;
}

float tRectangle::getYbr()
{
    return this->_Ybr;
}

float tRectangle::grTOrad(float Gr)
{
    return Gr * M_PI / 180;
}

void tRectangle::rotate(float Gr)
{
    float Rad = this->grTOrad(Gr);
    setXtl(this->getX(), Rad);
    setYtl(this->getY(), Rad);
    setXtr(this->getX(), Rad);
    setYtr(this->getY(), Rad);
    setXbl(this->getX(), Rad);
    setYbl(this->getY(), Rad);
    setXbr(this->getX(), Rad);
    setYbr(this->getY(), Rad);
}
