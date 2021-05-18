#include<bits/stdc++.h>

#define meio ((i+j)>>1)
#define esq (2*no)
#define dir ((2*no)+1)

#define ll long long 

using namespace std ; 

//seg min// minq

const int maxn = 1e6 + 5 ; 
const ll inf = 1e18 ; 

ll tree[4*maxn], v[maxn], dp[maxn] ; 
int n, d ; 

struct SEG{

	void att(int no, int i, int j, int pos, ll val){
		if(i == j && i == pos){
			tree[no] = val ;
			return ;  
		} 
		if(pos <= meio) att(esq, i, meio, pos, val) ; 
		else att(dir, meio + 1, j, pos, val) ; 
		tree[no] = min(tree[esq], tree[dir]) ; 
	}

	ll query(int no, int i, int j, int a, int b){
		if(a > j || b < i) return inf ; 
		if(a <= i && b >= j) return tree[no] ; 
		return min(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ; 
	}

} seg ; 

int main(){

	cin >> n >> d ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = n ; i > 0 ; i--){
		dp[i] = v[i] + seg.query(1, 1, n, min(n, i+1), min(n, i+d)) ;
		seg.att(1, 1, n, i, dp[i]) ; 
	}

	cout << dp[1] << "\n" ; 

}
