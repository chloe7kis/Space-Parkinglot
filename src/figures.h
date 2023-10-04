#ifndef FIGURES_H
#define FIGURES_H
#include "figure.h"
#include <vector>
#include "parkinglot.h"
using namespace std;
#include <iostream>
class Parkinglot;
class Vehicles : public Figure
{
protected:
    int n;
    int state;
    int sec;
    coloredfig **ss = NULL;
    Vec turn1;
    Vec turn2;
    Vec turn3;
    Vec turn0;
    bool arrived;
public:
    void rotate(double angle, Vec cen, int dir);
    void move(Vec dir);
    void zoom(double k);
    virtual void draw() {}
    Vehicles();
    int getstate();
    int getsec();
    virtual void set(int stallnum, Vec anchor, Vec turn)
    {
        stallnum++;
        anc = turn;
        anc = anchor;
    }
    virtual ~Vehicles() {}
    void enter();
    bool getarrived();
};

class Car : public Vehicles
{
public:
    Car(){};
    void set(int stallnum, Vec anchor, Vec turn);
    ~Car();
    void draw();

private:
    poly t1;
    poly t2;
    Rec t3;
    Rec t4;
    Rec t5;
    Rec t6;
    void flag();
    double now;
};

class UFO : public Vehicles
{
public:
    UFO() {}
    void set(int stallnum, Vec anchor, Vec turn);
    ~UFO();
    void draw();

private:
    halfpoly t1;
    Rec t2, t3; // foot
    Rec t4, t5; // antenna
    double now;
};

class Rocket : public Vehicles
{
public:
    Rocket() {}
    void set(int stallnum, Vec anchor, Vec turn);
    ~Rocket();
    void draw();

private:
    Triangle t1; // head
    Rec t2;      // body
    Rec t3;      // tail
    Triangle t4; // Left wing
    Triangle t5; // Right wing
    double now;
    int cnt;
};

#endif
