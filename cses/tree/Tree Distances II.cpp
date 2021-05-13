#include<bits/stdc++.h>
#define int long long
using namespace std ;
 
const int maxn = 2e5 + 5 ;
 
int dp[maxn], ans[maxn], nivel[maxn] ;
int a, b, n ;
vector<int> grafo[maxn] ;
 
void dfs(int v, int p, int d){ // calcular qts caras tem na sub de cada um 
    nivel[v] = d ;
    dp[v] = 1 ;
    for(int a : grafo[v]){
        if(a == p) continue ;
        dfs(a,  v, d+1) ;
        dp[v] += dp[a] ;
    }
}
 
void dfs2(int v, int p){
    for(int a : grafo[v]){
        if(a == p) continue ;
        ans[a] = ans[v] + n - 2*dp[a] ; //fora aumenta 1, na sub reduz 1 na dist 
        dfs2(a, v) ;
    }
}
 
int32_t main(){
 
    cin >> n ;
 
    for(int i = 1 ; i < n ; i++){
        cin >> a >> b ;
        grafo[a].push_back(b), grafo[b].push_back(a) ;
    }
    dfs(1, 0, 0) ;
    for(int i = 2 ; i <= n ; i++) ans[1] += nivel[i] ; //pro 1 a dist total p cada um é a soma dos níveis 
    dfs2(1, 0) ;
    for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ;
}
