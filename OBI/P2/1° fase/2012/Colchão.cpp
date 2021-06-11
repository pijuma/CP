#include<bits/stdc++.h>
using namespace std;
int l[5],v[5];
int main(){
    cin>>v[1]>>v[2]>>v[3];
    cin>>l[1]>>l[2];
    sort(v,v+4);
    sort(l,l+3);
    if(v[2]<=l[2] && v[1]<=l[1]) cout<<"S";
    else cout<<"N";
}
