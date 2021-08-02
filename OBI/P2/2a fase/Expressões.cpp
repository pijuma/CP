#include<bits/stdc++.h>
using namespace std;
string f;
char p;
bool ok;
int t,i,j;
int main()
{
    stack<char>cara;

    cin>>t;

    for(i=0;i<t;i++)
    {
       cin>>f;
       ok=true;
       while(!cara.empty()) cara.pop();
       for(j=0;j<(int)f.size();j++)
       {
           if(f[j]=='(')      cara.push('(');
           else if(f[j]=='[') cara.push('[');
           else if(f[j]=='{') cara.push('{');
           else if(f[j]==')')
           {
               if(cara.empty()) ok=false;
               else if(cara.top()!='(') ok=false;
               else cara.pop();
           }
           else if(f[j]==']')
           {
               if(cara.empty()) ok=false;
               else if(cara.top()!='[') ok=false;
               else cara.pop();
           }
           else if(f[j]=='}')
           {
               if(cara.empty()) ok=false;
               else if(cara.top()!='{') ok=false;
               else cara.pop();
           }
       }
       if(!cara.empty()) ok=false;
       if(ok) cout<<"S"<<endl;
       else cout<<"N"<<endl;
    }
}
