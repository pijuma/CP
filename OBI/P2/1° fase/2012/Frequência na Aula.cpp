#include<bits/stdc++.h>
using namespace std;
int n,i,a;
int main()
{
    set<int>alu;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        alu.insert(a);
    }
    cout<<alu.size();
}
