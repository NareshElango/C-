#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class base{
    float area,rad;
    public:
    void setrad(float rad){
        this->rad=rad;
    }
    float getrad(){
        return rad;
    }

    void setarea(float area){
        this->area=area;
    }
    float getarea(){
        return area;
    }
    
    float  calc(){
        return 3.14*getrad()*getarea();
    }
};


int main(){
    base b;
    b.setrad(5);
    cout<<b.getrad()<<endl;
    b.setarea(20);
    cout<<b.getarea()<<endl;
    cout<<b.calc();
}