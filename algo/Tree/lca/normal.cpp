#include <bits/stdc++.h>

using namespace std;

const int maxl = 20 ;
const int maxn = 5e4 + 10 ;

long long resp;

int n, x, nivel[maxn], tab[maxn][maxl], c[maxn], par[maxn], a, b ;
vector<int> grafo[maxn] ;

void dfs(int v, int p){

    tab[v][0] = p ;

    for(int i = 0 ; i < (int) grafo[v].size() ; i++){

        int u = grafo[v][i] ;

        if(v == u) continue ;

        if(nivel[u] == -1){

            nivel[u] = nivel[v] + 1 ;
            dfs(u, v) ;
        }
    }
}

int lca(int u, int v){

    if(nivel[u] < nivel[v]) swap(u, v) ;

    for(int i = maxl - 1 ; i >= 0 ; i--){

        if(tab[u][i] != -1 && nivel[tab[u][i]] >= nivel[v]) u = tab[u][i] ;

    }

    if(v == u) return u ;

    for(int i = maxl - 1 ; i >= 0 ; i--){

        if(tab[u][i] != tab[v][i]){

            u = tab[u][i] ;
            v = tab[v][i] ;

        }

    }

    return tab[u][0] ;

}

int main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; i++){

        cin >> x ;

        if(c[x]){

            par[i] = c[x] ;
            par[c[x]] = i ;

        }

        c[x] = i ;

    }

    for(int i = 1 ; i < n ; i++){

        cin >> a >> b ;

        grafo[a].push_back(b) ;
        grafo[b].push_back(a) ;

    }

    memset(nivel, -1, sizeof(nivel)) ;
    memset(tab, -1, sizeof(tab)) ;

    nivel[1] = 0 ;
    dfs(1, -1) ;

    for(int j = 1 ; j < maxl ; j++){

        for(int i = 1 ; i <= n ; i++){

            tab[i][j] = tab[tab[i][j-1]][j-1] ;

        }

    }

    for(int i = 1 ; i <= n ; i++){

        resp += (long long) (nivel[i] + nivel[par[i]] - 2*nivel[lca(i, par[i])]) ;
    }

    cout << resp/2 << "\n" ;
}
