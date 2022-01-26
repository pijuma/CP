#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, q, t, a, b ; 

struct Node{
	int rest1, rest2, rest0, lazy ; 
} ;

Node tree[4*maxn] ; 

struct SEG{

	void build(int no, int i, int j){
		if(i == j){
			tree[no].rest0 = (j-i+1) ; 
			return ; 
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no].rest0 = tree[esq].rest0 + tree[dir].rest0 ; 
	}

	void flush(int no, int i, int j){
		
		if(tree[no].lazy == 0) return ;
		
		int r1 = tree[no].rest1, r2 = tree[no].rest2, r0 = tree[no].rest0 ; 
		
		if(tree[no].lazy%3 == 1){
			tree[no].rest0 = r2, tree[no].rest1 = r0, tree[no].rest2 = r1 ; 
		}
		
		if(tree[no].lazy%3 == 2){
			tree[no].rest2 = r0, tree[no].rest0 = r1, tree[no].rest1 = r2 ; 
		}

		if(i != j){
			tree[esq].lazy += tree[no].lazy ; 
			tree[dir].lazy += tree[no].lazy ; 
		}

		tree[no].lazy = 0 ; 

	}

	void upd(int no, int i, int j, int a, int b){
		flush(no, i, j) ; 
		if(b < i || a > j) return ; 
		if(a <= i && b >= j){
			tree[no].lazy++ ; 
			flush(no, i, j) ;
			return ; 
		}
		upd(esq, i, meio, a, b), upd(dir, meio + 1, j, a, b) ; 
		tree[no].rest1 = (tree[esq].rest1 + tree[dir].rest1) ; 
		tree[no].rest2 = (tree[esq].rest2 + tree[dir].rest2) ; 
		tree[no].rest0 = (tree[esq].rest0 + tree[dir].rest0) ; 
	}

	int query(int no, int i, int j, int a, int b){
		flush(no, i, j) ; 
		if(b < i || a > j) return 0 ; 
		if(a <= i && b >= j) return tree[no].rest0 ; 
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 
	}

} Seg ; 

int main(){

	cin >> n >> q ; 

	Seg.build(1, 1, n) ; 
	
	while(q--){
		
		cin >> t >> a >> b ; 
		a++, b++ ; 

		if(t == 0) Seg.upd(1, 1, n, a, b) ; 
		else cout << Seg.query(1, 1, n, a, b) << "\n" ; 
  
	}

}
