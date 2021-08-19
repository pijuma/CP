#include<bits/stdc++.h>
using namespace std;
int qtd,i,p,a,n,b,j;
int main()
{
    vector<int>pes,apart;
    cin>>p>>a>>n;
    for(i=0;i<p;i++)
    {
        cin>>b;
        pes.push_back(b);
    }
    for(i=0;i<a;i++)
    {
        cin>>b;
        apart.push_back(b);
    }
    sort(pes.begin(),pes.end());
    sort(apart.begin(),apart.end());
    for(i=0,j=0;i<p;i++) // two pointers
    {
        while(j<a && apart[j]<pes[i]-n)// enquanto apart[j]<pes[i]-n == j++;
        {
            j++;
        }
        if(j<a && apart[j]<=pes[i]+n) //ele obrigatoriamente vai estar entre pes[i]-n e pes[i]+n
        {
            qtd++;
            j++;
        }
    }
    cout<<qtd;
}
