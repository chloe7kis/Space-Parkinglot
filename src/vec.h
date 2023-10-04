#ifndef VEC_H
#define VEC_H
#include <cmath>
#include <iostream>
class Vec
{
private:
    double x, y;

public:
    Vec(double _x = 0, double _y = 0);
    double getX();
    double getY();
    // Example Overloads + operator
    // returns the sum of 2 Vec
    Vec operator+(Vec v);
    // Overload - on 2 Vectors
    // return thier difference Vector
    Vec operator-(Vec v);
    // Overload * operator on a float k
    // return current Vector scaled by k
    Vec operator*(double k);
    // Overload * on 2 Vectors
    // return thier inner product (scaler product)
    double operator*(Vec v);
    // Overload << on an angle
    // return current vector rotated counter clockwise
    // by this angle
    Vec operator<<(double a);
    // Overload >> on an angle
    // return current vector rotated clockwise
    // by this angle
    Vec operator>>(double a);
    void print();
};
typedef struct Zoom_argu_
{
    Vec length;
    Vec centre;
} Zoom_argu;
#endif
Vec zoom(Vec a, Zoom_argu z);
