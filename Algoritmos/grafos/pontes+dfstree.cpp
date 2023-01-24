#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, timer, m, a, b, tin[maxn], vis[maxn], low[maxn], maior, dist[maxn], comp[maxn], br[maxn] ;
vector<pair<int, int>> grafo[maxn] ; 
vector<int> tree[maxn] ; 

void finding_b(int v, int p){

	tin[v] = low[v] = ++ timer ; 

	for(pair<int,int> a : grafo[v]){
		if(a.first == p) continue ; 
		if(tin[a.first]){
			low[v] = min(low[v], tin[a.first]) ; 
			continue ; 
		}

		finding_b(a.first, v) ; 

		if(low[a.first] > tin[v]) br[a.second] = 1 ; 

		low[v] = min(low[a.first], low[v]) ; 

	}

}

void dfs(int v, int c){
	comp[v] = c ; 
	vis[v] = 1 ; 
	for(pair<int,int> a : grafo[v]){
		if(br[a.second] || comp[a.first]) continue ;  
		dfs(a.first, c) ; 
	}
}

void dfs2(int v, int p){
	vis[v] = 1 ; 
	for(int a : tree[v]){
		if(a == p || vis[a]) continue ; 
		dist[a] = dist[v] + 1 ; 
		dfs2(a, v) ; 
	}
}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		a++, b++ ; 
		grafo[a].push_back({b, i}), grafo[b].push_back({a, i}) ; 
	}

	finding_b(1, 1) ; 

	int c = 0 ; 

	for(int i = 1 ; i <= n ; i++) if(!vis[i]) dfs(i, ++c) ; 

	for(int i = 1 ; i <= n ; i++){
		for(pair<int,int> a : grafo[i]){
			if(comp[i] == comp[a.first]) continue ; 
			tree[comp[i]].push_back(comp[a.first]), tree[comp[a.first]].push_back(comp[i]) ; 
		}
	}

	memset(vis, 0, sizeof vis) ; 

	dist[1] = 0 ; 
	dfs2(1, 1) ; 

	int p1, mx = 0 ; 

	for(int i = 1 ; i <= c ; i++) if(mx < dist[i]) mx = dist[i], p1 = i ; 

	dist[p1] = 0 ; 

    memset(vis, 0, sizeof vis) ; 

	dfs2(p1, p1) ; 

	mx = 0 ; 

	for(int i = 1 ; i <= c ; i++) if(mx < dist[i]) mx = dist[i] ; 

	cout << mx << "\n" ; 

}
