#include<bits/stdc++.h>
using namespace std;
int t,i,j,ca,co,compradas[350],carimbadas[350],total[100],qtd;
int main(){
       cin>>t>>ca>>co;
       for(i=0;i<ca;i++) cin>>carimbadas[i];
       for(i=0;i<co;i++) cin>>compradas[i];
       qtd=0;
       for(i=0;i<100;i++){
          total[compradas[i]]=1;
       }
       for(i=0;i<ca;i++){
        if(total[carimbadas[i]]==0) qtd++;
       }
       cout<<qtd;
return 0;
}
