#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

const int maxn = 1e5 + 5 ; 

int n, t, q, lazy[4*maxn], tree[4*maxn] ; 

struct SEG{

	void flush(int no, int i, int j){
		
		if(lazy[no] == 0) return ;
		
		tree[no] += (j-i+1)*lazy[no] ; 

		if(i != j){
			lazy[esq] += lazy[no] ; 
			lazy[dir] += lazy[no] ; 
		}

		lazy[no] = 0 ; 

	}

	void upd(int no, int i, int j, int a, int b, int v){
		flush(no, i, j) ; 
		if(b < i || a > j) return ; 
		if(a <= i && b >= j){
			lazy[no] += v ; 
			flush(no, i, j) ;
			return ; 
		}
		upd(esq, i, meio, a, b, v), upd(dir, meio + 1, j, a, b, v) ; 
		tree[no] = (tree[esq] + tree[dir]) ; 
	 
	}

	int query(int no, int i, int j, int a, int b){
		flush(no, i, j) ; 
		if(b < i || a > j) return 0 ; 
		if(a <= i && b >= j) return tree[no] ; 
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 
	}

} Seg ; 


int32_t main(){

	cin >> t ; 

	while(t--){

		int c ; 

		cin >> n >> c ; 

		memset(tree, 0, sizeof tree) ; memset(lazy, 0, sizeof lazy) ; 

		while(c--){

			int t, p, q, v ; 

			cin >> t ; 

			if(t == 0){
				cin >> p >> q >> v ; 
				Seg.upd(1, 1, n, p, q, v) ;  
			} 

			else{
				cin >> p >> q ; 
				cout << Seg.query(1, 1, n, p, q) << "\n" ; 
			}

		}

	}

}
