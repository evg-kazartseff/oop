#include <GL/glut.h>
#include <vector>
#include "point.h"
#include <cmath>
#include <iostream>

#define count_vertex 100

using namespace std;

vector<tPoint> p;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
        if (i->getSize() <= 2)
        {
            glPointSize(2);
            glColor3f(i->getR(), i->getG(), i->getB());
            glBegin(GL_POINTS);
            glVertex2f(i->getX(), i->getY());
            glEnd();
        }
        else
        {
            glBegin(GL_LINES);
            glColor3f(i->getR(), i->getG(), i->getB());
            for (int a = 0; a < 360; ++a)
            {
                float x = i->getSize() * cos(a * M_PI / 180);
                float y = i->getSize() * sin(a * M_PI / 180);
                glVertex2f(i->getX() + x, i->getY() + y);
                x = i->getSize() * cos((a + 1) * M_PI / 180);
                y = i->getSize() * sin((a + 1) * M_PI / 180);
                glVertex2f(i->getX() + x, i->getY() + y);
            }
            glEnd();
        }
    }
    glutSwapBuffers();
}

void timer(int = 0)
{
    Display();
    for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
        for (vector<tPoint>::iterator j = p.begin(); j != p.end(); ++j) {
            if (i != j) {
                float d = sqrt(pow(i->getX() - j->getX(), 2) + pow(i->getY() - j->getY(), 2));
                if (d <= (i->getSize() + j->getSize() + 1)) {
                    float f = 99 * (i->getSize() + j->getSize() - d);
                    i->setVecX(i->getVecX() + f * (i->getX() - j->getX()) / d / i->getSize() * 0.1);
                    i->setVecY(i->getVecY() + f * (i->getY() - j->getY()) / d / i->getSize() * 0.1);

                    j->setVecX(j->getVecX() - f * (i->getX() - j->getX()) / d / j->getSize() * 0.1);
                    j->setVecY(j->getVecY() - f * (i->getY() - j->getY()) / d / j->getSize() * 0.1);
                }
            }
        }
    }
    int flg = 1;
    if (flg) {
        for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
            if (i->getX() < 0 || i->getX() > 400)
                i->setVecX(-1 * i->getVecX());
            if (i->getY() < 0 || i->getY() > 400)
                i->setVecY(-1 * i->getVecY());
        }
        for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
            cout << i->getX() << ' ' << i->getY() << endl;
            i->move();
        }
    }
    else {
        for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
            if (i->getX() < 0)
                i->setX(i->getX() + 2);
            if (i->getY() < 0)
                i->setY(i->getY() + 2);
            if (i->getX() > 400)
                i->setX(i->getX() - 2);
            if (i->getY() > 400)
                i->setY(i->getY() - 2);
        }
        for (vector<tPoint>::iterator i = p.begin(); i != p.end(); ++i) {
            cout << i->getX() << ' ' << i->getY() << endl;
            i->chMove();
        }
    }
    glutTimerFunc(5, timer, 0);
}

int main(int argc, char **argv)
{
    for (int i = 0; i < count_vertex; ++i) {
        tPoint p0 = tPoint();
        p.push_back(p0);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("lab 3");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(Display);
    timer();
    glutMainLoop();
}
