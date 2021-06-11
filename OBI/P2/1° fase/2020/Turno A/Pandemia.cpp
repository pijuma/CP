#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
bool infec;
int i,j,con[maxn],pes[maxn],n,m,c,r,p,qtd;
int main(){
    cin>>n>>m;
    cin>>c>>r;
    con[c]=1;
    for(i=1;i<=m;i++){
        cin>>p;
        for(j=1;j<=p;j++){
            cin>>pes[j];
            if(con[pes[j]]==1 && i>=r) infec=true;
        }
        if(infec==true){
            for(j=1;j<=p;j++){
                con[pes[j]]=1;
            }
            infec=false;
        }
    }
    for(i=1;i<=n;i++) if(con[i]==1) qtd++;
    cout<<qtd;
}
