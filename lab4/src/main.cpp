#include <GL/glut.h>
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "rhombus.h"
#include "ellipse.h"
#include <cmath>
#include <iostream>

#define figure 5

using namespace std;

enum fig
{
    point,
    line,
    rectangle,
    triangle,
    circle,
    rhombus,
};

tPoint p = tPoint();
tLine l = tLine(100, 100, 300, 300);
tRectangle r = tRectangle(100, 150);
tTriangle t = tTriangle(50, 0, 50, 120, 50, 240);
tCircle c = tCircle(200, 200, 100);
tRhombus rh = tRhombus(150, 100);
tEllipse e = tEllipse(80, 50);

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (figure == point) {
        glPointSize(p.getSize());
        glColor3f(1, 0, 0);
        glBegin(GL_POINTS);

        glVertex2f(p.getX(), p.getY());

        glEnd();
    }
    else if (figure == line) {
        glColor3f(1, 0, 0);

        glBegin(GL_LINES);

        glVertex2f(l.getXl(), l.getYl());
        glVertex2f(l.getXr(), l.getYr());

        glEnd();
    }
    else if (figure == rectangle) {
        glColor3f(1, 0, 0);
        glBegin(GL_LINES);

        glVertex2f(r.getXtl(), r.getYtl());
        glVertex2f(r.getXtr(), r.getYtr());

        glVertex2f(r.getXtr(), r.getYtr());
        glVertex2f(r.getXbr(), r.getYbr());

        glVertex2f(r.getXbr(), r.getYbr());
        glVertex2f(r.getXbl(), r.getYbl());

        glVertex2f(r.getXbl(), r.getYbl());
        glVertex2f(r.getXtl(), r.getYtl());

        glEnd();
    }
    else if (figure == triangle) {
        glColor3f(1, 0, 0);
        glPointSize(p.getSize());
        glBegin(GL_POINTS);

        glVertex2f(t.getX(), t.getY());

        glEnd();

        glBegin(GL_LINES);

        glVertex2f(t.getV1X(), t.getV1Y());
        glVertex2f(t.getV2X(), t.getV2Y());

        glVertex2f(t.getV2X(), t.getV2Y());
        glVertex2f(t.getV3X(), t.getV3Y());

        glVertex2f(t.getV3X(), t.getV3Y());
        glVertex2f(t.getV1X(), t.getV1Y());

        glEnd();
    }
    else if (figure == circle) {
        glColor3f(1, 0, 0);
        glBegin(GL_LINES);

        for (size_t i = 0; i < 360; i++) {
            glVertex2f(c.getTmpX(i), c.getTmpY(i));
            glVertex2f(c.getTmpX(i+1), c.getTmpY(i+1));
        }

        glEnd();
    }
    else if (figure == rhombus) {
        glColor3f(1, 0, 0);
        glBegin(GL_LINES);

        glVertex2f(rh.getXtl(), rh.getYtl());
        glVertex2f(rh.getXtr(), rh.getYtr());

        glVertex2f(rh.getXtr(), rh.getYtr());
        glVertex2f(rh.getXbl(), rh.getYbl());

        glVertex2f(rh.getXbl(), rh.getYbl());
        glVertex2f(rh.getXbr(), rh.getYbr());

        glVertex2f(rh.getXbr(), rh.getYbr());
        glVertex2f(rh.getXtl(), rh.getYtl());

        glEnd();
    }

    glutSwapBuffers();
}

void timer(int = 0)
{
    if (figure == point) {
        Display();
        p.move();
    }
    if (figure == line) {
        for (size_t i = 0; i < 360; i++) {
            if (l.getXl() < 0 || l.getXr() < 0 || l.getXl() > 400 || l.getXr() > 400)
                l.setVecX(-1 * l.getVecX());
            if (l.getYl() < 0 || l.getYr() < 0 || l.getYl() > 400 || l.getYr() > 400)
                l.setVecY(-1 * l.getVecY());
            l.move();
            l.rotate(i);
            Display();
        }
    }
    else if (figure == rectangle) {
        for (size_t i = 0; i < 360; i++) {
            if (r.getXtl() < 0 || r.getXtr() < 0 || r.getXbl() < 0 || r.getXbr() < 0)
                r.setVecX(-1 * r.getVecX());
            if (r.getYtl() < 0 || r.getYtr() < 0 || r.getYbl() < 0 || r.getYbr() < 0)
                r.setVecY(-1 * r.getVecY());
            if (r.getXtl() > 400 || r.getXtr() > 400 || r.getXbl() > 400 || r.getXbr() > 400)
                r.setVecX(-1 * r.getVecX());
            if (r.getYtl() > 400 || r.getYtr() > 400 || r.getYbl() > 400 || r.getYbr() > 400)
                r.setVecY(-1 * r.getVecY());
            r.move();
            //r.rotate(i);
            Display();
        }
    }
    else if (figure == triangle) {
        for (size_t i = 0; i < 360; i++) {
            if (t.getV1X() < 0 || t.getV2X() < 0 || t.getV3X() < 0)
                t.setVecX(-1 * t.getVecX());
            if (t.getV1Y() < 0 || t.getV2Y() < 0 || t.getV3Y() < 0)
                t.setVecY(-1 * t.getVecY());
            if (t.getV1X() > 400 || t.getV2X() > 400 || t.getV3X() > 400)
                t.setVecX(-1 * t.getVecX());
            if (t.getV1Y() > 400 || t.getV2Y() > 400 || t.getV3Y() > 400)
                t.setVecY(-1 * t.getVecY());
            //t.move();
            t.rotate(i);
            Display();
        }
    }
    else if (figure == circle) {
        if (c.getR() > c.getX() || c.getR() > (400 - c.getX()))
            c.setVecX(-1 * c.getVecX());
        if (c.getR() > c.getY() || c.getR() > (400 - c.getY()))
            c.setVecY(-1 * c.getVecY());
        c.move();
        Display();
    }
    else if (figure == rhombus) {
        for (size_t i = 0; i < 360; i++) {
            if (rh.getXtl() < 0 || rh.getXtr() < 0 || rh.getXbl() < 0 || rh.getXbr() < 0)
                rh.setVecX(-1 * rh.getVecX());
            if (rh.getYtl() < 0 || rh.getYtr() < 0 || rh.getYbl() < 0 || rh.getYbr() < 0)
                rh.setVecY(-1 * rh.getVecY());
            if (rh.getXtl() > 400 || rh.getXtr() > 400 || rh.getXbl() > 400 || rh.getXbr() > 400)
                rh.setVecX(-1 * rh.getVecX());
            if (rh.getYtl() > 400 || rh.getYtr() > 400 || rh.getYbl() > 400 || rh.getYbr() > 400)
                rh.setVecY(-1 * rh.getVecY());
            rh.move();
            //rh.rotate(i);
            Display();
        }
    }
    glutTimerFunc(5, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("lab 4");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(Display);
    timer();
    glutMainLoop();
}
