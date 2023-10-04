#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "vec.h"
#include "figure.h"
#include <vector>
#include "figures.h"
#include "singleton.h"
#ifndef PI
#define PI 3.1415926535
#endif
#define ZOOM 1
using namespace std;
class Singleton;
class Car;

class stall
{
public:
    stall();
    void stall_locate(Vec pt);
    void stall_length(double l);
    void stall_width(double w);
    Vec getlocate();
    int empty();
    void enter();
    void zoom(double k, Vec anc);
    void move(Vec dir);
    void draw();
    ~stall();

private:
    int state;
    Vec anc;
    double width;
    double length;
};
class gate
{
public:
    gate();
    void gate_(Vec anc, double w, double l);
    ~gate();
    void gate_draw();
    void zoom(double k, Vec anc);
    void move(Vec dir);

protected:
    Vec gate_locate;
    double width;
    double gate_length;
};
class pole
{
public:
    pole();
    void set(Vec anc, double l, double angle);
    ~pole();
    void pole_draw();
    void getangle();
    void zoom(double k, Vec anc);
    void move(Vec dir);
    void out();
    void iscar();

protected:
    Vec Pole_locate;
    double pole_length;
    double angle;
};
class extrance
{
public:
    extrance() {}
    void set(Vec loc, double gate_wide, double gate_length);
    void draw();
    ~extrance();
    void zoom(double k, Vec anc);
    void move(Vec dir);
    void out();
    void iscar();
    void pole_draw();

private:
    gate gate1;
    pole pole1;
};
class Vehicles;
class Parkinglot : public Figure
{
public:
    Parkinglot() {}
    Parkinglot(double a, double b);
    int getstallnum();
    Vec getturn();
    void draw();
    void pole_draw();
    ~Parkinglot();
    void fream();
    void iscar();
    void zoom(double k);
    Vec find();
    void move(Vec dir);
    void out();
    void getstallstate();
    int emptynum();

private:
    int stall_num;
    double gate_width;
    double road_width;
    double stall_length;
    double stall_width;
    double gate_length;
    stall *up;
    stall *down;
    extrance entrance1;
    vector<tel> teles;
    int *nteles;
};

class line
{
public:
    line();
    void line_(Vec a, Vec b);
    ~line();

private:
    Vec a;
    Vec b;
};

void glDraw();
void TimeStep(int n);

#endif