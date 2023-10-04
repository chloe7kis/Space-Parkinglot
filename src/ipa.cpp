#include <iostream>
#include "figure.h"
#include "figures.h"
#include "parkinglot.h"
#include "singleton.h"
#include <queue>
#include <vector>
//#include <windows.h>//only for windows

using namespace std;
void TimeStep(int n)
{
    glutTimerFunc(n, TimeStep, n);
    glutPostRedisplay();
}
void glDraw()
{
    static Parkinglot lot(0, 0);
    static int flag = 0;
    static int vecnum = rand()%20+20;//number of cars is randomly distributed from 20 to 40
    static Vehicles **vecs = new Vehicles *[vecnum];
    if (flag == 0)//randomly decide the type
    {
        for (int i = 0; i < vecnum; i++)
        {
            switch (rand() % 3)
            {
            case 0:
                vecs[i] = new Car;
                break;
            case 1:
                vecs[i] = new Rocket;
                break;
            case 2:
                vecs[i] = new UFO;
                break;
            default:
                break;
            }
        }
        for (int i = 0; i < vecnum; i++)
        {
            vecs[i]->set(lot.getstallnum(), lot.getAnchor(), lot.find());//initialize the cars
        }
        flag++;
    }
    static int cnt = 0;//count how many cars have arrived
    Singleton *s = Singleton::getInstance();
    s->setcurrent(vecs[cnt]);
    (s->getcurrent())->enter();
    if ((s->getcurrent())->getarrived())
    {
        cnt++;
        if (cnt < vecnum&&cnt<lot.emptynum())//end the game when the parking lot is full or there is no car waiting to enter
            s->setcurrent(vecs[cnt]);
        else
        {
            Singleton::deleteInstance();//free the memory
            for (int i = 0; i < vecnum; i++)
            {
                delete vecs[i];
            }
            delete[] vecs;
            glutLeaveMainLoop();
            return;
        }
    }
    switch ((s->getcurrent())->getstate())
    {
    case -1:
        lot.iscar();
        break;
    case 0:
        break;
    default:
        lot.out();
        break;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    lot.pole_draw();
    lot.draw(); 
    for (int i = 0; i <= cnt; i++)
        vecs[i]->draw();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 500);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    glutInitWindowPosition(-50, 0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Interstellar car park");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(200, TimeStep, 10);
    glutMainLoop();
    glutExit();
    return 0;
}
