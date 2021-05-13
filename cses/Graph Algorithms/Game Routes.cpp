#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 1e5 + 1 ;
const int M = 1e9 + 7 ;
 
int dp[maxn], vis[maxn], n, m, a[maxn] ;
vector<int> grafo[maxn] ;
const int inf = 1e9 ;
 
void dfs(int u){
	dp[u] = u == n - 1 ? 1 : 0 ;
	vis[u] = 1, a[u] = 1 ;
	for(int v : grafo[u]){
		if(a[v]){
			cout << "IMPOSSIBLE" ;
			exit(0) ;
		}
		else{
			if(!vis[v]){
				dfs(v) ;
			}
		}
		dp[u] = (dp[u] + dp[v])%M ;
	}
	a[u] = 0 ;
}
int main(){
 
	cin >> n >> m ;
 
	for(int i = 1 ; i <= m ; i++){
		long long a, b ;
		cin >> a >> b ;
		a--, b-- ;
		grafo[a].push_back(b) ;
	}
	for(int i = 0 ; i < n ; i++){
		if(!vis[i]) dfs(i) ;
	}
	cout << dp[0] ;
}
