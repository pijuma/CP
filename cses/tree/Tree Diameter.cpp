#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, a, b, diam, dp[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int v, int p){
    dp[v] = 0 ; 
    for(int a : grafo[v]){
        if(a == p) continue ; 
        dfs(a, v) ; 
        diam = max(diam, dp[v] + dp[a] + 1) ; 
        dp[v] = max(dp[v], dp[a] + 1) ; 
    }
}
int main(){
 
    cin >> n ; 
 
    for(int i = 1 ; i < n ; i++){
        cin >> a >> b ; 
        grafo[a].push_back(b), grafo[b].push_back(a) ; 
    }
 
    dfs(1, 1) ; 
 
    cout << diam << "\n" ; 
 
}
