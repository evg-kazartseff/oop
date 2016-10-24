#ifndef SQUARE_H
#define SQUARE_H

#include <GL/glut.h>
#include <cmath>
#include "point.h"
#include <iostream>
class tRectangle : public tPoint
{
    private:
        float _Fi;
        float _R;

        float _Xtl;
        float _Ytl;

        float _Xtr;
        float _Ytr;

        float _Xbl;
        float _Ybl;

        float _Xbr;
        float _Ybr;
    public:

        tRectangle(float a, float b);

        void setR(float a, float b);
        void setFi(float a, float b);

        void setXtl(float c, float fi);
        void setYtl(float c, float fi);
        void setXtr(float c, float fi);
        void setYtr(float c, float fi);
        void setXbl(float c, float fi);
        void setYbl(float c, float fi);
        void setXbr(float c, float fi);
        void setYbr(float c, float fi);

        float getR();
        float getFi();

        float getXtl();
        float getYtl();
        float getXtr();
        float getYtr();
        float getXbl();
        float getYbl();
        float getXbr();
        float getYbr();

        float grTOrad(float Gr);
        void rotate(float Gr);
};

#endif
