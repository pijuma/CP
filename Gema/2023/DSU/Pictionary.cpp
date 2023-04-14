#include<bits/stdc++.h>
using namespace std ;
 
const int maxl = 22 ; 
const int maxn = 2e5 + 5 ; 
 
int n, q, m ; 
int pai[maxn], sz[maxn], tab[maxl][maxn], nivel[maxn], mx_t[maxl][maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 
 
struct DSU{
 
    int find(int a){return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }
 
    void join(int a, int b){
        a = find(a), b = find(b) ; 
        if(a == b) return ; 
        if(sz[a] > sz[b]) swap(a, b) ; 
        sz[b] += sz[a] ; pai[a] = b ; 
    }
 
} dsu ; 
 
void dfs(int v, int p){
 
    tab[0][v] = p ; 
 
    for(auto a : grafo[v]){
        if(a.first == p || nivel[a.first] != -1) continue ;
        mx_t[0][a.first] = a.second ; 
        nivel[a.first] = nivel[v] + 1 ; 
        dfs(a.first, v) ; 
    }
 
}
 
int lca(int a, int b){
 
    if(nivel[a] > nivel[b]) swap(a, b) ; 
 
    int ans = 0 ; 
 
    for(int i = maxl - 1 ; i >= 0 ; i--){
        if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]){
            ans = max(ans, mx_t[i][b]) ; 
            b = tab[i][b] ; 
        }
    }
 
    if(a == b) return ans ; 
 
    for(int i = maxl - 1 ; i >= 0 ; i--){
        if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]){
            ans = max({ans, mx_t[i][a], mx_t[i][b]}) ; 
            a = tab[i][a], b = tab[i][b] ;
        }
    }
 
    return max({ans, mx_t[0][a], mx_t[0][b]}) ;
 
}
 
int main(){
 
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
    cin >> n >> m >> q ; 
 
    for(int i = 1 ; i <= n ; i++) nivel[i] = -1, pai[i] = i, sz[i] = 1 ; 
 
    for(int i = m ; i > 0 ; i--){ // pega a 1a vez q fica conectado
        for(int j = i + i ; j <= n ; j += i){
            if(dsu.find(i) == dsu.find(j)) continue ; 
            dsu.join(i, j) ; 
            grafo[i].push_back({j, m-i+1}) ; grafo[j].push_back({i, m-i+1}) ;
        }
    }
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++) tab[i][j] = -1 ; 
    }
 
    nivel[1] = 0 ; 
    dfs(1, 0) ; 
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(tab[i-1][j] == -1) continue ; 
            tab[i][j] = tab[i-1][tab[i-1][j]] ; 
            mx_t[i][j] = max(mx_t[i-1][j], mx_t[i-1][tab[i-1][j]]) ;
        }
    }
 
    for(int i = 1 ; i <= q ; i++){
        int a, b ; cin >> a >> b ; 
        cout << lca(a, b) << "\n" ;
    }
 
}
