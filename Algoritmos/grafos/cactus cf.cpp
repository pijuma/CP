#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const int mod = 1e9 + 7 ;
const int maxl = 22 ; 
 
int n, m, c, q ; 
int nivel[maxn], sz[maxn], vis[maxn], comp[maxn], sum[maxn] ; 
int timer, tab[maxl][maxn], tin[maxn], low[maxn], brid[maxn] ; 
vector<int> tree[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 
 
void find_b(int v, int p){
 
	tin[v] = low[v] = ++timer ; 
 
	for(auto a : grafo[v]){
 
		if(a.first == p) continue ; 
 
		if(tin[a.first]){
			low[v] = min(low[v], tin[a.first]) ; 
			continue ; 
		}
 
		find_b(a.first, v) ; 
 
		if(low[a.first] > tin[v]) brid[a.second] = 1 ;
 
		low[v] = min(low[v], low[a.first]) ;  
 
	}
 
}
 
void dfs(int v, int p){
 
	vis[v] = 1 ; comp[v] = c ; 
 
	for(auto a : grafo[v]){
		if(a.first == p || vis[a.first] || brid[a.second]) continue ; 
		dfs(a.first, v) ; 
	}
 
}
 
void dfs_tree(int v, int p){
 
	tab[0][v] = p ; sum[v] = sum[p] + (sz[v] > 1) ; 
 
	for(auto a : tree[v]){
		if(a == p || nivel[a]) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		dfs_tree(a, v) ; 
	} 
 
}
 
int lca(int a, int b){
 
	if(nivel[a] > nivel[b]) swap(a, b) ; 
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
	}
 
	if(a == b) return a ; 
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && tab[i][a] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}
 
	return tab[0][b] ; 
 
}
 
int exp(int a, int b){
	
	int ans = 1 ; 
	
	while(b){
		if(b&1) ans = (ans*a)%mod ; 
		a = (a*a)%mod ; b >>= 1 ; 
	}
 
	return ans ; 
 
}
 
int32_t main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back({b, i}) ; grafo[b].push_back({a, i}) ; 
	}
 
	find_b(1, 1) ;
	for(int i = 1 ; i <= n ; i++){ 
		if(!vis[i]) {++c ; dfs(i, i) ;} 
	} 
 
	for(int i = 1 ; i <= n ; i++) sz[comp[i]]++ ;  
 
	for(int i = 1 ; i <= n ; i++){
		for(auto a : grafo[i]){
			if(comp[i] == comp[a.first]) continue ; 
			tree[comp[i]].push_back(comp[a.first]) ; tree[comp[a.first]].push_back(comp[i]) ; 
		}
	}
 
	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= c ; j++){
			tab[i][j] = -1 ; 
		}
	}
 
	dfs_tree(1, 1) ;
 
	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= c ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
		}
	}
 
	cin >> q ; 
 
	while(q--){
		
		int u, v ; cin >> u >> v ; 
		u = comp[u], v = comp[v] ; 
		
		int _lca = lca(u, v) ; 
		int ans = (sum[u] + sum[v] - 2*sum[_lca] + mod)%mod ; 
		
		if(sz[_lca] > 1) ans = (ans + 1)%mod ; 
		
		cout << exp(2, ans) << "\n" ; 
 
	}
 
}
