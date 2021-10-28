#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int i;
 
// queremos fazer 2^n
// porem pode ser muito grande ent�o fazemos modulo
int main()
{
    long long n,resp=1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        resp=(resp*2)%mod;
    }
    cout<<resp;
}
