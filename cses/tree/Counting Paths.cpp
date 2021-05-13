#include<bits/stdc++.h>
 
using namespace std ; 
 
const int maxn = 2e5 + 5 ;
const int maxl = 21 ; 
 
int n, m, a, b, d, tab[maxl][maxn], ans[maxn], nivel[maxn], vis[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int v, int p){
	
	tab[0][v] = p ; 
	
	for(int a : grafo[v]){
		if(a == p || nivel[a] != -1) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		dfs(a, v) ; 
	}
 
}
 
void dfs2(int v, int p){ //faz "soma de prefixo" 
	
	ans[v] = vis[v] ; 
	nivel[v] = 0 ;
 	for(int a : grafo[v]){
		if(a == p || nivel[a] != -1) continue ; 
		dfs2(a, v) ; 
		ans[v] += ans[a] ; 
	}
 
}
 
int lca(int a, int b){
	
	if(nivel[a] > nivel[b]) swap(a, b) ;  
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
	}
 
	if(a == b) return a ; 
 
	for(int i =  maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}
 
	return tab[0][a] ;
 
}
 
int main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> m ; 
 
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}
 
	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
		}
	}
 
	for(int i = 1 ; i <= n ; i++) nivel[i] = -1, vis[i] = 0, ans[i] = 0 ;
 
	nivel[1] = 1 ; 
 
	dfs(1, 0) ;
 
	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
		}
	}
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		d = lca(a, b) ; 
		vis[a]++, vis[b]++, vis[d]--, vis[tab[0][d]]-- ; 
	}
 
	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 
 
	dfs2(1, 0) ; 
 
	for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 
 
}
