#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxn = 1e3 + 5 ; 

int n, m, vis[maxn], ans, val[maxn][maxn], dp[maxn] ; 
vector<int> grafo[maxn] ; 

int dfs(int v, int p){

	if(dp[v] != -1) return dp[v] ; 

	dp[v] = 0 ; 
	
	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dp[v] = max(dp[v], dfs(a, v) + val[v][a]) ;
	}

	return dp[v] ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		
		int u, v, c ; 
		cin >> u >> v >> c ; 

		vis[v] = 1 ; 

		if(val[u][v] == 0) grafo[u].push_back(v) ;
		val[u][v] = max(val[u][v], c) ; 


	}

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			ans = max(ans, dfs(i, i)) ; 
		}
	}

	cout << ans << "\n" ; 

}
