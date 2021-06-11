#include<bits/stdc++.h>
using namespace std ;

const int maxn = 5e4 + 4 ; 

int n, a, b, c, dp[maxn][2], vis[maxn], ans ;
vector< pair<int,int> > grafo[maxn] ;

void dfs(int v, int p){

	vis[v] = 1 ; 

	for(int i = 0 ; i < grafo[v].size() ; i++){
		
		int u = grafo[v][i].first ; 
		int w = grafo[v][i].second ; 
		
		if(u == p) continue ; 

		dfs(u, v) ;

		if(w == 1) dp[v][1] = max(dp[v][1], dp[u][0] + 1) ;
		else dp[v][0] = max(dp[v][0], dp[u][1] + 1) ;  

	}

	ans = max(ans, dp[v][1] + dp[v][0] + 1) ;

}

int main(){

	cin >> n ; 
	
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}) ;
		grafo[b].push_back({a, c}) ; 
	}

	memset(vis, 0, sizeof vis) ; 
	dfs(1, -1) ;
	//memset(vis, 0, sizeof vis) ;
	//dfs(1, -1, 1) ; 
	
	cout << ans << "\n" ;

}
