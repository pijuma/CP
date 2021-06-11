#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+10;
bool mito;
int n,i,x,j,y,grafo[maxn][maxn],linha[maxn],coluna[maxn];
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>x>>y;
        grafo[x][y]++;
        if(grafo[x][y]>1) mito=true;
    }
    if(mito==true) cout<<1;
    else cout<<0;
return 0;
}
