#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
const int maxl = 20 ; 
 
int n, m, q, pai[maxn], mx[maxl][maxn], tab[maxl][maxn], nivel[maxn], sz[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 
 
struct DSU{
    
    int find(int a){return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }
 
    void join(int a, int b){
    	a = find(a), b = find(b) ; 
    	if(sz[a] > sz[b]) swap(a, b) ;
    	sz[b] += sz[a] ; 
    	pai[a] = b ;   
    }	
 
} dsu ;
 
void dfs(int v, int p){
 
	tab[0][v] = p ; 
 
	for(auto a : grafo[v]){
		if(a.first == p || nivel[a.first] != -1) continue ; 
		nivel[a.first] = nivel[v] + 1 ; 
		mx[0][a.first] = a.second ; 
		dfs(a.first, v) ;  
	}
 
}
 
int lca(int a, int b){
	
	int ans = 0 ; 
	
	if(nivel[a] > nivel[b]) swap(a, b) ; // b mais fundo 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]){
			ans = max(ans, mx[i][b]) ;
			b = tab[i][b] ;
		}  
	}
 
	if(a == b) return ans ; 
 
	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && tab[i][a] != -1 && tab[i][a] != tab[i][b]){
			ans = max({ans, mx[i][b], mx[i][a]}) ; 
			a = tab[i][a], b = tab[i][b] ; 
		} 
	}
 
	return max({ans, mx[0][a], mx[0][b]}) ; 
 
}
 
int main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> m >> q ; 
 
	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		if(dsu.find(a) != dsu.find(b)){
			dsu.join(a, b) ; 
			grafo[a].push_back({b, i}), grafo[b].push_back({a, i}) ; 
		} 
	}
 
	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
			mx[i][j] = 0 ; 
		}
	}
 
	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 
 
	for(int i = 1 ; i <= n ; i++) if(nivel[i] == -1) nivel[i] = 0, dfs(i, 0) ; 
 
	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ;
			mx[i][j] = max(mx[i-1][j], mx[i-1][tab[i-1][j]]) ;  
		}
	}
 
	for(int i = 1 ; i <= q ; i++){
		int a, b ; 
		cin >> a >> b ; 
		if(dsu.find(a) != dsu.find(b)) cout << "-1\n" ; 
		else cout << lca(a, b) << "\n" ; 
	}
 
}
