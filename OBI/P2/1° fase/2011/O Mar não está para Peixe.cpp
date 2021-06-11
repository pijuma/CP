#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2+10;
int xa,xb,ya,yb,n,d,i,j,matriz[maxn][maxn];
int main(){
    cin>>n;
    while(n--){
        cin>>xa>>xb>>ya>>yb;
        for(i=xa;i<xb;++i){
            for(j=ya;j<yb;++j){
                matriz[i][j]=1;
            }
        }
    }
    for(i=0;i<maxn-10;i++){
        for(j=0;j<maxn-10;j++){
            if(matriz[i][j]==1) d++;
        }
    }
    cout<<d;
}
