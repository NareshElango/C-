#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string alpha="abcdefghijklmnopqrstuvwxyz";
    string cipher="";
    string plain;
    cout<<"enter the plain text ";
    cin>>plain;
    int key;
    cout<<"enter the key ";
    cin>>key;
    for(int i=0;i<plain.size();i++){
        char c=tolower(plain[i]);
        int j=alpha.find(c);
        if(j!=string::npos){
            char ct=isupper(plain[i])?toupper(alpha[(j+key)%26]):alpha[(j+key)%26];
            cipher+=ct;
        }
        else{
            cipher+=plain[i];
        }
    }

    cout<<"the cipher text is "<<cipher<<endl;
    return 0;
}