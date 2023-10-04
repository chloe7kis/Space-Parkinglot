#ifndef TICKET_H
#define TICKET_H
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include "carport.h"
#include "regularparkinglot.h"
using namespace std;
class vehicle
{
public:
    void aprint();//print the information when the car exits from the parkinglot
    void bprint();//print the information when the car enters the parkinglot
    void waitmore(); // the parkinglot is full so wait more before entering
    int getstate();
    int getstart();
    int getend();
    position pos;

protected:
    time_t enter;
    time_t out;
    time_t start;
    double price;
    double wtime; // wait time
    string name;
    int state = 0;
};
class van : public vehicle
{
public:
    van(time_t now, time_t st);
};

class car : public vehicle
{
public:
    car(time_t now, time_t st);
};
class motorbike : public vehicle
{
public:
    motorbike(time_t now, time_t st);
};

class bicycle : public vehicle
{
public:
    bicycle(time_t now, time_t st);
};
#endif
