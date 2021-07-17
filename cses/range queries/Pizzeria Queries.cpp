#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

const int maxn = 2e5 + 5 ; 
const int inf = 1e17 ; 

int n, x, tipo, k, p, q, v[maxn], tree_d[4*maxn], tree_u[4*maxn] ; 

// pa + |a-b| -> sendo a o local da pizzaria 
// p qd ta esq a eh menor ent fica a - b 
// p cima fica -a + b 

struct SEG{

	void build_d(int no, int i, int j){
		
		if(i == j){
			tree_d[no] = v[i] + i ; 
			return ;
		}

		build_d(esq, i, meio), build_d(dir, meio + 1, j) ; 

		tree_d[no] = min(tree_d[esq], tree_d[dir]) ; 

	}

	void build_u(int no, int i, int j){

		if(i == j){
			tree_u[no] = v[i] - i ; 
			return ; 
		}

		build_u(esq, i, meio), build_u(dir, meio + 1, j) ; 

		tree_u[no] = min(tree_u[esq], tree_u[dir]) ; 

	}

	void upd_d(int no, int i, int j, int pos, int val){
		
		if(i == j && i == pos){
			tree_d[no] = val ; 
			return ; 
		}

		if(pos <= meio) upd_d(esq, i, meio, pos, val) ; 
		else upd_d(dir, meio + 1, j, pos, val) ; 

		tree_d[no] = min(tree_d[esq], tree_d[dir]) ; 

	}

	void upd_u(int no, int i, int j, int pos, int val){

		if(i == j && i == pos){
			tree_u[no] = val ; 
			return ; 
		}

		if(pos <= meio) upd_u(esq, i, meio, pos, val) ; 
		else upd_u(dir, meio + 1, j, pos, val) ; 

		tree_u[no] = min(tree_u[esq], tree_u[dir]) ; 

	}

	int query_u(int no, int i, int j,  int a, int b){

		if(b < i || a > j) return inf ; 
		if(a <= i && b >= j) return tree_u[no] ;

		return min(query_u(esq, i, meio, a, b), query_u(dir, meio + 1, j, a, b)) ; 

	}

	int query_d(int no, int i, int j, int a, int b){

		if(b < i || a > j) return inf ; 
		if(a <= i && b >= j) return tree_d[no] ; 

		return min(query_d(esq, i, meio, a, b), query_d(dir, meio + 1, j, a, b)) ; 

	}

} seg ; 

int32_t main(){

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	seg.build_d(1, 1, n), seg.build_u(1, 1, n) ;

	while(q--){

		cin >> tipo ; 

		if(tipo == 1){
			cin >> k >> x ; //k vira x 
			seg.upd_d(1, 1, n, k, x + k) ; 
			seg.upd_u(1, 1, n, k, x - k) ; 
		}

		else{

			cin >> k ; 
			
			int UP = seg.query_u(1, 1, n, 1, k) + k ; 
			int D = seg.query_d(1, 1, n, min(n, k + 1), n) - k ; 

			cout << min(UP, D) << "\n" ; 

		}

	} 

}
