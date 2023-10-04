
#include "ticket.h"
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <vector>
#include "carport.h"
#include "regularparkinglot.h"
using namespace std;

int sum(vector <int> a)
{
    int s=0;int n=a.size();
    for(int i=0;i<n;i++)s+=a[i];
    return s;
}

int main( )
{
    cout<<"Parking Management Software"<<std::endl;
    parkinglot park(3);//there are 3 floors
    srand((unsigned int)time(NULL));
    int n=rand()%10+4;//4-13 vehicles
    vector<vehicle> cars;
    vector<int> flag;
    for (int i=0;i<n;i++){flag.push_back(0);}
    time_t now=time(0);
    
    for (int i=0;i<n;i++)
    {
        int type=rand()%4;time_t st=rand()%20;
        switch (type)
        {
            case 0:{van temp(now,st);cars.push_back(temp);break;}
            case 1:{car temp(now,st);cars.push_back(temp);break;}
            case 2:{motorbike temp(now,st);cars.push_back(temp);break;}
            case 3:{bicycle temp(now,st);cars.push_back(temp);break;}
        }
    } 
    int t=0;
    while(sum(flag)<n)
    {sleep(1);
        for(int i=0;i<n;i++)
        {
            if (t==cars[i].getstart()){cars[i].pos=park.enter();cars[i].bprint();}
            if (t==cars[i].getend()){park.leave(cars[i].pos);cars[i].aprint();}
            flag[i]=cars[i].getstate();
        }
        t++;
    }
    return 0;
}
