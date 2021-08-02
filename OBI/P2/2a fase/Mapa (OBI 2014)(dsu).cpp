#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// import - branco - 1

const int maxn = 1e5 + 5 ; 

int n, qtd, sz[maxn], pai[maxn] ; 

struct DSU{

	int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){

		a = find(a), b = find(b) ; 

		if(a == b) return ; 

		if(sz[a] > sz[b]) swap(a, b) ; // a menor 

		pai[a] = b ; 
		sz[b] += sz[a] ; 

	}

} dsu ; 

int32_t main(){

	cin >> n ; 

	qtd = (n*(n-1))/2 ; //-> tds pares possiveis 

	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

	for(int i = 1 ; i < n ; i++){

		int a, b, c ; 

		cin >> a >> b >> c ; 

		if(c == 0) dsu.join(a, b) ; 

	}

	for(int i = 1 ; i <= n ; i++){
		if(pai[i] == i) qtd -= (sz[i]*(sz[i] - 1))>>1 ; 
	}

	cout << qtd << "\n" ; 

}
