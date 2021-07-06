#include<bits/stdc++.h>
#define int long long
using namespace std ; 

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

const int maxn = 2e5 + 5 ; 

int n, sz[maxn], tree[4*maxn], value[maxn], c, qtd, head[maxn] ; 
int cam[maxn], pos[maxn], vis[maxn], q, a, b, valor[maxn], nivel[maxn], pai[maxn] ; 
vector<int> grafo[maxn] ; 

struct SEG{

	void update(int no, int i, int j, int pos, int val){
		
		if(i == j && i == pos){
			tree[no] = val ; 
			valor[i] = val ; 
			return ; 
		}
		
		if(pos <= meio) update(esq, i, meio, pos, val) ; 
		else update(dir, meio + 1, j, pos, val) ; 

		tree[no] = max(tree[esq], tree[dir]) ; 

 	}

 	int query(int no, int i, int j, int l, int r){

		if(l > j || r < i) return 0 ; 

		if(l <= i && r >= j) return tree[no] ; 

		return max(query(esq, i, meio, l, r), query(dir, meio + 1, j, l, r)) ; 

	}

} seg ; 

void dfs(int v, int p){

	sz[v] = 1 ; 
	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		pai[a] = v ;
		dfs(a, v) ; 
		sz[v] += sz[a] ;  
	}

}

void hld(int v){

	if(!head[c]) head[c] = v ; 

	pos[v] = ++qtd, cam[v] = c ; 

	seg.update(1, 1, n, pos[v], value[v]) ;

	int maior = -1, id = -1 ; 

	for(auto a : grafo[v]){
		if(a == pai[v]) continue ; 
		if(sz[a] > maior){
			maior = sz[a] ; 
			id = a ; 
		}
	}

	if(id != -1) hld(id) ; 

	for(auto a : grafo[v]){
		if(a == pai[v] || id == a) continue ; 
		c++ ; 
		hld(a) ; 
	}

}

int lca(int a, int b){

	while(cam[a] != cam[b]){
		if(nivel[head[cam[a]]] > nivel[head[cam[b]]]) a = pai[head[cam[a]]] ; 
		else b = pai[head[cam[b]]] ; 
	}

	if(nivel[a] > nivel[b]) return b ; 
	else return a ; 

}

int query_path(int a, int b){

	int ans = 0 ; 

	while(cam[a] != cam[b]){
		ans = max(ans, seg.query(1, 1, n, pos[head[cam[a]]], pos[a])) ; 
		a = pai[head[cam[a]]] ; 
	}

	if(pos[a] == pos[b]) return max(ans, seg.query(1, 1, n, pos[a], pos[a])) ; 

	return max(ans, seg.query(1, 1, n, pos[b], pos[a])) ; 

}

void update(int a, int b) { seg.update(1, 1, n, pos[a], b) ; } 

int query(int a, int b){

	int l = lca(a, b) ; 

	return max(query_path(a, l), query_path(b, l)) ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> value[i] ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	dfs(1, 0) ; 
		
	hld(1) ; 

	while(q--){
		int tipo, a, b ; 
		cin >> tipo >> a >> b ; 
		if(tipo == 1) update(a, b) ; 
		else cout << query(a, b) << " " ; 
	}

	cout << "\n" ; 

}
