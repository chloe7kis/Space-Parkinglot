#include "figures.h"
#include <stdlib.h>

#define PI 3.1415926535
using namespace std;
Vehicles::Vehicles()
{
    state = -1;// -1 stands for outside the parkinglot
    sec = 0;//count the time
    arrived=false;//judge whether the car has already arrived the proper lot.
}
void Vehicles::move(Vec dir)//move the vehicles along the dir vector.
{
    for (int i = 0; i < n; i++)
    {
        ss[i]->move(dir);
    }
    anc = anc + dir;
}
void Vehicles::zoom(double kx)//zoom with respect to the anchor
{
    for (int i = 0; i < n; i++)
    {
        ss[i]->zoom(kx, anc);
    }
}
void Vehicles::enter()//the whole enter process
{
    Vec up(0, .005);
    Vec right(.005, 0);
    Vec down(0, -.005);
    Vec left(-.005, 0);
    switch (state)
    {
    case -1://wait until the pole is open
        if (sec > 120)
        {
            state++;
            sec = 0;
        }
        else
        {
            sec++;
        }
        break;
    case 0:
        if (anc.getY() < turn1.getY())
        {
            move(up);
        }
        else
        {
            state++;
        }
        break;
    case 1:
        if (sec < 157)
        {
            rotate(.01, turn1, 1);
            sec++;
        }
        else
        {
            state++;
            sec = 0;
        }
        break;
    case 2:
        if (turn2.getY() < 0)//for down cars
        {
            if (anc.getX() < turn2.getX())
            {
                move(right);
            }
            else
            {
                sec++;
                if (sec>20)
                {state++;sec=0;}           
            }
        }
        else
        {
            state += 2;
        }
        break;
    case 3:
        if (sec < 157)//stop and reverse
        {
            rotate(.01, turn2, 0);
            sec++;
        }
        else
        {
            if (anc.getY() > (turn2.getY() + turn0.getY()) * .5)
                move(down);
            else
                arrived=true;
        }
        break;
    case 4:
        if (anc.getX() < turn3.getX())
        {
            move(right);
        }
        else
        {
            state++;
        }
        break;
    case 5://turn round
        if (sec < 314)
        {
            rotate(.01, turn3, 0);
            sec++;
        }
        else
        {
            state++;
            sec = 0;
        }
        break;
    case 6:
        if (anc.getX() > turn2.getX())
        {
            move(left);
        }
        else
        {
            sec++;
            if (sec>20)
            {state++;sec=0;}
        }
        break;
    case 7://reverse 
        if (sec < 157)
        {
            rotate(.01, turn2, 0);
            sec++;
        }
        else
        {
            if (anc.getY() < (turn2.getY() + (turn0.getY() * (-1.0))) * .5)
                move(up);
            else
                arrived=true;
        }
        break;
    default:
        break;
    }
}
void Vehicles::rotate(double angle, Vec cen, int dir)//rotate the vehicle with respect to cen,dir=0 stands for anticlockwise, dir=1 stands for clockwise
{
    for (int i = 0; i < n; i++)
    {
        ss[i]->rotate(angle, cen, dir);
    }
    if (dir == 0)
    {
        anc = ((anc - cen) << angle) + cen;
    }
    else
    {
        anc = ((anc - cen) >> angle) + cen;
    }
}
int Vehicles::getstate()//return the state
{
    return state;
}
int Vehicles::getsec()//return the sec
{
    return sec;
}
bool Vehicles::getarrived()//return whether the vehicle has arrived
{
    return arrived;
}
void Car::set(int stallnum, Vec anchor, Vec turn)//set the parameters of the car
{
    double stalllength = 4.0 / stallnum;
    double stallwidth = 1.5 / stallnum;
    setAnchor(anchor + Vec(-.8 / stallnum, -.8 / stallnum));
    turn0 = anchor;
    turn1 = turn0 + Vec(0, stalllength);
    turn2 = turn + Vec(stallwidth, stalllength) * .5;
    if (turn2.getY() > 0)
    {
        turn2 = turn + Vec(stallwidth, stalllength) * (-.5);
    }
    turn3 = Vec(1.5 + turn0.getX(), 0);
    n = 6;
    ss = new coloredfig *[n];
    now = 0;
    Vec s1(.3, .3);
    Vec s2(.3, -.3);
    Vec s3(0, -.5);
    Vec s6(0, .5);
    Vec s5(.3, .5);
    Vec s4(.3, -.5);
    Vec s7(-.3, -.2);
    Vec s8(0, -.4);
    Vec s9(0, .4);
    Vec s10(-.3, .2);
    Vec d1(.1, 0);
    Vec d2(0, .03);
    Vec d3(.5, 0);
    t1.set(anc + s1, .1, (float).3, (float).2, (float).0, 20);
    t2.set(anc + s2, .1, (float).3, (float).2, (float).0, 20);
    t3.set(anc + s3, anc + s4, anc + s5, anc + s6, (float).0, (float).5, (float).5);
    t4.set(anc + s7, anc + s8, anc + s9, anc + s10, (float).0, (float).8, (float).8);
    t5.set(anc + s8 - d1, anc + s8, anc + s8 + d2, anc + s8 + d2 - d1, (float)1, (float)0, (float)0);
    t6.set(anc + s8 - d3, anc + s8, anc + s8 + d2, anc + s8 - d3 + d2, (float)0, (float)0, (float)0);
    ss[0] = &t1;
    ss[1] = &t2;
    ss[2] = &t3;
    ss[3] = &t4;
    ss[4] = &t5;
    ss[5] = &t6;
    zoom(1.25 / stallnum);
}

Car::~Car()//destructor, free the allocated memory
{
    delete[] ss;
}

