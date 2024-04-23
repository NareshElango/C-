#include<iostream>
using namespace std;

class base{
    
    int r,i;
    public:
    base(int r=0,int i=0){
        this->r=r;
        this->i=i;
    }
    base operator+(base &b){
        base res;
        res.r=r+b.r;
        res.i=i+b.i;
        return res;
    }

    void print(){
        cout<<r<<" +i"<<i;
    }
};

int main(){
    base g(3,4);
    base c(5,4);
    base f=g+c;
    f.print();
}