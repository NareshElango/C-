#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> permute(vector<int>&v,int n){
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(v.begin(),v.end());
        cout<<"it is the greater one";
        return v;
    }

    for(int i=n-1;i>ind;i--){
        if(v[i]>v[ind]){
            swap(v[i],v[ind]);
            break;
        }
    }
    reverse(v.begin()+ind+1,v.end());
    return v;
}
int main(){
    int n;
    cout<<"n";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"To find next greater element"<<endl;
    permute(v,n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
    
}