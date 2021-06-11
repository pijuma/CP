#include<bits/stdc++.h>
using namespace std;
int i,c,n,modelo,versao;
int main()
{
    map<int,int>inst;
    map<int,int>atu;
    cin>>c>>n;
    for(i=0;i<c;i++)
    {
        cin>>modelo>>versao;
        inst[modelo]=versao;
    }
    for(i=0;i<n;i++)
    {
        cin>>modelo>>versao;
        atu[modelo]=max(atu[modelo],versao);
    }
    for(auto i=atu.begin();i!=atu.end();i++)
    {
       int modelo=i->first,versao=i->second;
       if(inst[modelo]<versao) cout<<modelo<<" "<<versao<<"\n";
    }
}
