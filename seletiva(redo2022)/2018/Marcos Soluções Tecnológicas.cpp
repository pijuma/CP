#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

#define int long long 
using namespace std ; 

const int maxn = 3e5 + 5 ; 

int n, m, v[maxn], k, q, c, sz[maxn], pai[maxn] ; 

struct TREE{
	int val, qtd ; 
} ; 

struct aresta{
	int a, b, peso ; 
} ; 

TREE tree[4*maxn] ; 
aresta ar[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 

bool cmp(aresta a, aresta b){ return a.peso < b.peso ; }

struct DSU{

	int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		
		a = find(a), b = find(b) ; 
		
		if(sz[a] > sz[b]) swap(a, b) ; 
		
		sz[b] += sz[a] ; 
		pai[a] = b ; 

	}

} dsu ; 

struct SEG{

	void upd(int no, int i, int j, int pos, int val){
		if(i == j){
			tree[no].qtd += val ; tree[no].val += (i*val) ; 
			return ;  
		}
		if(pos <= meio) upd(esq, i, meio, pos, val) ; 
		else upd(dir, meio + 1, j, pos, val) ; 
		tree[no].val = tree[esq].val + tree[dir].val ; 
		tree[no].qtd = tree[esq].qtd + tree[dir].qtd ; 
	}

	int query(int no, int i, int j, int k){
		if(!k) return 0 ;  
		if(i == j) return i*k ; 
		if(tree[esq].qtd >= k) return query(esq, i, meio, k) ; 
		else return tree[esq].val + query(dir, meio + 1, j, k-tree[esq].qtd) ; 
	}


} Seg ; 

int32_t main(){

	cin >> n >> m >> k >> q ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}) ; grafo[b].push_back({a, c}) ; 
		ar[i] = {a, b, c} ; 
	}

	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

	sort(ar + 1, ar + 1 + m, cmp) ; 

	for(int i = 1 ; i <= m ; i++){
		if(dsu.find(ar[i].a) == dsu.find(ar[i].b)) continue ; 
		dsu.join(ar[i].a, ar[i].b) ; 
		Seg.upd(1, 1, maxn-1, ar[i].peso, 1) ; 
	}

	for(int i = 1 ; i <= k ; i++){
		int val ; 
		cin >> val ; 
		Seg.upd(1, 1, maxn-1, val, 1) ; 
	}

	cout << Seg.query(1, 1, maxn-1, n-1) << "\n" ; 
	
	for(int i = 1 ; i <= q ; i++){
		int type, val ; 
		cin >> type >> val ; 
		Seg.upd(1, 1, maxn-1, val, type) ; 
		cout << Seg.query(1, 1, maxn-1, n-1) << "\n" ; 
	}

}
