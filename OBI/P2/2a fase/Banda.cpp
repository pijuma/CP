#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int l,r,f,i,j,k,n,m,maxl,soma[5],v[maxn][maxn];
int main(){
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>l>>r>>f;
        v[l][r]=f;
        v[r][l]=f;
    }
    soma[1]=1;
    soma[2]=2;
    soma[3]=3;
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(k=j+1;k<=n;k++){
                if((v[i][j]+v[i][k]+v[j][k])>maxl){
                    maxl=v[i][j]+v[i][k]+v[j][k];
                    soma[1]=i;
                    soma[2]=j;
                    soma[3]=k;
                }
            }
        }
    }
    sort(soma+1,soma+4);
    cout<<soma[1]<<" "<<soma[2]<<" "<<soma[3];
}
