#include<bits/stdc++.h>

#define int long long 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m ; 
int tree[4*maxn], lazy[4*maxn] ; 

struct SEG{

	void flush(int no, int i, int j){
		if(lazy[no] == 0) return ; 
		tree[no] = (j-i+1) - tree[no] ; 
		if(i != j){
			lazy[esq] ^= 1 ; 
			lazy[dir] ^= 1 ; 
		}
		lazy[no] = 0 ; 
	}

	void upd(int no, int i, int j, int a, int b){
		flush(no, i, j) ; 
		if(i > b || j < a) return ; 
		if(a <= i && b >= j){
			lazy[no] ^= 1 ; 
			flush(no, i, j) ; 
			return ; 
		}
		upd(esq, i, meio, a, b), upd(dir, meio + 1, j, a, b) ; 
		tree[no] = tree[esq] + tree[dir] ; 
	}

	int query(int no, int i, int j, int a, int b){
		flush(no, i, j) ; 
		if(i > b || j < a) return 0 ; 
		if(a <= i && b >= j) return tree[no] ;
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a ,b) ; 
	}

	void see(){
		for(int i = 1 ; i <= 4*n ; i++) cout << i << " " << tree[i] << "\n" ; 

	}

} Seg ;

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		
		int t, a, b ; 
		cin >> t >> a >> b ; 
		
		if(t == 1) cout << Seg.query(1, 1, n, a, b) << "\n" ; 
		else Seg.upd(1, 1, n, a, b) ; 
 

	}

}
