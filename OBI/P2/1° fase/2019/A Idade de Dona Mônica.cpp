#include<bits/stdc++.h>
using namespace std;
int maax,t,i,j,k;
int main(){
    cin>>t>>i>>j;
    k=t-i-j;
    maax=max(k,max(i,j));
    cout<<maax;
}
