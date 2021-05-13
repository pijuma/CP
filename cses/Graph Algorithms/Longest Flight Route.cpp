#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 5e5 + 20 ;
 
// queremos maximizar o caminho
// da p usar dp
// d[x] � a maior dist de 1 a x
// d[i] = max(d[v] + 1, d[i]) ;
// d[1] = 0 ;
 
int n, m, grau[maxn], vis[maxn], dp[maxn], pai[maxn], x ;
vector<int> grafo[maxn] ;
vector<int> removed ;
vector<int> rev[maxn] ;
 
int main(){
 
    cin >> n >> m ;
 
    for(int i = 1 ; i <= m ; i++){
        int a, b ;
        cin >> a >> b ;
        grafo[a].push_back(b) ;
        rev[b].push_back(a) ;
        grau[b]++ ;
    }
    /*vis[1] = 1 ;
    dfs(1) ;
    /*for(int a : removed){
        for(int v : grafo[a]) grau[v]-- ;
    }*/
    for(int i = 1 ; i <= n ; i++) dp[i] = -999999999 ;
    queue<int> fila ;
    for(int i = 1 ; i <= n ; i++){
        if(grau[i] == 0) fila.push(i) ;
    }
    dp[1] = 1;
    pai[1] = -1 ;
    while(!fila.empty()){
        int u = fila.front() ;
        fila.pop() ;
        for(auto v : grafo[u]){
            if(dp[v] < dp[u] + 1){
                pai[v] = u ;
                dp[v] = dp[u] + 1 ;
            }
            grau[v]-- ;
            if(grau[v] == 0) fila.push(v) ;
        }
    }
    if(dp[n] < 0){
        cout << "IMPOSSIBLE\n" ;
        return 0 ;
    }
    cout << dp[n] << "\n" ;
    vector<int> ans ;
    x = n ;
    while(pai[x]!=-1){
        ans.push_back(x) ;
        x = pai[x] ;
    }
    ans.push_back(1) ;
    reverse(ans.begin(), ans.end()) ;
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " " ;
    cout << "\n" ;
}
