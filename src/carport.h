#ifndef CARPORT_H
#define CARPORT_H

#include <iostream>
using namespace std;

class Carport
{
private:
    int order;

public:
    Carport(bool a, int b);
    bool empty;
    int getorder();
};

#endif
