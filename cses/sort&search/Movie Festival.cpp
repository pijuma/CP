#include<bits/stdc++.h>
using namespace std;

int n,a,i,b,v,md;
vector< pair<int,int> > m;

int main(){

    cin>>n;
    
    for(i=0;i<n;i++){
        cin>>a>>b;
        m.push_back(make_pair(b,a));
    }
    
    sort(m.begin(),m.end());
    md=m[0].first;
    v=1;
    
    for(i=1;i<m.size();i++){
        if(md<=m[i].second){
            v++;
            md=m[i].first;
        }
        else continue;
    }
    
    cout<<v;
    
}
