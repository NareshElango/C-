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

class derived1:public  derived{
    protected:
    int c,p;
    public:
    void set_c(){
        set_b();
        cout<<"enter the val";
        cin>>c;
    }
    void showi(){
        show();
        cout<<c<<endl;
    }

    void cal(){
        p=a*c*b;
        cout<<p<<endl;
    }
};

int main(){
   derived1 d;
   d.set_c();
   d.showi();
   d.cal();
}