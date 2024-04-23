#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    do{
        v.push_back(n);
    }while(next_permutation(v.begin(),v.end()));

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}