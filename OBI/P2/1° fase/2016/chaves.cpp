#include<bits/stdc++.h>
using namespace std;
int t,i,j;
string f;
bool ok;
int main()
{
    stack<char>cha;
    ok=true;
    cin>>t;
    for(i=0;i<=t;i++)
    {
        getline(cin,f);
        for(j=0;j<=f.size();j++)
        {
            if(f[j]=='{') cha.push('{');
            else if(f[j]=='}')
            {
                if(cha.empty()) ok=false;
                else cha.pop();
            }
        }
    }
    if(!cha.empty()) ok=false;
    if(ok) cout<<"S";
    else cout<<"N";
}
