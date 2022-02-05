#include<bits/stdc++.h>
#define int long long 

using namespace std ; 


const int MAX = 505 ; 
const int maxn = 5e5 + 5 ; 
const int maxl = 22 ; 

struct aresta{
	int a, b, p ; 
} ; 

int n, m, q, vert ; 
int g[MAX][MAX] ;
int tab[maxl][maxn], mx_tab[maxl][maxn] ; 
int nivel[maxn], pai[maxn], vis[maxn], sz[maxn] ; 
aresta query[maxn] ; 
int vertex[MAX][MAX] ; 
vector<pair<int,int>> grafo[maxn] ; 

int dx[4] = {0, 1} ; 
int dy[4] = {1, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

bool cmp(aresta a, aresta b){ return a.p < b.p ; } 

void ini(int x){

	for(int i = 1 ; i <= x ; i++) pai[i] = i, sz[i] = 1, nivel[i] = -1 ; 

	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= x ; j++){
			tab[i][j] = -1, mx_tab[i][j] = 0 ; 
		}
	}

}

struct DSU{

	int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		
		a = find(a), b = find(b) ; 

		if(sz[a] > sz[b]) swap(a, b) ; // b smp maior 

		pai[a] = b ; 
		sz[b] += sz[a] ; 

	}

} dsu ; 


void dfs(int v, int p, int val){

	tab[0][v] = p ; mx_tab[0][v] = val ; 
	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a.first == p || vis[a.first]) continue ; 
		nivel[a.first] = nivel[v] + 1 ; 
		dfs(a.first, v, a.second) ; 
	}

}

int lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; // b sobe 

	int mx = 0 ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
	
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]){
			mx = max(mx, mx_tab[i][b]) ; 
			b = tab[i][b] ; 
		}
	
	}

	if(a == b) return mx ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]){
			mx = max({mx, mx_tab[i][b], mx_tab[i][a]}) ; 
			b = tab[i][b] ; a = tab[i][a] ; 
		}
	}

	mx = max({mx, mx_tab[0][a], mx_tab[0][b]}) ; 

	return mx ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m >> q ; 

	for(int i = 1 ; i <= n ; i++){
		
		for(int j = 1 ; j <= m ; j++){
		
			cin >> g[i][j] ; 
			vertex[i][j] = ++vert ; 
		
		}

	}

	int ct = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		
		for(int j = 1 ; j <= m ; j++){
		
			for(int k = 0 ; k < 2 ; k++){

				int pi = i + dx[k], pj = j + dy[k] ; 
				
				if(!valid(pi, pj)) continue ; 

				int v1 = vertex[i][j], v2 = vertex[pi][pj] ;
				int peso = max(g[i][j], g[pi][pj]) ; 

				ct++ ; 
				query[ct].a = v1, query[ct].b = v2, query[ct].p = peso ; 

			}

		}

	}

	sort(query + 1, query + 1 + ct, cmp) ; 

	ini(vert) ;

	for(int i = 1 ; i <= ct ; i++){
		
		int f = query[i].a, s = query[i].b ; 
		if(dsu.find(f) == dsu.find(s)) continue ; 

		dsu.join(f, s) ; 
		grafo[f].push_back({s, query[i].p}), grafo[s].push_back({f, query[i].p}) ; 

	}

	nivel[1] = 0 ; 
	dfs(1, 0, 0) ; 

	for(int i = 1 ; i < maxl ; i++){

		for(int j = 1 ; j <= vert ; j++){

			if(tab[i-1][j] == -1) continue ; 

			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
			mx_tab[i][j] = max(mx_tab[i-1][j], mx_tab[i-1][tab[i-1][j]]) ; 

		}

	}

	// for(int i = 1 ; i <= vert ; i++){
	// 	for(int j = 0 ; j < maxl ; j++){
	// 		cout << mx_tab[j][i] << " " ; 
	// 	}
	// 	cout << "\n" ; 
	// }

	for(int i = 1 ; i <= q ; i++){

		int x1, x2, y1, y2 ; 

		cin >> x1 >> y1 >> x2 >> y2 ; 

		int v1 = vertex[x1][y1], v2 = vertex[x2][y2] ; 

		if(v1 == v2) cout << g[x1][y1] << "\n" ; 
		else cout << lca(v1, v2) << "\n" ; 

	}

}
