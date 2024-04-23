#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

class alice{
    public:
    int p=11;
    int b=13;
    int key;
    int secrtekey(){
        cin>>key;
        long long int val=static_cast<long long int>(pow(b,key)) %p;
        return val;
    }
    int calc(int val){
        long long int res=static_cast<long long int>(pow(val,key)) %p;
        return res;
    }
}a;

class bob{
    public:
    int p=11;
    int g=13;
    int key;
    int secrte(){
        cin>>key;
        long long int val=static_cast<long long int>(pow(g,key)) %p;
       // cout<<val;
        return val;
    }

    int calc(int val){
        long long int res=static_cast<long long int>(pow(val,key)) %p;
        return res;
    }
}b;

int main(){
    int bobkey=b.secrte();
    int alicekey=a.secrtekey();
    if(a.calc(bobkey)==b.calc(alicekey))
    cout<<"true";
    else
    cout<<"false";
    return 0;
}