#include<bits/stdc++.h>
using namespace std ;

const int maxn = 110 ;

int n, vis[maxn] ;
map<int,int> f ;
vector<int> g [maxn] ;

void dfs(int v, int p){

    vis[v] = 1 ;

    for(auto a : g[v]){
        if(a == p || vis[a]) continue ;
        dfs(a, v) ;
    }

}

int main(){

    ifstream cin("factory.in");
    ofstream cout("factory.out");

    cin >> n ;

    for(int i = 1 ; i < n ; i++){
        int a, b ; cin >> a >> b ;
        g[b].push_back(a) ;
    }

    int ans = -1 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++) vis[j] = 0 ;
       dfs(i, i) ;
       bool ok = 1 ;
       for(int j = 1 ; j <= n ; j++) if(!vis[j]) ok = 0 ;
       if(ok) ans = i ;
    }

    cout << ans << "\n" ;

}
