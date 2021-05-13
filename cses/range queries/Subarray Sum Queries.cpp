#include<bits/stdc++.h>
 
 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
#define ll long long 
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
struct Tree{
	ll ans, pref, suf, sum ; 
} ; 
 
ll v[maxn] ; 
Tree tree[4*maxn] ; 
int n, m ;
 
struct SEG{
 
	Tree join(Tree a, Tree b){
		Tree c ; 
		c.sum = a.sum + b.sum ; 
		c.pref = max(a.pref, a.sum + b.pref) ; 
		c.suf = max(b.suf, b.sum + a.suf) ; 
		c.ans = max({a.ans, b.ans, a.suf + b.pref}) ; 
		return c ; 
	}
 
	void build(int no, int i, int j){
		if(i == j){
			tree[no].ans = tree[no].pref = tree[no].suf = max(0LL, v[i]), tree[no].sum = v[i] ; 
			return ;  
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = join(tree[esq], tree[dir]) ; 
	}
 
	void att(int no, int i, int j, int a, int val){
		
		if(i == j){
			tree[no].ans = tree[no].pref = tree[no].suf = max(0, val), tree[no].sum = val ; 
			v[i] = val ; 
			return ; 
		}
 
		if(a <= meio) att(esq, i, meio, a, val) ; 
		else att(dir, meio + 1, j, a, val) ; 
		
		tree[no] = join(tree[esq], tree[dir]) ; 
 
	}
 
} seg ; 
 
int main(){
	
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	seg.build(1, 1, n) ; 
 
	for(int i = 1, a, b ; i <= m ; i++){
		cin >> a >> b ; 
		seg.att(1, 1, n, a, b) ;
		cout << tree[1].ans << "\n" ; 
	}
 
}
