#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <cstdlib>
#include "figures.h"

using namespace std;
class Vehicles;

class Singleton{
private:
    Singleton()=default;
    ~Singleton()=default;
    Vehicles * current;
public:
    static Singleton *getInstance();
    static void deleteInstance();
    Vehicles * getcurrent();
    void setcurrent(Vehicles* tmp);
};

#endif
