#include<bits/stdc++.h>
using namespace std;
int a,b,c,v;
int main(){
    cin>>c;
    cin>>a>>b;
    v=abs(a-b);
    if(c<=v) cout<<"EH SUFICIENTE";
    else cout<<"NAO EH SUFICIENTE";
return 0;
}
