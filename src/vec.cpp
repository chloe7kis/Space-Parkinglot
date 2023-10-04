#include "vec.h"

using namespace std;
Vec::Vec(double _x, double _y)
{
    x = _x;
    y = _y;
}

double Vec::getX()
{
    return x;
}

double Vec::getY()
{
    return y;
}

Vec Vec::operator+(Vec v)
{
    return Vec(x + v.getX(), y + v.getY());
}

Vec Vec::operator-(Vec v)
{
    return Vec(x - v.getX(), y - v.getY());
}

Vec Vec::operator*(double k)
{
    return Vec(x * k, y * k);
}

double Vec::operator*(Vec v)
{
    return x * v.getX() + y * v.getY();
}

Vec Vec::operator<<(double a)
{
    return Vec(x * cos(a) - y * sin(a), y * cos(a) + x * sin(a));
}

Vec Vec::operator>>(double a)
{
    return Vec(x * cos(a) + y * sin(a), y * cos(a) - x * sin(a));
}
void Vec::print()
{
    cout << "x:" << getX() << " y:" << getY() << endl;
}
Vec zoom(Vec a, Zoom_argu z)
{
    double x = ((a.getX() - z.centre.getX()) * 2) / z.length.getX();
    double y = ((a.getY() - z.centre.getY()) * 2) / z.length.getY();
    Vec window(x, y);
    return window;
}
