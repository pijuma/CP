#include<bits/stdc++.h> 
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1) 
using namespace std ;

const int maxn = 1e5 + 5 ; 

int n, v[maxn], t, ct ; 
int tree[4*maxn], tree2[4*maxn] ; 

struct SEG{

	void build(int no, int i, int j){
		if(i > j) return ; 
		if(i == j){
			tree[no] = v[i] ; 
			tree2[no] = v[i] ; 
			return ; 
		}
		build(esq, i, meio), build(dir, meio + 1, j) ;
		tree[no] = tree[esq] + tree[dir] ; 
		tree2[no] = max(tree2[esq], tree2[dir]) ; 
	}

	void upd(int no, int i, int j, int a, int b){

		if(a > j || b < i || i > j) return ; 
		if(tree2[no] == 1) return ; 
		if(a <= i && b >= j && i == j){
			tree[no] = sqrt(tree[no]) ; 
			tree2[no] = tree[no] ; 
			return ; 
		}

		upd(esq, i, meio, a, b), upd(dir, meio + 1, j, a, b) ; 

		tree[no] = tree[esq] + tree[dir] ; 
		tree2[no] = max(tree2[esq], tree2[dir]) ;  
	}

	int query(int no, int i, int j, int a, int b){

		if(a > j || b < i || i > j) return 0 ; 
		if(a <= i && b >= j) return tree[no] ; 
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 


	}

} Seg ; 

int32_t main(){

	// ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	while(scanf("%lld", &n) != EOF){

		memset(tree, 0, sizeof tree) ; memset(tree2, 0, sizeof tree2) ; 

		for(int i = 1 ; i <= n ; i++) scanf("%lld", &v[i]) ; 

		Seg.build(1, 1, n) ; 

	    cin >> t ; 

	    cout << "Case #" << ++ct << ":\n" ; 
	    while(t--){
	    	int l, r, ty ; 
	    	scanf("%lld%lld%lld",&ty, &l, &r) ; 
	    	if(l > r) swap(l, r) ; 
	    	if(ty == 0) Seg.upd(1, 1, n, l, r) ; 
	    	else printf("%lld\n", Seg.query(1, 1, n, l, r)) ;
	    }

	    printf("\n") ;

	}

} 
