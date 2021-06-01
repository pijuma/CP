#include<bits/stdc++.h>
using namespace std;
float c,l,t1,t2,a,b;
int main(){
    cin>>l;
    cin>>c;
    t2=2*(c-1)+2*(l-1);
    a=l*c;
    a=a-0.5;
    b=(t2*0.25);
    a=a-b;
    t1=a/0.5;
    cout<<t1<<endl<<t2;
return 0;
}
