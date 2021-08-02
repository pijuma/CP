#include<bits/stdc++.h>
using namespace std;
int main(){
    int v,i,x,y,z,f;
    int vet[2];
    f=0;
    cin>>v;
    for(i=0;i<3;i++){cin>>vet[i];}
    sort(vet,vet+3);
    for(i=0;i<3;i++){
        if((v-vet[i])>=0){f++;
        v=v-vet[i];
        }
    }
cout<<f;
return 0;
}
