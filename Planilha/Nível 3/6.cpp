#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, resp, dp[3][maxn], mark[maxn], valor[maxn] ; 
vector<int> grafo[maxn] ; 

// dp[1][v] -> qt max vzs eu somei 
// dp[0][v] -> qt max vzs tirei 
void dfs(int v, int p){

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs(a, v) ; 
		dp[1][v] = max(dp[1][v], dp[1][a]) ; 
		dp[0][v] = max(dp[0][v], dp[0][a]) ; 
	}
	
	valor[v] += (dp[1][v] - dp[0][v]) ; 
	(valor[v] < 0 ? dp[1][v] += abs(valor[v]) : dp[0][v] += valor[v]) ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) cin >> valor[i] ; 

	dfs(1, 1) ; 
  
    cout << dp[1][1] + dp[0][1] << "\n" ; 

} 
