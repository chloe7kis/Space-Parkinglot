#ifndef FIGURE_H
#define FIGURE_H
#include "vec.h"
#ifdef linux
#include <GL/glut.h>
#include <ctime>
#include <cstdlib>
#else
#include <GL/freeglut.h>
#endif
#include <ctime>
#include <cstdlib>

class Figure
{
protected:
    Vec anc;

public:
    Figure() : anc(0, 0) {}
    Vec getAnchor();//get the anchor of the figure
    virtual void setAnchor(Vec anchor);//set the anchor of the figure
    virtual void draw(){}//draw the figure
    virtual ~Figure() {}
};

class coloredfig : public Figure
{
public:
    virtual ~coloredfig() = 0;
    virtual void zoom(double k,Vec cen)=0;//zoom the figure wrp to cen
    virtual void rotate(double angle,Vec cen,int dir)=0;//rotate the shape wrp to cen, dir=0 stands for anticlockwise, 1 for clockwise
    virtual void draw()=0;//draw the figure
    virtual void move(Vec dir){dir=Vec(0,0);}//move along dir vector
protected:
    float r;
    float g;
    float b;
    
    void paint();
};

class Triangle : public coloredfig
{
public:
    Triangle();
    void set(Vec a1, Vec a2, Vec a3, float red, float gre ,float blu);
    Vec geta();
    Vec getb();
    Vec getc();
    void move(Vec dir);
    void rotate(double angle, Vec x,int dir);
    void draw(); // void getcen();
    void zoom(double k,Vec cen);

private:
    Vec p1;
    Vec p2;
    Vec p3;
};

class Rec : public coloredfig
{
public:
    Rec();
    void move(Vec dir);
    void rotate(double angle, Vec x,int dir);
    void draw();
    Vec geta();
    Vec getb();
    Vec getc();
    Vec getd();
    void zoom(double k,Vec cen);
    void set(Vec a1, Vec a2, Vec a3, Vec a4, float red,float gre ,float blu );

private:
    Vec p1;
    Vec p2;
    Vec p3;
    Vec p4;
};
class poly : public coloredfig
{
public:
    poly();
    void set(Vec o, double ri, float red, float gre,float blu, int li);
    void move(Vec dir);
    void rotate(double angle, Vec x,int dir);
    void zoom(double k,Vec cen);
    virtual void draw();

protected:
    double ra;
    int l;
};

class halfpoly : public coloredfig
{
public:
    halfpoly();
    void set(Vec o, double ri, float red,float gre, float blu, int li, double a);
    void move(Vec dir);
    void rotate(double angle, Vec x,int dir);
    void zoom(double k,Vec cen);
    virtual void draw();
protected:
    double ra, ang;
    int l;
};

class tel : public poly
{
public:
    tel(){}
    void draw();//changing the number of the lines amd the color of the shape 
    void set(Vec o, double ri, float red, float gre,float blu );
private:
int sec;int line;
};

#endif
