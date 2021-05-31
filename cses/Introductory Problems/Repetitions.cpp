#include<bits/stdc++.h>
using namespace std;
int qtd,i,resp;
string f;
int main()
{
    qtd=1;
    cin>>f;
    for(i=0;i<f.size();i++)
    {
        if(f[i]==f[i+1]) qtd++;
        else
        {
           resp=max(resp,qtd);
           qtd=1;
        }
 
    }
    cout<<resp;
}
