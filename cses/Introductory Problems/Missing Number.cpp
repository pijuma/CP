#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,i,v[maxn],e[maxn];
int main()
{
    cin>>n;
    for(i=1;i<=n-1;i++)
    {
        cin>>v[i];
        e[v[i]]=1;
    }
    for(i=1;i<=n;i++){
        if(e[i]==0) cout<<i;
    }
}
