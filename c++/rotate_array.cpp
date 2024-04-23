#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,3,4,5};
    int k;
    cout<<"enter the k value";
    cin>>k;
    cout<<"Original Vector: ";
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    
    cout<<"rotated Vector: ";
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}