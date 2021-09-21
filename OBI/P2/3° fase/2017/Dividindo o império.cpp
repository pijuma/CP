#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9  ; 

int n, res, m, vis[maxn], a, b, dp[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	
	dp[v] = 1 ;  

	for(int a : grafo[v]){
		if(a == p) continue ;  
		dfs(a, v) ; 
		dp[v] += dp[a] ;  
	}

}

int main(){

	cin >> n ; 

	res = n ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	 dfs(1, -1) ; 
	 
	 for(int i = 1 ; i <= n ; i++){
	 	res = min(res, abs(n - 2*dp[i])) ; 
	 }

	 cout << res << "\n" ; 

}
