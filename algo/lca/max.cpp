#include<bits/stdc++.h>
#define ll long long 

using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int maxl = 20 ; 

int n, m, q ; 
int tab[maxl][maxn], max_t[maxl][maxn], nivel[maxn] ;
vector<int>grafo[maxn] ; 
map<pair<int,int>, int > p ; 

void dfs(int v, int pai){
	
	max_t[0][v] = p[{v, pai}] ;
	tab[0][v] = pai ;

	for(int i = 0 ; i < grafo[v].size() ; i++){
		int u = grafo[v][i] ; 
		if(nivel[u] != -1 || u == pai) continue ; 
		nivel[u] = nivel[v] + 1 ; 
		dfs(u, v) ; 
	}

}

int lca(int a, int b){

	int ans = 0 ; 

	if(nivel[a] > nivel[b]) swap(a, b) ; // b eh o mais dist smp 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(nivel[tab[i][b]] >= nivel[a] && tab[i][b] != -1){
			ans = max(ans, max_t[i][b]) ; 
			b = tab[i][b] ; 
		}
	}

	if(a == b) return ans ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != tab[i][b] && tab[i][a] != -1){
			ans = max({ans, max_t[i][a], max_t[i][b]}) ; 
			a = tab[i][a], b = tab[i][b] ; 
		}
	}

	return max({ans, max_t[0][a], max_t[0][b]}) ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i < n ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ;
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
		p[{a, b}] = c ; 
		p[{b, a}] = c ; 
	}

	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
			max_t[i][j] = 0 ;  
		}
	}

	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 

	nivel[1] = 0 ;
	dfs(1, -1) ; 

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
			max_t[i][j] = max(max_t[i-1][j], max_t[i-1][tab[i-1][j]]) ; 
		}
	}

	cin >> q ; 

	for(int i = 1 ; i <= q ; i++){
		int a, b ; 
		cin >> a >> b ; 
		cout << lca(a, b) << "\n" ; 
	}

}
