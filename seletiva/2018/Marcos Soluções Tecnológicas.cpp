#include<bits/stdc++.h>
#define ll long long

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ;
const int maxm = 3e5 + 5 ;

// monta mst 
// pega do maior p menor peso usado 
// faz uma prefix sum 
// na query subtrai do peso total os k fios disponiveis
// faz bb na qtd boa de gad p usar 
// usa seg p guardar as ativas, a soma e a qtd a pos guarda o valor da aresta ou gad e 
// a qtd daql 

struct ar{
	int a, b, c ; 
} ;

struct T{
	ll sum, qtd ; 
} ;

int n, m, k, q ;
int pai[maxn], gad[maxn], sz[maxn] ; 
T tree[4*maxn] ; 
ar aresta[maxm] ; 

bool cmp(ar a, ar b){ return a.c <= b.c ; }

struct DSU{

	int find(int a){ return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ; 
		if(a == b) return ; 
		if(sz[a] > sz[b]) swap(a, b) ; 
		pai[a] = b ; 
		sz[b] += sz[a] ; 
	}

} dsu ; 

struct SEG{

	void upd(int no, int i, int j, int pos, int val){
		
		if(i == j && i == pos){
			tree[no].qtd += val ; 
			tree[no].sum += pos*val ;
			return ;
		}

		if(pos <= meio) upd(esq, i, meio, pos, val) ;
		else upd(dir, meio + 1, j, pos, val) ; 

		tree[no].qtd = tree[esq].qtd + tree[dir].qtd ; 
		tree[no].sum = tree[esq].sum + tree[dir].sum ; 

	}

	ll query(int no, int i, int j, int qtd){
		if(!qtd) return 0 ; 
		if(i == j) return i*qtd ;
		if(tree[esq].qtd >= qtd) return query(esq, i, meio, qtd) ; 
		return tree[esq].sum + query(dir, meio + 1, j, qtd - tree[esq].qtd) ; 
	}

	void see(){
		for(int i = 1 ; i <= 4*9 ; i++) cout << i << " " << tree[i].sum << " " << tree[i].qtd << "\n" ; 
	}

} seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m >> k >> q ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		aresta[i] = {a, b, c} ; 
	}

	for(int i = 1 ; i <= k ; i++){
		cin >> gad[i] ; 
		seg.upd(1, 1, maxn - 1, gad[i], 1) ; 
	}

	sort(aresta + 1, aresta + 1 + m, cmp) ; 

	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

	for(int i = 1 ; i <= m ; i++){
		if(dsu.find(aresta[i].a) == dsu.find(aresta[i].b)) continue ; 
		dsu.join(aresta[i].a, aresta[i].b) ; 
		seg.upd(1, 1, maxn - 1, aresta[i].c, 1) ; 
	}

	// 4 4 3 2

	cout << seg.query(1, 1, maxn - 1, n - 1) << "\n" ; 

	for(int i = 1 ; i <= q ; i++){
		
		int op, val ; 
		cin >> op >> val ; 
		
		if(op == 1){
			seg.upd(1, 1, maxn - 1, val, 1) ;
			cout << seg.query(1, 1, maxn - 1, n - 1) << "\n" ; 
		}

		else{
			seg.upd(1, 1, maxn - 1, val, -1) ; 
			cout << seg.query(1, 1, maxn - 1, n - 1) << "\n" ;  
		}

	}

}
