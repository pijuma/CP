#include<bits/stdc++.h>
#define int long long
using namespace std ;
 
const int maxn = 2e5 + 5 ;
const int maxl = 20 ;
 
int n, a, b, k ;
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
 
int32_t main(){
 
    cin >> n >> q ;
 
    for(int i = 2 ; i <= n ; i++){
        cin >> a ;
        grafo[a].push_back(i), grafo[i].push_back(a) ;
    }
 
    for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ;
    nivel[1] = 0 ;
    dfs(1, 0) ;
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(tab[i-1][j] == -1) continue ;
            tab[i][j] = tab[i-1][tab[i-1][j]] ;
        }
    }
    while(q--){
        cin >> a >> k ;
        int c = a ;
        for(int i = maxl - 1 ; i >= 0 ; i--){
            if(tab[i][c] != 0 && k >= (1<<i)){
                c = tab[i][c] ;
                k -= (1<<i) ;
               // cout << c << " " << k << "\n" ;
            }
        }
        if(k != 0) cout << "-1\n" ;
        else cout << c << "\n" ;
    }
 
}
