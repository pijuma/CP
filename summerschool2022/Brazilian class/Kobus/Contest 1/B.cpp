#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int maxl = 20 ; 
const int inf = 1e9 ; 

int n, vis[maxn], nivel[maxn], mx_tab[maxl][maxn], tab[maxl][maxn], mn_tab[maxl][maxn] ; 
int q ; 

map<pair<int,int>, int> ar ; 
vector<pair<int,int>> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 
	tab[0][v] = p ; 
	mn_tab[0][v] = ar[{v, p}] ; 
	mx_tab[0][v] = ar[{v, p}] ; 

	for(auto a : grafo[v]){
		if(vis[a.first] || a.first == p) continue ; 
		nivel[a.first] = nivel[v] + 1 ; 
		dfs(a.first, v) ; 
	}

}


pair<int,int> lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; // subir com b 

	int mx = 0LL, mn = inf ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]){
			mx = max(mx, mx_tab[i][b]) ; mn = min(mn, mn_tab[i][b]) ; 
			b = tab[i][b] ; 
		}
	}

	if(a == b) return {mn, mx} ;

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && tab[i][a] != -1 && tab[i][a] != tab[i][b]){
			mx = max({mx, mx_tab[i][a], mx_tab[i][b]}) ; 
			mn = min({mn, mn_tab[i][a], mn_tab[i][b]}) ; 
			a = tab[i][a], b = tab[i][b] ; 
		}
	} 

	mn = min({mn, mn_tab[0][a], mn_tab[0][b]}) ; 
	mx = max({mx, mx_tab[0][a], mx_tab[0][b]}) ; 

	return {mn, mx} ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		
		int a, b, c ; 
		cin >> a >> b >> c ; 
		ar[{a, b}] = c ; ar[{b, a}] = c ; 
		grafo[a].push_back({b, c}) ; grafo[b].push_back({a, c}) ; 

	}

	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 

	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
			mx_tab[i][j] = 0LL ; 
			mn_tab[i][j] = inf ; 
		}
	}

	nivel[1] = 0 ; 
	dfs(1, -1) ; 

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
			mx_tab[i][j] = max(mx_tab[i-1][j], mx_tab[i-1][tab[i-1][j]]) ; 
			mn_tab[i][j] = min(mn_tab[i-1][j], mn_tab[i-1][tab[i-1][j]]) ; 
		}
	}

	cin >> q ; 

	while(q--){
		
		int a, b ; 
		cin >> a >> b ; 

		pair<int,int> ans = lca(a, b) ; 
		cout << ans.first << " " << ans.second << "\n" ; 

	}

}
