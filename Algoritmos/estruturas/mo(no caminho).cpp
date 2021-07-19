#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 4e4 + 5 ; 
const int maxm = 1e5 + 5 ; 
const int maxl = 22 ; 

int n, v[maxm], timer, sq, qtd_cor, cor_f[maxm], f[maxm], m ;
int vis[maxm], tab[maxl][maxm], ans[maxm], nivel[maxm], id[3*maxm], tin[maxm], tout[maxm] ;  
vector<int> grafo[maxm] ; 
map<int,int> mapa ;  

struct Q{
	int l, r, lca, id ;
} ; 

Q q[3*maxm] ; 

void dfs(int v, int p){

	tab[0][v] = p ; 
	tin[v] = ++timer ;
	id[timer] = v ; 

	for(auto a : grafo[v]){
		if(a == p) continue ;
		nivel[a] = nivel[v] + 1 ;  
		dfs(a, v) ; 
	}

	tout[v] = ++timer ;
	id[timer] = v ; 

}

bool cmp(Q a, Q b){ //ordena - mo 
	if((a.l/sq) != (b.l/sq)) return a.l < b.l ; 
	return ((a.l/sq)&1 ? (a.r < b.r) : (a.r > b.r)) ; 
}

int _lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; //sobe com b 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
	} 

	if(a == b) return a ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}

	return tab[0][a] ; 

}

void check(int pos){
	if(f[pos] && (--cor_f[v[pos]] == 0)) qtd_cor-- ; //aparece n° par de vzs e eh o unico da cor
	else if(!f[pos] && (cor_f[v[pos]]++ == 0)) qtd_cor++ ; //aparece n° impar d vzs e eh o unico da cor
	f[pos] ^= 1 ; 
}

void solve(){

	int ini = q[0].l, fim = q[0].l - 1 ; 

	for(int i = 0 ; i < m ; i++){
		
		int l = q[i].l, r = q[i].r ; 

		while(ini < l) check(id[ini++]) ;  
		while(ini > l) check(id[--ini]) ; 
		while(fim > r) check(id[fim--]) ;  
		while(fim < r) check(id[++fim]) ;  

		int u = id[l], v = id[r] ; 

		if(q[i].lca != u && q[i].lca != v) check(q[i].lca) ; //add lca 

		ans[q[i].id] = qtd_cor ; 

		if(q[i].lca != u && q[i].lca != v) check(q[i].lca) ; //retira lca

	}

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	int ct = 0 ; 

	for(int i = 1 ; i <= n ; i++){ //compressão
		cin >> v[i] ; 
		if(mapa.find(v[i]) == mapa.end()) mapa[v[i]] = ct++ ; 
		v[i] = mapa[v[i]] ; 
	} 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
		}
	}

	dfs(1, 1) ; 

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
		}
	}

	sq = 448 ; 

	for(int i = 0 ; i < m ; i++){
		int u, v ; 
		cin >> u >> v ; 
		int lca = _lca(u, v) ; // tin de u smp menor
		q[i].lca = lca ; 
		if(tin[v] < tin[u]) swap(u, v) ; //u smp tem tin menor 
		if(lca == u) q[i].l = tin[u], q[i].r = tin[v] ; 
		else q[i].l = tout[u], q[i].r = tin[v] ; 
		q[i].id = i ; 
	}

	sort(q, q + m, cmp) ; 

	solve() ; 

	for(int i = 0 ; i < m ; i++) cout << ans[i] << "\n" ; 

}
