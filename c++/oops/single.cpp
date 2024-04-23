#include<iostream>
using namespace  std;

class base{
    protected:
    int a;
    public:
    void setval(){
        cout<<"neter the val";
        cin>>a;
    }

    void display(){
        cout<<a<<endl;
    }
};

class derived:public base{
    int b,ans;
    public:
    void set_b(){
        setval();
        cout<<"enter the val";
        cin>>b;
    }
    void show(){
        display();
        cout<<b<<endl;
    }
    void calc(){
        ans=a*b;
        cout<<"ans:"<<ans<<endl;
    }
};


int main(){
    derived d;
    d.set_b();
    d.show();
    d.calc();
}