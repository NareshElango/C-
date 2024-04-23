#include<iostream>
using namespace std;

class base{
    int x,y;
    public:
    void setval(int a,int b){
        x=a;
        y=b;
    }

    void display(){
        cout<<x<<" "<<y<<endl;
        cout<<x+y<<endl;
    }
};

int main(){
    base b;
    int d,f;
    cin>>d>>f;
    b.setval(d,f);
    b.display();
}