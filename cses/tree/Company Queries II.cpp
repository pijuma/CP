#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 5 ;
const int maxl = 20 ;
 
int n, a, b ;
int nivel[maxn], tab[maxl][maxn], q ;
vector<int>grafo[maxn] ;
 
void dfs(int v, int p){
    tab[0][v] = p ;
    for(int a : grafo[v]){
        if(nivel[a] != -1 || a == p) continue ;
        nivel[a] = nivel[v] + 1 ;
        dfs(a, v) ;
    }
}
 
int lca(int a, int b){
    if(nivel[a] > nivel[b]) swap(a, b) ;
    for(int i = maxl - 1 ; i >= 0 ; i--){
        if(nivel[tab[i][b]] >= nivel[a] && tab[i][b] != 0) b = tab[i][b] ;
    }
    if(a==b) return a ;
    for(int i = maxl - 1 ; i >= 0 ; i--){
        if(tab[i][a] != 0 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ;
    }
    return tab[0][a] ;
}
 
int main(){
 
    cin >> n >> q ;
 
    for(int i = 2 ; i <= n ; i++){
        cin >> a ;
        grafo[a].push_back(i), grafo[i].push_back(a) ;
    }
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++){
            tab[i][j] == -1 ;
        }
    }
    for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ;
    nivel[1] = 0 ;
    dfs(1, 1) ;
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(tab[i-1][j] == -1) continue ;
            tab[i][j] = tab[i-1][tab[i-1][j]] ;
        }
    }
    while(q--){
        cin >> a >> b ;
        cout << lca(a,b) << "\n" ;
    }
 
}
