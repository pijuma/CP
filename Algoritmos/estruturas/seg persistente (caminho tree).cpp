#include<bits/stdc++.h>
#define meio ((i+j)>>1)
using namespace std ; 

// k ésimo menor peso 
// seg persistente de soma, versão = prefixo, posição é a frequencia do valor i 

const int maxn = 5e5 + 5 ; 
const int maxl = 21 ; 

int tab[maxl][maxn], nivel[maxn], vis[maxn], tin[maxn], tout[maxn] ; 
int n, q, a, b, v[maxn], My_root[maxn], timer ;
vector<int> d, e, sum, grafo[maxn], root ; 

struct SEG{

	int create(){
		e.push_back(0) ; sum.push_back(0) ; d.push_back(0) ; 
		int sz = sum.size() - 1 ; 
		return max(0, sz) ; 
	}

	int upd(int no, int i, int j, int pos, int v){

		int neww = create() ; 
		e[neww] = e[no], d[neww] = d[no], sum[neww] = sum[no] ; 

		if(i == j){
			sum[neww]++ ; 
			return neww ; 
		}

		if(pos <= meio){
			int aux = upd(e[neww], i, meio, pos, v) ; 
			e[neww] = aux ; 
		}

		else{
			int aux = upd(d[neww], meio + 1, j, pos, v) ; 
			d[neww] = aux ; 
		}

		sum[neww] = sum[e[neww]] + sum[d[neww]] ; 

		return neww ; 

	}

	int query(int no_u, int no_v, int no_lca, int add, int i, int j, int k){

		// cout << no_u << " " << no_v << " " << no_lca << " " << i << " " << j << " " << k <<  "\n" ; 
		// cout << sum[no_v] << " " << sum[e[no_v]] << " " << sum[e[no_v]] + sum[e[no_u]] - 2*sum[e[no_lca]] + (add <= meio && add >= i ? 1 : 0) << "\n" ;  
		if(i == j) return i ;
		int val = sum[e[no_v]] + sum[e[no_u]] - 2*sum[e[no_lca]] + (add <= meio && add >= i ? 1 : 0) ;
		
		if(val >= k) return query(e[no_u], e[no_v], e[no_lca], add, i, meio, k) ; 
		else return query(d[no_u], d[no_v], d[no_lca], add, meio + 1, j, k - val) ; 
	
	}

} Seg ; 

void dfs(int vv, int p){ 
	
	vis[vv] = 1 ;  

	for(auto a : grafo[vv]){
		if(a == p || vis[a]) continue ; 
		nivel[a] = nivel[vv] + 1 ; 
		tab[0][a] = vv ;
		dfs(a, vv) ; 
	}

}

int lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
	}

	if(a == b) return a ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] && tab[i][b] && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}

	return tab[0][a] ; 

}

void dfs_built_seg(int vv, int p){

	root[vv] = Seg.upd(root[p], 1, maxn - 1, v[vv], 1) ; 

	for(auto a : grafo[vv]){
		if(a == p) continue ; 
		dfs_built_seg(a, vv) ;
	}

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) nivel[i] = 0, vis[i] = 0 ; 

	dfs(1, 0) ; 

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n  ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
		}
	}

	root.push_back(Seg.create()) ;

	for(int i = 1 ; i <= n ; i++) root.push_back(0) ; 

	dfs_built_seg(1, 0) ; 

	while(q--){
		
		int a, b, k ; 
		cin >> k >> a >> b ; 
		// cout << v[lca(a, b)] << "\n" ; 
		int l = lca(a, b) ;
		cout << Seg.query(root[a], root[b], root[l], v[l], 1, maxn - 1, k) << "\n" ; 

	}

}
