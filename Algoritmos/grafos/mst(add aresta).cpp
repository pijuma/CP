#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxl = 22 ; 
const int maxn = 2e5 + 5 ; 
 
struct A{
	int a, b, c ; 
} ; 
 
bool cmp(A a, A b){ return a.c < b.c ; }
 
A qr[maxn], ar[maxn] ; 
 
int n, m, tab[maxl][maxn], ans, mx[maxl][maxn], nivel[maxn], pai[maxn], sz[maxn] ; 
vector<pair<int,int>> grafo[maxn] ;
 
struct DSU{
 
	int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }
 
	void join(int a, int b){
		a = find(a), b = find(b) ; 
		if(sz[a] > sz[b]) swap(a, b) ; 
		sz[b] += sz[a] ; pai[b] = a ; 
	}
 
} dsu ;  
 
void dfs(int v, int p){
 
	tab[0][v] = p ; 
 
	for(auto a : grafo[v]){
		if(nivel[a.first] != -1 || a.first == p) continue ;
		nivel[a.first] = nivel[v] + 1 ;
		mx[0][a.first] = a.second ;  
		dfs(a.first, v) ;  
	}
}
 
int lca(int a, int b){
 
	if(nivel[a] > nivel[b]) swap(a, b) ; 
 
	int ans = 0 ; 
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]){
			ans = max(ans, mx[i][b]) ; 
			b = tab[i][b] ; 
		}
	}
 
	if(a == b) return ans ; 
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && tab[i][a] != -1 && tab[i][a] != tab[i][b]){
			ans = max({ans, mx[i][a], mx[i][b]}) ; 
			a = tab[i][a], b = tab[i][b] ; 
		}
	}
 
	return max({ans, mx[0][a], mx[0][b]}) ; 
 
}
 
int32_t main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1, nivel[i] = -1 ; 
 
	for(int i = 1 ; i <= m ; i++){
		int u, v, w ; cin >> u >> v >> w ; 
		qr[i] = {u, v, w} ; ar[i] = {u, v, w} ; 
	}
 
	sort(ar + 1, ar + 1 + m, cmp) ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a = ar[i].a, b = ar[i].b, c = ar[i].c ; 
		if(dsu.find(a) == dsu.find(b)) continue ;
		dsu.join(a, b) ; ans += c ;  
		grafo[a].push_back({b, c}) ; grafo[b].push_back({a, c}) ;   
	}
 
	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++) tab[i][j] = -1, mx[i][j] = 0 ; 
	}
 
	nivel[1] = 0 ; 
	dfs(1, -1) ; 
 
	// for(int i = 1 ; i <= n ; i++) cout << tab[0][i] << "\n" ; 
 
	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
			mx[i][j] = max(mx[i-1][j], mx[i-1][tab[i-1][j]]) ;
		}
	}
 
	for(int i = 1 ; i <= m ; i++){
		cout << ans + qr[i].c - lca(qr[i].a, qr[i].b) << "\n" ; 
	}
 
}
