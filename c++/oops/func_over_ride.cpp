#include<iostream>
using namespace std;

class base{
    public:
    string color;
    base(){
        color="black";
    }
};

class derived: public base{
    public:
    derived(){
        color="blue";
    }
};

int main(){
    derived d;
    cout<<d.color;
    base b;
    cout<<b.color;
}
