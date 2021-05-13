#include<bits/stdc++.h>
using namespace std;

const int maxn= 2e5+10 ;

long long n,q,i,l,r,v[maxn],sum[maxn] ;

int main(){
  
    cin>>n>>q;
  
    for(i=1;i<=n;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
  
    for(i=1;i<=q;i++){
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
  
}
