#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string alpa="abcdefghijklmnopqrstuvwxyz";
    string cipher="";
    string plain;
    cout<<"enter the plain text ";
    cin>>plain;
    for(int i=0;i<plain.length();i++){
        char c=tolower(plain[i]);
        int j=alpa.find(c);
        if(j!=string::npos){
            char ct=isupper(plain[i])?toupper(alpa[(j+3)%26]):alpa[(j+3)%26];
            cipher+=ct;
        }
        else{
            cipher+=plain[i];
        }
    }
    cout<<"the cipher text is "<<cipher<<endl;
    return 0;
}