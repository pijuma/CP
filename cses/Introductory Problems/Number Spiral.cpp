#include<bits/stdc++.h>
using namespace std;
long long i,n,x,y;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>y>>x;
        if(x>y)
        {
            if((x&1)==1) cout<<x*x-y+1<<endl;
            else cout<<(x-1)*(x-1)+y<<endl;
        }
        else
        {
            if((y&1)==0) cout<<y*y-x+1<<endl;
            else cout<<(y-1)*(y-1)+x<<endl;
        }
    }
}
