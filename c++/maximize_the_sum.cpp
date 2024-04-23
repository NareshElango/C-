#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    sort(a,a+n,greater<int>());
    for(int i=0;i<k;i++){
        sum+=a[i];

    }
    cout<<sum<<endl;
    return 0;
}