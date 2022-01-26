#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int inf = 1e9 ; 
const int maxn = 1e5 + 5 ; 

int ct, t, n, q, v[maxn] ; 

struct Node{
	int lazy_sum, lazy_subs, tree_quad, tree_val ; 
} ; 

Node tree[4*maxn] ; 

struct SEG {

	void flush(int no, int i, int j){

		if(tree[no].lazy_subs == 0 && tree[no].lazy_subs == -inf) return ; 

		if(tree[no].lazy_subs != -inf){
			tree[no].tree_val = (j-i+1)*tree[no].lazy_subs ; 
			tree[no].tree_quad = (j-i+1)*tree[no].lazy_subs*tree[no].lazy_subs ; 
		}

		if(tree[no].lazy_sum != 0){
			tree[no].tree_quad += (j-i+1)*tree[no].lazy_sum*tree[no].lazy_sum ; 
			tree[no].tree_quad += 2*tree[no].lazy_sum*tree[no].tree_val ; 
			tree[no].tree_val += (j-i+1)*tree[no].lazy_sum ; 
		}

		if(i != j){

			if(tree[no].lazy_subs != -inf){
				tree[esq].lazy_sum = 0, tree[dir].lazy_sum = 0 ; 
				tree[dir].lazy_subs = tree[esq].lazy_subs = tree[no].lazy_subs ; 
			}

			tree[esq].lazy_sum += tree[no].lazy_sum ; 
			tree[dir].lazy_sum += tree[no].lazy_sum ; 

		}

		tree[no].lazy_sum = 0 ; 
		tree[no].lazy_subs = -inf ;

	}

	void build(int no, int i, int j){

		if(i == j){
			tree[no].lazy_subs = -inf, tree[no].lazy_sum = 0, tree[no].tree_val = v[i], tree[no].tree_quad = v[i]*v[i] ; 
			return ;
		}

		build(esq, i, meio), build(dir, meio + 1, j) ; 

		tree[no].tree_quad = (tree[esq].tree_quad + tree[dir].tree_quad) ; 
		tree[no].tree_val = (tree[esq].tree_val + tree[dir].tree_val) ;
		tree[no].lazy_sum = 0, tree[no].lazy_subs = -inf ; 

	}

	void upd1(int no, int i, int j, int a, int b, int val){ // add nos vals 

		flush(no, i, j) ; 

		if(i > b || j < a) return ; 

		if(a <= i && b >= j){
			tree[no].lazy_sum += val ; 
			flush(no, i, j) ; 
			return ; 
		}

		upd1(esq, i, meio, a, b, val), upd1(dir, meio + 1, j, a, b, val) ; 

		tree[no].tree_quad = (tree[esq].tree_quad + tree[dir].tree_quad) ; 
		tree[no].tree_val = (tree[esq].tree_val + tree[dir].tree_val) ; 

	}

	void upd2(int no, int i, int j, int a, int b, int val){

		flush(no, i, j) ; 

		if(i > b || j < a) return ; 

		if(a <= i && b >= j){
			tree[no].lazy_sum = 0 ;
			tree[no].lazy_subs = val ;  
			flush(no, i, j) ; 
			return ; 
		}

		upd2(esq, i, meio, a, b, val), upd2(dir, meio + 1, j, a, b, val) ; 

		tree[no].tree_quad = (tree[esq].tree_quad + tree[dir].tree_quad) ; 
		tree[no].tree_val = (tree[esq].tree_val + tree[dir].tree_val) ; 

	}

	int query(int no, int i, int j, int a, int b){
		
		flush(no, i, j) ; 
		
		if(i > b || j < a) return 0 ; 
		if(a <= i && b >= j) return tree[no].tree_quad ; 
		
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 

	}

} Seg ;

int main(){

	cin >> t ; 

	while(t--){
		
		cin >> n >> q ; 

		for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

		Seg.build(1, 1, n) ; 

	    cout << "Case " << ++ct << ":\n" ; 

	    while(q--){

	    	int ty, l, r, val ; 
	    	cin >> ty ; 

	    	if(ty == 2){
	    		cin >> l >> r ; 
	    		cout << Seg.query(1, 1, n, l, r) << "\n" ; // soma dos quadrados 
	    	}

	    	else if(ty == 1){
	    		cin >> l >> r >> val ; 
	    		Seg.upd1(1, 1, n, l, r, val) ; // add val nos valores
	    	}

	    	else{
	    		cin >> l >> r >> val ; 
	    		Seg.upd2(1, 1, n, l, r, val) ; //setar os valores p val 
	    	}

	    }

	}

}
