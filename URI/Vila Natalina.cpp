#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 

struct P{
	int x, y ; 
} ; 

int n, t, k, ans ; 
int pai[maxn], sz[maxn] ; 
P c[maxn] ; 

struct aresta{
	int a, b, pes ; 
} ;

aresta ar[maxn*maxn] ; 

struct DSU{

	int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ; 
		if(sz[a] < sz[b]) swap(a, b) ; 
		sz[a] += sz[b] ; 
		pai[b] = a ; 
	}

} dsu ; 

bool cmp(aresta a, aresta b){ return a.pes < b.pes ; }

int32_t main(){

	cin >> t ; 

	while(t--){

		cin >> n >> k ; 

		for(int i = 1 ; i <= n ; i++) cin >> c[i].x >> c[i].y ; 

		for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ;

		int qtd = 0 ; 

		for(int i = 1 ; i <= n ; i++){
			
			for(int j = 1 ; j <= n ; j++){
				if(i == j) continue ; 
				int a = abs(c[i].x - c[j].x) ; 
				int b = abs(c[i].y - c[j].y) ;
				int peso ;  
		        peso = __gcd(a, b) - 1 ; 
				ar[qtd++] = {i, j, peso} ; 
			}

		}

		ans = 0 ; 

		sort(ar, ar + qtd - 1, cmp) ; 

		for(int i = 0 ; i < qtd ; i++){
			if(dsu.find(ar[i].a) == dsu.find(ar[i].b)) continue ; 
			ans += ar[i].pes ; 
			dsu.join(ar[i].a, ar[i].b) ; 
		}

		cout << ans*k << "\n" ; 

	}

}
