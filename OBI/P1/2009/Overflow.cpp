#include<bits/stdc++.h>
using namespace std;
double a,b,v,p;
int main(){
    char c;
    cin>>p;
    cin>>a>>c>>b;
    if(c=='+'){
        v=a+b;
        if(v<=p){
            cout<<"OK";
        }
        else{cout<<"OVERFLOW";}
    }
    if(c=='*'){
        v=a*b;
        if(v<=p) cout<<"OK";
        else cout<<"OVERFLOW";
    }
return 0;
}

