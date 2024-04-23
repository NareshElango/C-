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
    protected:
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

class derived1:public base{
    protected:
    int c,p;
    public:
    void set_c(){
        setval();
        cout<<"enter the val";
        cin>>c;
    }
    void showi(){
        display();
        cout<<c<<endl;
    }

    void cal(){
        p=a*c;
        cout<<p<<endl;
    }
};

int main(){
   derived1 d;
   derived s;
   d.set_c();
   d.showi();
   d.cal();
   s.set_b();
   s.display();
   s.calc();
}