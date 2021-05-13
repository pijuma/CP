#include<bits/stdc++.h>
using namespace std;

const int maxn=1e3+10;

int s[maxn][maxn],qtd,i,j,x,y,n,q,x2,y2;
char f[maxn][maxn];

int main(){
  
    cin>>n>>q;
  
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>f[i][j];
            if(f[i][j]=='*') s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1]+1;
            else s[i][j]=s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }
  
    for(i=1;i<=q;i++){
        cin>>y>>x>>y2>>x2;
         cout<<s[y2][x2]-s[y2][x-1]-s[y-1][x2]+s[y-1][x-1]<<endl;
    }
  
}
