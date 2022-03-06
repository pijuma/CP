#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, dp[maxn], ans, vis[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(!vis[a]) dfs(a, v) ; 
		dp[v] = max(dp[v], dp[a] + 1) ; 
	}

	ans = max(ans, dp[v]) ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; 
	}

	for(int i = 1 ; i <= n ; i++) if(!vis[i]) dfs(i, i) ; 

	cout << ans << "\n" ; 

}
