#include <iostream>
#include "figure.h"
#include "vec.h"
#define PI 3.1415926
using namespace std;

Vec Figure::getAnchor() { return anc; }

void Figure::setAnchor(Vec anchor) { anc = anchor; }

void coloredfig::paint()
{
    r = (float)rand() / (float)RAND_MAX;
    g = (float)rand() / (float)RAND_MAX;
    b = (float)rand() / (float)RAND_MAX;
}

coloredfig::~coloredfig() {}

Triangle::Triangle()
{
    Vec a0(0.3, 0);
    p1 = anc + (a0 << (2 * (PI / 3)));
    p2 = anc + (a0 << (4 * (PI / 3)));
    p3 = anc + a0;
    r = 1;
    g = 1;
    b = 0;
}

void Triangle::set(Vec a1, Vec a2, Vec a3, float red,  float gre,float blu)
{
    p1 = a1;
    p2 = a2;
    p3 = a3;
    anc=(a1+a2+a3)*(1.0/3.0);
    r = red;
    b = blu;
    g = gre;
}

Vec Triangle::geta() { return p1; }

Vec Triangle::getb() { return p2; }

Vec Triangle::getc() { return p3; }

void Triangle::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_STRIP);
    double p1x = p1.getX();
    double p1y = p1.getY(); // why!!!
    double p2x = p2.getX();
    double p2y = p2.getY();
    double p3x = p3.getX();
    double p3y = p3.getY();
    glVertex2d(p1x, p1y);
    glVertex2d(p2x, p2y);
    glVertex2d(p3x, p3y);
    glEnd();
}

void Triangle::move(Vec dir)
{
    p1 = p1 + dir;
    p2 = p2 + dir;
    p3 = p3 + dir;
    anc=anc+dir;
}

void Triangle::rotate(double angle, Vec x,int dir)
{
    // cout<<p1->getX()+p2->getX()+p3->getX()<<endl<<p.getX()<<endl;
    if(dir==0)
    {
        p1 = ((p1 - x) << angle) + x;
        p2 = ((p2 - x) << angle) + x;
        p3 = ((p3 - x) << angle) + x;
    }
    else
    {
        p1 = ((p1 - x) >> angle) + x;
        p2 = ((p2 - x) >> angle) + x;
        p3 = ((p3 - x) >> angle) + x;
    }
    anc=(p1+p2+p3)*(1.0/3.0);
}

void Triangle::zoom(double k,Vec cen)
{
    p1 = (p1 - cen) * k + cen;
    p2 = (p2 - cen) * k + cen;
    p3 = (p3 - cen) * k + cen;
    anc=(p1+p2+p3)*(1.0/3.0);
    //cout << "anc(" << anc.getX() << " " << anc.getY() << ") p1 (" << p1.getX() << " " << p1.getY() << ") p2 ("
    //     << p2.getX() << " " << p2.getY() << ") p3 (" << p3.getX() << " " << p3.getY() << ")" << endl;
}

Rec::Rec()
{
    Vec a0(.25, 0);
    Vec a1(0, .25);
    p1 = anc - a0 - a1;
    p2 = anc + a0 - a1;
    p3 = anc + a0 + a1;
    p4 = anc + a1 - a0;
    r = 0;
    g = 0;
    b = 1;
}

void Rec::set(Vec a1, Vec a2, Vec a3, Vec a4, float red,  float gre,float blu)
{
    p1 = a1;
    p2 = a2;
    p3 = a3;
    p4 = a4;
    anc=(p1+p2+p3+p4)*(1.0/4.0);
    r = red;
    b = blu;
    g = gre;
}

Vec Rec::geta() { return p1; }

Vec Rec::getb() { return p2; }

Vec Rec::getc() { return p3; }

Vec Rec::getd() { return p4; }

