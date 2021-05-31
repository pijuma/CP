#include<bits/stdc++.h>
using namespace std;
int n,i;
int main()
{
    cin>>n;
    if(n==1) cout<<1<<" ";
    else if(n<=3)cout<<"NO SOLUTION";
    else {
        for(i=2;i<=n;i=i+2) cout<<i<<" ";
        for(i=1;i<=n;i=i+2) cout<<i<<" ";
    //printa os pares primeiro dps os impares
    }
 
}
