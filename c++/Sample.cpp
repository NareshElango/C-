#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int fir=0;
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i])){
            fir=i;
            break;
        }
    }
    int ans=s[0];
    int op=fir;
    for(int i=1;i<fir;i++){
        if(s[op]=='+'){
            ans+=s[i];
        }
        if(s[op]=='-'){
            ans-=s[i];
        }
        if(s[op]=='*'){
            ans*=s[i];
        }
        if(s[op]=='/'){
            ans/=s[i];
        }
        op++;
    }
    cout<<ans;
}