void Rec::zoom(double k,Vec cen)
{
    p1 = (p1 - cen) * k + cen;
    p2 = (p2 - cen) * k + cen;
    p3 = (p3 - cen) * k + cen;
    p4 = (p4 - cen) * k + cen;
    anc=(p1+p2+p3+p4)*(1.0/4.0);
}
void Rec::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    double p1x = p1.getX();
    double p1y = p1.getY(); // why!!!
    double p2x = p2.getX();
    double p2y = p2.getY();
    double p3x = p3.getX();
    double p3y = p3.getY();
    double p4x = p4.getX();
    double p4y = p4.getY();
    glVertex2d(p1x, p1y);
    glVertex2d(p2x, p2y);
    glVertex2d(p3x, p3y);
    glVertex2d(p4x, p4y);
    glEnd();
    // cout<<"p1x"<<p1x<<"p2x"<<p2x<<"p3x"<<p3x<<"p4x"<<p4x<<"p1y"<<p1y<<"p2y"<<p2y<<"p3y"<<p3y<<"p4y"<<p4y<<endl;
}

void Rec::move(Vec dir)
{
    p1 = p1 + dir;
    p2 = p2 + dir;
    p3 = p3 + dir;
    p4 = p4 + dir;
    anc=anc+dir;
}

void Rec::rotate(double angle, Vec x,int dir)
{
    if (dir==0)
    {
        p1 = ((p1 - x) << angle) + x;
        p2 = ((p2 - x) << angle) + x;
        p3 = ((p3 - x) << angle) + x;
        p4 = ((p4 - x) << angle) + x;
    }
    else
    {
        p1 = ((p1 - x) >> angle) + x;
        p2 = ((p2 - x) >> angle) + x;
        p3 = ((p3 - x) >> angle) + x;
        p4 = ((p4 - x) >> angle) + x;
    }
    anc=(p1+p2+p3+p4)*(1.0/4.0);
}

poly::poly()
{
    Vec o(-.5, -.5);
    ra = .1;
    anc = o;
    r = .5;
    g = .5;
    b = .5;
    l = 10;
}

void poly::set(Vec o, double ri, float red, float gre,float blu,  int li)
{
    anc = o;
    r = red;
    b = blu;
    g = gre;
    ra = ri;
    l = li;
}

void poly::move(Vec dir)
{
    anc = anc + dir;
}

void poly::rotate(double angle, Vec x,int dir)
{
    if(dir==0){anc = ((anc - x) << angle) + x;}
    else{anc = ((anc - x) >> angle) + x;}
}

void poly::zoom(double k,Vec cen)
{
    ra *= k;anc=(anc-cen)*k+cen;
}

void poly::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    int i = 0;
    while (i < l)
    {
        double p1x = anc.getX() + ra * cos(2 * i * PI / l);
        double p1y = anc.getY() + ra * sin(2 * i * PI / l);
        glVertex2d(p1x, p1y);
        i++;
    }
    glEnd();
}
void halfpoly::zoom(double k,Vec cen)
{
    ra *= k;anc=(anc-cen)*k+cen;
}
halfpoly::halfpoly()
{
    Vec o(0, 0);
    anc = o;
    ra = .5;
    r = .5;
    g = .5;
    b = .5;
    l = 20;
    ang = 0;
}

void halfpoly::set(Vec o, double ri, float red,  float gre,float blu, int li, double an)
{
    anc = o;
    r = red;
    b = blu;
    g = gre;
    ra = ri;
    l = li;
    ang = an;
}

void halfpoly::move(Vec dir)
{
    anc = anc + dir;
}



void halfpoly::rotate(double angle, Vec x,int dir)
{
    
    if(dir==0){ang+=angle;anc = ((anc - x) << angle) + x;}
    else{ang-=angle;anc = ((anc - x) >> angle) + x;}
}

void halfpoly::draw()
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    int i = 0;
    while (i <= l / 2)
    {
        double p1x = anc.getX() + ra * cos(2 * i * PI / l + ang);
        double p1y = anc.getY() + ra * sin(2 * i * PI / l + ang);
        glVertex2d(p1x, p1y);
        i++;
    }
    glEnd();
}

void tel::set(Vec o, double ri, float red, float gre,float blu )
{
    anc = o;
    r = red;
    b = blu;
    g = gre;
    ra = ri;
    sec=0;
}

void tel::draw()
{
    if (sec%100==0)
    {
    paint();line = rand() % 3 + 7;
    }
    // dip some paint.qvq
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    int i = 0;sec++;
    while (i < line)
    {
        double p1x = anc.getX() + ra * cos(2 * i * PI / line);
        double p1y = anc.getY() + ra * sin(2 * i * PI / line);
        glVertex2d(p1x, p1y);
        i++;
    }
    glEnd();
}
