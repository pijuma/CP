#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int p,s,u,me,md,i,r;
int main()
{
    cin>>p>>s;

    vector< pair<int,int> >v;

    for(i=0;i<s;i++)
    {
        cin>>u>>r;

        v.push_back(make_pair(u,r));
    }

    sort(v.begin(),v.end());

    v.push_back(make_pair(maxn,maxn));

    me=v[0].first,md=v[0].second;

    vector< pair<int,int> > ans;

    for(i=1;i<(int)v.size();i++)
    {
        if(v[i].first>md)
        {
            ans.push_back(make_pair(me,md));

            me=v[i].first;

            md=v[i].second;
        }
        else if(v[i].second>md)  md=v[i].second;
    }
    for(i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
