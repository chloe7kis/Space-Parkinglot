#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <iostream>
#include <vector>
#include "carport.h"
using namespace std;

typedef struct pos_
{
    int floor;
    int order;
} position;

class floor
{
private:
    int order;
    int area;

public:
    int remain;
    vector<Carport> carports; // true if is empty
    floor(int o, int a);
    //~floor();
    int getarea();
    int enter(); // return -1 if there is no available carport, return the order(from 0 to area-1)if succeed
    void leave(int p);
    int find(int o);
};

class parkinglot
{
private:
    int num; // number of floors
public:
    vector<floor> floors;
    parkinglot(int n);
    int getnum();
    position enter();
    void leave(position p);
};

#endif
