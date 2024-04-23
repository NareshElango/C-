#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int var1=0,var2=1;
    for(int i=0;i<n;i++){
        for(int s=0;s<n-i-1;s++)
        cout<<" ";
        for(int j=0;j<(2*i)+1;j++){
            cout<<abs(j-var1);
        }
        var1++;
        var2+=2;
        cout<<"\n";
    }
}