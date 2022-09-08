#include<bits/stdc++.h>
using namespace std ;

const int maxn = 110 ;

int t, n, vis[maxn] ;
vector<int> cam ;
vector<int> grafo[maxn] ;

void dfs(int v, int p, int lvl){
    vis[v] = 1 ;
    if(lvl%2 == 0) cam.push_back(v) ;
    for(auto a : grafo[v]){
        if(vis[a] || a == p) continue ;
        dfs(a, v, lvl+1) ;
    }
    if(lvl%2) cam.push_back(v) ;
}

int main(){

    cin >> t ;

    while(t--){
        cin >> n ;
        for(int i = 1 ; i < n ; i++){
            int a, b ; cin >> a >> b ;
            grafo[a].push_back(b) ; grafo[b].push_back(a) ;
        }
        dfs(1, 1, 0) ;
        for(auto a : cam) cout << a << " " ;
        cout <<"\n" ;
        cam.clear() ;
        for(int i = 1 ; i <= n ; i++) grafo[i].clear(), vis[i] = 0 ;
    }

}
