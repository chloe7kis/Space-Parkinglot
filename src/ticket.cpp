#include "ticket.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include "carport.h"
#include "regularparkinglot.h"
using namespace std;

void vehicle::aprint()
{
    double p = wtime * price;
    char *dt = ctime(&out);
    cout << "_______________________" << endl
         << "See you next time!" << endl;
    cout << "you have parked " << wtime << " seconds" << endl;
    cout <<"at floor " << pos.floor+1 << " number " << pos.order+1 << endl;
    cout << price << " per second for a/an " << name << endl;
    cout << p << " please" << endl;
    cout << dt << "out" << endl;
    state = 1;
}
void vehicle::bprint()
{
    cout << "_________________________" << endl;
    cout << "Welcome!" << endl
         << name << endl
         << price << " per second, please" << endl;
    char *dt = ctime(&enter);
    cout << dt << "enter" << endl;
    cout << "Your position is floor " << pos.floor + 1 << " number " << pos.order + 1 << endl;
}
int vehicle::getstate() { return state; }
int vehicle::getstart() { return start; }
int vehicle::getend() { return (start + wtime); }
void vehicle::waitmore()
{
    start++;
    enter++;
    out++;
}

van::van(time_t now, time_t st)
{
    wtime = rand() % 30;
    start = st;
    enter = now + start;
    out = enter + wtime;
    price = 50;
    name = "van";
}

car::car(time_t now, time_t st)
{
    wtime = rand() % 30;
    start = st;
    enter = now + start;
    out = enter + wtime;
    price = 40;
    name = "car";
}

motorbike::motorbike(time_t now, time_t st)
{
    wtime = rand() % 30;
    start = st;
    enter = now + start;
    out = enter + wtime;
    price = 30;
    name = "motorbike";
}

bicycle::bicycle(time_t now, time_t st)
{
    wtime = rand() % 30;
    start = st;
    enter = now + start;
    out = enter + wtime;
    price = 20;
    name = "bicycle";
}
