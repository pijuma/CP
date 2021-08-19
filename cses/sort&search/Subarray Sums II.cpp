#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n;
long long f,x,b[maxn],resp;
int main(){
    cin>>n>>x;
    map<long long,int>s;
    s[0]++;
    for(int i=0;i<n;i++){
        cin>>b[i];
        f+=b[i];
        resp+=s[f-x];
        s[f]++;
    }
    cout<<resp;
}
