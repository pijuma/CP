#include<bits/stdc++.h>
using namespace std;

int a;

int main(){
    cin>>a;
    if(a%8==7) cout<<2;
    else if(a%8==6) cout<<1;
    else cout<<3;
}