void Car::draw()//draw the car
{
    flag();
    for (int i = 0; i < n; i++)
    {

        ss[i]->draw();
    }
}

void Car::flag()//locate the flag
{
    Vec m = t6.geta();
    Vec n = t6.getb();
    now++;
    int t = abs((int)now % 100 - 50);
    Vec x = (m * (double)t + n * (100 - t)) * 0.01;
    Vec y = (m - n) * (0.2);
    Vec pt2 = y + x;
    Vec pt3 = pt2 + (y << (PI / 2));
    Vec pt4 = x + (y << (PI / 2));
    t5.set(x, pt2, pt3, pt4, (float)1, (float)0, (float)0);
}

void UFO::set(int stallnum, Vec anchor, Vec turn)//set the parameters of the UFO 
{
    double stalllength = 4.0 / stallnum;
    double stallwidth = 1.5 / stallnum;
    setAnchor(anchor + Vec(-.8 / stallnum, -.8 / stallnum));
    turn0 = anchor;
    turn1 = turn0 + Vec(0, stalllength);
    turn2 = turn + Vec(stallwidth, stalllength) * .5;
    if (turn2.getY() > 0)
    {
        turn2 = turn + Vec(stallwidth, stalllength) * (-.5);
    }
    turn3 = Vec(1.5 + turn0.getX(), 0);
    n = 5;
    ss = new coloredfig *[n];
    now = 0;
    Vec O(0, 0); // center of the halfpoly
    Vec lf1(-0.35, 0);
    Vec lf2(-0.15, 0);
    Vec lf3(-0.1, -0.07);
    Vec lf4(-0.4, -0.07); // left foot
    Vec rf1(0.35, 0);
    Vec rf2(0.15, 0);
    Vec rf3(0.1, -0.07);
    Vec rf4(0.4, -0.07); // right foot
    Vec la1(-0.4, 0.3);
    Vec la2(-0.39, 0.31);
    Vec la3(-0.8, 0.6);
    Vec la4(-0.79, 0.61); // left antenna
    Vec ra1(0.4, 0.3);
    Vec ra2(0.39, 0.31);
    Vec ra3(0.8, 0.6);
    Vec ra4(0.79, 0.61);                                                              // right antenna
    t1.set(anc + O, (float).5, (float)0, (float)1, (float)0, 20, (double)0);          // blue
    t2.set(anc + lf1, anc + lf2, anc + lf3, anc + lf4, (float)1, (float)0, (float)1); // yellow
    t3.set(anc + rf1, anc + rf2, anc + rf3, anc + rf4, (float)1, (float)0, (float)1); // yellow
    t4.set(anc + la1, anc + la2, anc + la4, anc + la3, (float)1, (float)0, (float)0); // red
    t5.set(anc + ra1, anc + ra2, anc + ra4, anc + ra3, (float)1, (float)0, (float)0); // red
    ss[0] = &t1;
    ss[1] = &t2;
    ss[2] = &t3;
    ss[3] = &t4;
    ss[4] = &t5;
    zoom(1.25 / stallnum);
}

UFO::~UFO()//destructor, free the allocated memory
{
    delete[] ss;
}

void UFO::draw()//draw the UFO
{
    rotate(0.05, getAnchor(), 1);
    for (int i = 0; i < n; i++)
    {
        ss[i]->draw();
    }
}
void Rocket::set(int stallnum, Vec anchor, Vec turn)//set the parameters of the rocket
{
    double stalllength = 4.0 / stallnum;
    double stallwidth = 1.5 / stallnum;
    setAnchor(anchor + Vec(-.8 / stallnum, -.8 / stallnum));
    turn0 = anchor;
    turn1 = turn0 + Vec(0, stalllength);
    turn2 = turn + Vec(stallwidth, stalllength) * .5;
    if (turn2.getY() > 0)
    {
        turn2 = turn + Vec(stallwidth, stalllength) * (-.5);
    }
    turn3 = Vec(1.5 + turn0.getX(), 0);
    cnt = 0;
    n = 5;
    ss = new coloredfig *[n];
    now = 0;
    Vec s1(0, 0.5);
    Vec s2(0.05, 0.4);
    Vec s3(-0.05, 0.4);
    Vec s4(0.05, 0);
    Vec s5(-0.05, 0);
    Vec s6(-0.1, -0.05);
    Vec s7(0.1, -0.05);
    Vec s8(-0.05, 0.3);
    Vec s9(-0.15, 0);
    Vec s10(0.05, 0.3);
    Vec s11(0.15, 0);
    t1.set(anc + s1, anc + s2, anc + s3, (float)0.3, (float)0.6, (float)1);
    t2.set(anc + s4, anc + s2, anc + s3, anc + s5, (float)1, (float)0, (float)0.84);
    t3.set(anc + s4, anc + s5, anc + s6, anc + s7, (float)0, (float)0, (float)0);
    t4.set(anc + s8, anc + s9, anc + s5, (float)0.95, (float)0.4, (float)0.64);
    t5.set(anc + s4, anc + s10, anc + s11, (float)0.95, (float)0.4, (float)0.64);
    ss[0] = &t1;
    ss[1] = &t2;
    ss[2] = &t3;
    ss[3] = &t4;
    ss[4] = &t5;
    zoom(2.0 / stallnum);
}

Rocket::~Rocket()//destructor, free the allocated memory
{
    delete[] ss;
}
void Rocket::draw()//draw the rocket                                                                                                                        
{
    if ((cnt % 40) < 20)
    {
        zoom(1.01);
    }
    else
    {
        zoom(1/1.01);
    }
    for (int i = 0; i < n; i++)
    {
        ss[i]->draw();
    }
    cnt++;
}
