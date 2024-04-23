#include<iostream>
using namespace std;

class base{
    public:
    int  add(int a,int b){
        return a+b;
    }
    float add(float a ,float b){
        return a+b;
    }
    double add(double a,double b,double c){
        return a+b+c;
    }
};

int main(){
    base b;
    cout<<b.add(2,5)<<endl;
    cout<<b.add(2.5f,3.5f)<<endl;
    cout<<b.add(5.333,8.555,9.555);
    return 0;
    
}