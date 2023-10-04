#include "singleton.h"

using namespace std;

Singleton* Singleton::getInstance(){
    static Singleton *s=NULL;
    if (s==NULL)
        s=new Singleton();
    return s;
}

void Singleton::deleteInstance(){
    Singleton *s=Singleton::getInstance();
    if (s!=NULL)
        delete s;
    s=NULL;
}

Vehicles * Singleton::getcurrent(){
    return current;
}

void Singleton::setcurrent(Vehicles * tmp){
    current=tmp;
}
