#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
long long f,x,b[maxn],resp;
int main(){
    cin>>n;
    map<long long,int>s;
    s[0]++;
    for(int i=0;i<n;i++){
        cin>>b[i];
        f+=b[i];
        f%=n;
        if(f<0) f+=n;
        resp+=s[f];
        s[f]++;
    }
    cout<<resp;
}
