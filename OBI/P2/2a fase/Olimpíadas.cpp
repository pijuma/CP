#include<bits/stdc++.h>
using namespace std;
struct pais{
    int prata,ouro,bronze,id;
};
int func(pais a,pais b){
     if(a.ouro!= b.ouro) return a.ouro>b.ouro;
     if(a.prata!=b.prata) return a.prata>b.prata;
     if(a.bronze!=b.bronze) return a.bronze>b.bronze;
     return a.id<b.id;
}
int main(){
    int n,m,o,p,b,i;
    pais v[105];
    cin>>n>>m;
    for(i=1;i<=n;i++){
        v[i].ouro=0;
        v[i].prata=0;
        v[i].bronze=0;
        v[i].id=i;
    }
    for(i=1;i<=m;i++){
        cin>>o>>p>>b;
        v[o].ouro++;
        v[p].prata++;
        v[b].bronze++;
    }
    sort(v+1,v+n+1,func);
    for(i=1;i<=n;i++){
        cout<<v[i].id<<" ";
    }
return 0;
}
