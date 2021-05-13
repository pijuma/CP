#include<bits/stdc++.h>
using namespace std ; 
 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define ll long long 
 
const int maxn = 2e5 + 5 ; 
 
struct Tree{
	ll pref, sum ; 
} ; 
 
ll n, q, type ;
ll v[maxn] ;
Tree tree[4*maxn] ; 
 
struct SEG{
 
	Tree join(Tree a, Tree b){
		Tree ans ; 
		ans.sum = a.sum + b.sum ; 
		ans.pref = max(a.pref, a.sum + b.pref) ; 
		return ans ; 
	}
 
	void build(int no, int i, int j){
		if(i == j){
			tree[no].pref = max(0LL, v[i]), tree[no].sum = v[i] ;
			return ;  
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = join(tree[esq], tree[dir]) ; 
	}
 
	void att(int no, int i, int j, int a, ll val){
		if(i == j){
			tree[no].pref = max(0LL, val), tree[no].sum = val ; 
			return ; 
		}
		if(a <= meio) att(esq, i, meio, a, val) ; 
		else att(dir, meio + 1, j, a, val) ; 
		tree[no] = join(tree[esq], tree[dir]) ; 
	}
 
	Tree query(int no, int i, int j, int a, int b){
		Tree null ; 
		null.pref = null.sum = 0LL ; 
		if(a > j || b < i) return null ; 
		if(a <= i && b >= j) return tree[no] ; 
		return join(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ; 
	}
 
} seg ; 
 
int main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> q ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	seg.build(1, 1, n) ; 
 
    for(int i = 1, a, b ; i <= q ; i++){
    	
    	cin >> type ; 
    	
    	if(type == 1){
    		int pos, val ; 
    		cin >> pos >> val ;
    		seg.att(1, 1, n, pos, val) ;  
    	}
 
    	else{
    		int a, b ; 
    		cin >> a >> b ; 
    		cout << seg.query(1, 1, n, a, b).pref << "\n" ; 
    	}
 
    }
 
}
