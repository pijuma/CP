#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long n,i,qtd,v[maxn];
int main()
{
    cin>>n;
    for(i=0;i<n;i++) cin>>v[i];
    for(i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            qtd=qtd+(v[i]-v[i+1]);
            v[i+1]=v[i];
        }
 
    }
    cout<<qtd;
}
