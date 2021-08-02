#include<bits/stdc++.h>
using namespace std;
bool i=false;
int n,x,x2,y,y2;
int main(){
    cin>>n;
    cin>>x>>y;
    cin>>x2>>y2;
    if((x <= n/2 && x2 > n/2 ) || (x2 <= n/2 && x > n/2 ) || (y <= n/2 && y2 > n/2 ) || (y2 <= n/2 && y > n/2 )) i=true;
    if(i==true) cout<<"S";
    else cout<<"N";
}
