#include<bits/stdc++.h>
using namespace std ; 
 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define ll long long 
 
const int maxn = 2e5 +  5 ; 
 
ll n, q, v[maxn] ; 
ll tree[4*maxn] ; 
 
struct SEG{
 
	void build(int no, int i, int j){
		if(i == j){
			tree[no] = v[i] ;
			return ;  
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = tree[esq]^tree[dir] ; 
	}
 
	ll query(int no, int i, int j, int a, int b){
		if(a > j || b < i) return 0 ; 
		if(a <= i && b >= j) return tree[no] ;
		return query(esq, i, meio, a, b)^query(dir, meio + 1, j, a, b) ;  
	}
 
} seg ; 
 
int main(){ 
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> q ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	seg.build(1, 1, n) ; 
 
    for(int i = 1, a, b; i <= q ; i++){
    	cin >> a >> b ; 
    	cout << seg.query(1, 1, n, a, b) << "\n" ; 
    }
 
}
