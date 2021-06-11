#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100,inf=1e9+10;
int n,k,s[maxn],i,menor,t;
int main(){
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>s[i];
    sort(s,s+n+1);
    menor=inf;
    for(i=0;i<=k;i++){
        t=s[n-k+i]-s[i+1];
        if(t<=menor) menor=t;
    }
    cout<<menor;
}
