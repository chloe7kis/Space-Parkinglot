#include "regularparkinglot.h"
#include "carport.h"
using namespace std;

floor::floor(int o, int a)
{
    order = o;
    area = a; // set different areas
    remain = area;
    for (int i = 0; i < area; i++)
    {
        Carport tmp = Carport(true, i);
        (carports).push_back(tmp);
    }
}

// floor::~floor(){}

int floor::getarea()
{
    return area;
}

int floor::find(int o)
{
    int k = 0;
    for (int i = 0; i < getarea(); i++)
    {
        if (carports[i].empty)
        {
            if (k == o)
            {
                return i;
            }
            else
            {
                k++;
            }
        }
    }
    return -1;
}

int floor::enter()
{
    if (!remain)
        return -1;
    int n = remain;
    int o;
    o = rand() % n; // 0-(n-1)
    int place = find(o);
    remain--;
    carports[place].empty = false;
    return place;
}

void floor::leave(int p)
{
    carports[p].empty = true;
    remain++;
}

parkinglot::parkinglot(int n)
{
    num = n;
    for (int i = 0; i < n; i++)
    {
        floor tmp = floor(i,4*(i+1));//make sure each floor is of different size
        floors.push_back(tmp);
    }
}

position parkinglot::enter()
{
    int isempty;
    int f = -1;
    for (int i = 0; i < getnum(); i++)
    {
        isempty = floors[i].remain;
        if (isempty > 0)
        {
            f = i;
            break;
        }
    }
    if (f == -1)
    { // if the parking lot is full of cars
        position full;
        full.floor = -1;
        full.order = -1;
        return full;
    }
    int o = floors[f].enter();
    position r;
    r.floor = f;
    r.order = o;
    return r;
}

void parkinglot::leave(position p)
{
    floors[p.floor].leave(p.order);
}

int parkinglot::getnum()
{
    return num;
}
