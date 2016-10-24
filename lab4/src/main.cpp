#include <GL/glut.h>
#include "point.h"
#include "rectangle.h"
#include <cmath>
#include <iostream>

using namespace std;

tPoint p = tPoint();
tRectangle s = tRectangle(100, 150);

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(3);

    glBegin(GL_POINTS);

    glVertex2f(s.getX(), s.getY());

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex2f(s.getXtl(), s.getYtl());
    glVertex2f(s.getXtr(), s.getYtr());

    glVertex2f(s.getXtr(), s.getYtr());
    glVertex2f(s.getXbr(), s.getYbr());

    glVertex2f(s.getXbr(), s.getYbr());
    glVertex2f(s.getXbl(), s.getYbl());

    glVertex2f(s.getXbl(), s.getYbl());
    glVertex2f(s.getXtl(), s.getYtl());

    glEnd();
    glutSwapBuffers();
}

void timer(int = 0)
{
        for (size_t i = 0; i < 360; i++) {
            Display();
            s.rotate(i);
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
