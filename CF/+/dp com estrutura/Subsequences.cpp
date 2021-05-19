#include<bits/stdc++.h>

#define ll long long 

#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 

ll n, ans, mx, k, v[maxn], a[maxn]; 

ll tree[4*maxn][13], dp[maxn] ; 

struct SEG{

	ll query(int no, int i, int j, int a, int b, int k){ 
    	if(a > j || b < i || a > b) return 0 ; 
    	if(a <= i && b >= j) return tree[no][k] ; 
    	ll l, ans, r ; 
    	l = query(esq, i, meio, a, b, k), r = query(dir, meio + 1, j, a, b, k) ; 
    	return l+r ; 
    }

	void att(int no, int i, int j, int pos){
		if(i == j && i == pos){
			tree[no][0]++ ; 
			for(int g = 1 ; g <= k ; g++) tree[no][g] += query(1, 1, n, 1, j-1, g-1) ; // p formar uma de tam g pego tds as de tam g-1 anteriores
			return ; 
		}

		if(pos <= meio) att(esq, i, meio, pos) ; 
		else att(dir, meio + 1, j, pos) ; 

		for(int g = 0 ; g <= k ; g++) tree[no][g] = tree[esq][g] + tree[dir][g] ; // qts temos de tam g? 

	}

} seg ; 

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++) seg.att(1, 1, n, v[i]) ; //atualiza pelos valores ("ordenado")

	cout << seg.query(1, 1, n, 1, n, k) << "\n" ; //qts seqs com o intervalo de tam k temos?

}
