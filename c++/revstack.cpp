#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cout<<"enter the string";
    getline(cin,a);
    cout<<a<<endl;
    string b;
    b=a;
    reverse(b.begin(),b.end());
    stack<char>s;
    string ans="";
    for(int i=0;i<b.size();i++){
        if(isalpha(b[i])){
            s.push(b[i]);
        }
        else if(b[i]==' '){
            if(!s.empty()){
                while(!s.empty()){
                    ans+=s.top();
                    s.pop();
                }
                ans+=" ";
            }
        }

    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    cout<<"reversed string:"<<ans<<endl;
    return 0;
}