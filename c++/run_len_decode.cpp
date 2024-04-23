#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string ans;
    cin>>s;
    int num;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            if(isdigit(s[i+1])){
                num=(s[i]-'0')*10+(s[i+1]-'0');
            }else{
            num=s[i]-'0';
            }
            for(int j=0;j<num;j++){
                ans+=s[i-1];
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        if(isdigit(ans[i])){
            continue;
        }
        else{
            cout<<ans[i];
        }
    }
}