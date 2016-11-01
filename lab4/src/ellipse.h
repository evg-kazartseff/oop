#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <GL/glut.h>
#include <cmath>
#include "point.h"

class tEllipse : public tPoint
{
    private:
        float _A;
        float _B;

        float _R;
        float _Angle;
        float _tX;
        float _tY;
    public:
        tEllipse(float A, float B);
        void setA(float A);
        void setB(float B);
        void setAngle(float Angle);
        void setR();
        void settX();
        void settY();

        float getA();
        float getB();
        float getR();
        float getAngle();
        float gettX();
        float gettY();
};


#endif
