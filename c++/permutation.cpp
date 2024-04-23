#include<iostream>
using namespace std;
void print(int a[],int n){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";    //for array
    }
    cout<<"\n";
}
void permute(string a,int l,int r){
    if(l==r){
    //    print(a,r+1);   //for array
    cout<<a<<" ";
    }
    else{
        for(int i=l;i<=r;i++){
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
int main(){
    // int n;
    // cin>>n;
    // int a[n];       //for array
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }
    string a;
    cin>>a;
    int n=a.size();

    permute(a,0,n-1);
    return 0;
}