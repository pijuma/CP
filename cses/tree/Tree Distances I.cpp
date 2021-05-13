#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, m, dp[maxn], val[maxn], dist1[maxn], dist2[maxn], dist[maxn], a, b, t, vis[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int v, int p){
	for(int a : grafo[v]){
		if(a == p) continue ; 
		dist[a] = dist[v] + 1 ;
		dfs(a, v) ;   
	}
}
 
void dfs_u(int v, int p){
	for(int a : grafo[v]){
		if(a == p) continue ; 
		dist1[a] = dist1[v] + 1 ; 
		dfs_u(a, v) ; 
	}
}
 
void dfs_v(int v, int p){
	for(int a : grafo[v]){
		if(a == p) continue ; 
		dist2[a] = dist2[v] + 1 ; 
		dfs_v(a, v) ; 
	}
}
 
int main(){
	
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n ; 
 
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}
 
	dfs(1, 1) ; 
	
	int pa = 1, pb = 1 ; 
 
	for(int i = 1 ; i <= n ; i++){
		if(dist[i] > dist[pa]) pa = i ; 
	}
 
	dfs_u(pa, pa) ; 
 
	for(int i = 1 ; i <= n ; i++){
		if(dist1[i] > dist1[pb]) pb = i ; 
	}
 
	dfs_v(pb, pb) ; 
 
	for(int i = 1 ; i <= n ; i++){
		cout << max(dist1[i], dist2[i]) << " " ; 
	}
 
}
