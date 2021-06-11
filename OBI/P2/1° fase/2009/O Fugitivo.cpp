#include<bits/stdc++.h>
using namespace std;
bool preso;
char t;
double n,m,norte,sul,leste,i,oeste,f,ver,hor,dist,d;
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t>>f;
        if(t=='N') norte=norte+f;
        else if(t=='S') sul=sul+f;
        else if(t=='O') oeste=oeste+f;
        else if(t=='L') leste=leste+f;
        ver=abs(sul-norte);
        hor=abs(leste-oeste);
        dist=(ver*ver)+(hor*hor);
        d=sqrt(dist);
        if(d>m) preso=1;
    }
    if(preso==1) cout<<1;
    else cout<<0;
}
