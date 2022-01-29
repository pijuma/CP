#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e4 + 5 ; 
const int maxl = 22 ; 

int t, n, vis[maxn], nivel[maxn], dist[maxn], tab[maxl][maxn] ; 
map<pair<int,int>,int> mp ; 
vector<pair<int,int>> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 
	tab[0][v] = p ; 

	for(auto a : grafo[v]){
		if(vis[a.first] || a.first == p) continue ; 
		nivel[a.first] = nivel[v] + 1 ; 
		dist[a.first] = dist[v] + a.second ; 
		dfs(a.first, v) ; 
	}

}

int lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ;  
	}

	if(a == b) return a ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}

	return tab[0][a] ; 

}

int kth(int a, int b, int k){
 
	int d ; 
 
	d = nivel[a] - nivel[lca(a,b)] + 1 ; 
 
	if(k > d){ // ta no cam de b p lca 
		k -= nivel[a] - nivel[lca(a, b)] + 1 ;
		d = nivel[b] - nivel[lca(a, b)] ; 
		k = d - k ;  
		for(int i = maxl - 1 ; i >= 0 ; i--){
			if((1<<i) <= k){
				b = tab[i][b] ;
				k -= (1<<i) ; 
			}
		}
		return b ; 
	}
 
	else{
		k-- ; 
		for(int i = maxl - 1 ; i >= 0 ; i--){
			if((1<<i) <= k){
				a = tab[i][a] ; 
				k -= (1<<i) ; 
			}
		}
		return a ; 
	}
 
}
int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	cin >> t ; 

	while(t--){

		cin >> n ; 

		mp.clear() ; 

		for(int i = 1 ; i <= n ; i++) nivel[i] = -1, dist[i] = 0, vis[i] = 0 ; 
		for(int i = 0 ; i < maxl ; i++){
			for(int j = 1 ; j <= n ; j++){
				tab[i][j] = -1 ; 
			}
		}

		for(int i = 1 ; i < n ; i++){
			int a, b, c ; 
			cin >> a >> b >> c ; 
			mp[{a, b}] = mp[{b, a}] = c ; 
			grafo[a].push_back({b, c}) ; grafo[b].push_back({a, c}) ; 
		}

		nivel[1] = 0 ; 
		dfs(1, -1) ; 

		for(int i = 1 ; i < maxl ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(tab[i-1][j] == -1) continue ; 
				tab[i][j] = tab[i-1][tab[i-1][j]] ; 
			}
		}

		while(true){
			
			string s ; 
			cin >> s ; 

			if(s == "DIST"){
				int a, b ; 
				cin >> a >> b ; 
				cout << dist[a] + dist[b] - 2*dist[lca(a, b)] << "\n" ; 
			}

			else if(s == "KTH"){
				
				int a, b, k ; 
				cin >> a >> b >> k ; 

				cout << kth(a, b, k) << "\n" ; 

			}

			else break ; 

		}

		for(int i = 1 ; i <= n ; i++) grafo[i].clear() ; 

		cout << "\n" ; 

	}

}
