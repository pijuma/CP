#include<bits/stdc++.h>
#define meio ((i+j)>>1)
#define int long long 
using namespace std ; 

const int maxx = 1e18 ; 
const int maxn = 1e5 + 5 ; 
const int maxl = 21 ; 

int n, m ; 
int vis[maxn], val[maxn], nivel[maxn], tab[maxl][maxn] ;
vector<int> grafo[maxn] ;
vector<int> root, e, d, sum ; 

void dfs(int v, int p){

	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(vis[a] || a == p) continue ; 
		nivel[a] = nivel[v] + 1 ;
		tab[0][a] = v ; 
		dfs(a, v) ; 
	}

}

struct SEG{

	int create(){
		e.push_back(0) ; d.push_back(0) ; sum.push_back(0) ; 
		int sz = sum.size() - 1 ; 
		return max(0LL, sz) ;  
	}

	int upd(int no, int i, int j, int pos, int v){

		int neww = create() ; 
		e[neww] = e[no] ; d[neww] = d[no] ; sum[neww] = sum[no] ; 

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

	int query(int no_a, int no_b, int no_lca, int lca_val, int i, int j, int k){

		if(i == j) return i ; 

		int val = sum[e[no_a]] + sum[e[no_b]] - 2*sum[e[no_lca]] + (lca_val >= i && lca_val <= meio) ; 

		if(val >= k) return query(e[no_a], e[no_b], e[no_lca], lca_val, i, meio, k) ; 
		else return query(d[no_a], d[no_b], d[no_lca], lca_val, meio + 1, j, k - val) ; 
	
	}

} Seg ; 

void dfs_build_seg(int v, int p){

	root[v] = Seg.upd(root[p], 1, 2*maxx - 1, val[v], 1) ;  

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs_build_seg(a, v) ; 
	}

}

int _lca(int a, int b){

	if(nivel[a] > nivel[b]) swap(a, b) ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
	}

	if(a == b) return b ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][b] && tab[i][a] && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}

	return tab[0][a] ; 

}


int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> val[i] ; val[i] += maxx ; 
	}

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) nivel[i] = 0, vis[i] = 0 ; 

	dfs(1, 0) ; 

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
		}
	}

	root.push_back(Seg.create()) ; 

	for(int i = 1 ; i <= n ; i++) root.push_back(0) ; 

	dfs_build_seg(1, 0) ; 

    for(int i = 1 ; i <= m ; i++){

    	int a, b, k ; 
    	cin >> a >> b >> k ; 

    	int lca = _lca(a, b) ; 
    	
    	cout << Seg.query(root[a], root[b], root[lca], val[lca], 1, 2*maxx - 1, k) - maxx << "\n" ; 
    
    }

}
