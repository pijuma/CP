#include<bits/stdc++.h>
#define ll long long
#define esq (2*no)
#define dir ((2*no) + 1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 2e5 + 5 ; 

// igual a len1 mas usa uma seg/bit p guardar qts caras tem c o nivel 
// ai qd atualiza ans pega de ((max(0, k1 - nivel), max(0, k2 - nivel))
// att pt nivel (+1)
// pega a arvore de centroid processa os caras somando o nivel 0 (cara cent) 
// processa cada sub ligado ao centroid e soma ans antes de processar ela (conectando com as outras comps)
// add a comp e continua a pegar os centroids

int k1, mark[maxn], k2, mxlvl, n, a, b, sub[maxn] ; 
ll ans, bit[4*maxn] ; 
vector<int> grafo[maxn] ; 

struct BIT{

	void att(int pos, int val){
		for( ; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
	}

	int query(int l, int r){

		ll tot = 0 ; 
		l-- ;

		for( ; r > 0 ; r -=  r&-r) tot += bit[r] ; 
		if(l) for( ; l > 0 ; l -= l&-l) tot -= bit[l] ; 

		return tot ; 
	
	}

} Bit ; 

void dfs(int v, int p){

	sub[v] = 1 ; 

	for(auto a : grafo[v]){
		if(mark[a] || a == p) continue ; 
		dfs(a, v) ; 
		sub[v] += sub[a] ; 
	}

}

int finding_cent(int v, int p, int sz){

	for(auto a : grafo[v]){
		if(mark[a] || a == p || 2*sub[a] <= sz) continue ; 
		return finding_cent(a, v, sz) ; 
	}

	return v ; 

}

void add(int v, int p, bool type, int nivel){
	
	if(nivel > k2) return ; 

	mxlvl = max(mxlvl, nivel) ; 

	if(type) ans += Bit.query(max(1, k1 - nivel + 1), k2 - nivel + 1) ; 
	else Bit.att(nivel + 1, 1) ; 

	for(auto a : grafo[v]){
		if(mark[a] || a == p) continue ; 
		add(a, v, type, nivel + 1) ; 
	}

}

void make_a(int v, int p){
	
	dfs(v, p) ;

	int cent = finding_cent(v, p, sub[v]) ; 

	mxlvl = 0 ;

	mark[cent] = 1 ; 
	Bit.att(1, -Bit.query(1, 1) + 1) ; 

	for(int a : grafo[cent]){
		if(mark[a] || a == p) continue ; 
		add(a, cent, 1, 1) ; 
		add(a, cent, 0, 1) ; 
	}

	for(int i = 1 ; i <= mxlvl ; i++) Bit.att(i + 1, -Bit.query(i + 1, i + 1)) ; 

	for(int a : grafo[cent]){
		if(a == cent || mark[a]) continue ; 
		make_a(a, cent) ; 
	}

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> k1 >> k2 ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	make_a(1, 0) ; 

	cout << ans << "\n" ; 

}
