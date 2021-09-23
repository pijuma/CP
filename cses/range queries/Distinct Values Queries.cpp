#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
 
using namespace std ; 
 
const int maxn = 2e5 + 15 ; 
 
struct Q{
	int l, r, id ; 
} ; 
 
bool cmp(Q a, Q b){ return a.r < b.r ; }
 
int n, qq, v[maxn], last[maxn], ans[maxn] ; 
int tree[4*maxn] ; 
Q q[maxn] ; 
map<int,int> mp ;
 
struct SEG{
 
	void upd(int no, int i, int j, int pos, int v){
		if(i == j){
			tree[no] += v ; 
			return ; 
		}
		if(pos <= meio) upd(esq, i, meio, pos, v) ; 
		else upd(dir, meio + 1, j, pos, v) ; 
		tree[no] = tree[esq] + tree[dir] ; 
	}
 
	int query(int no, int i, int j, int a, int b){
		if(i > b || j < a) return 0 ; 
		if(a <= i && b >= j) return tree[no] ; 
		return query(esq, i, meio, a, b) + query(dir, meio + 1, j, a, b) ; 
	}
 
} seg ; 
 
int32_t main(){
 
	cin >> n >> qq ; 
 
	int c = 1 ; 
 
	for(int i = 1 ; i <= n ; i++){
		cin >> v[i] ; 
		if(mp.find(v[i]) == mp.end()) mp[v[i]] = c++ ;
		v[i] = mp[v[i]] ; 
	} 
 
	for(int i = 1 ; i <= qq ; i++){
		int l, r, id ; 
		cin >> l >> r ; 
		q[i] = {l, r, i} ; 
	}
 
	sort(q + 1, q + qq + 1, cmp) ; 
 
	// for(int i = 1 ; i <= qq ; i++) cout << q[i].id << "\n" ; 
 
	int rx = 1 ; 
 
	for(int i = 1 ; i <= n ; i++) last[v[i]] = -1 ; 
 
	for(int i = 1 ; i <= qq ; i++){
		int l = q[i].l, r = q[i].r ; 
		while(rx <= r){ 
			if(last[v[rx]] != -1){
				seg.upd(1, 1, n, last[v[rx]], -1) ; 
			}
			seg.upd(1, 1, n, rx, 1) ;
			last[v[rx]] = rx ; 
			rx++ ; 
		}
		ans[q[i].id] = seg.query(1, 1, n, l, r) ;
	}
 
	for(int i = 1 ; i <= qq ; i++) cout << ans[i] << "\n" ; 
 
}
