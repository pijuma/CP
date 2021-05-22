#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, vis[maxn], a, b, dp[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v){

	vis[v] = 1 ; 

	for(int a : grafo[v]){
		if(!vis[a]) dfs(a) ;  
		dp[v] = max(dp[v], dp[a] + 1) ;  
	}

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i  <= m ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b) ; 
	}

	for(int i = 1 ; i <= n ; i++) if(!vis[i]) dfs(i) ; 

	int ans = 0 ; 

	for(int i = 1 ; i <= n ; i++) if(dp[i] > ans) ans = dp[i] ; 

	cout << ans << "\n" ; 

}
