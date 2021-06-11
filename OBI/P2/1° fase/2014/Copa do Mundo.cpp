#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

struct aresta{
	int peso, a, b ; 
} ;

aresta grafo[maxn], grafor[maxn], mst[maxn] ; 
int n, f, r ; 
int pai[maxn], peso[maxn] ; 

struct DSU{

	int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ;  
		if(peso[a] > peso[b]) swap(a, b) ; 
		pai[a] = b ; 
		peso[b] += peso[a] ; 
	}

} dsu ; 

bool cmp(aresta a, aresta b){ return a.peso < b.peso ; }

int main(){

	cin >> n >> f >> r ; 

	for(int i = 1 ; i <= n ; i++) pai[i] = i, peso[i] = 1 ; 

	for(int i = 1 ; i <= f ; i++) cin >> grafo[i].a >> grafo[i].b >> grafo[i].peso ; 

	for(int i = 1 ; i <= r ; i++) cin >> grafor[i].a >> grafor[i].b >> grafor[i].peso ; 

	sort(grafo + 1, grafo + 1 + f, cmp), sort(grafor + 1, grafor + 1 + r, cmp) ; 

	int t = 0 ; 

	for(int i = 1 ; i <= f ; i++){
		if(dsu.find(grafo[i].a) != dsu.find(grafo[i].b)){
			dsu.join(grafo[i].a, grafo[i].b) ; 
			mst[++t] = grafo[i] ; 
		}
	}

	for(int i = 1 ; i <= r ; i++){
		if(dsu.find(grafor[i].a) != dsu.find(grafor[i].b)){
			dsu.join(grafor[i].a, grafor[i].b) ; 
			mst[++t] = grafor[i] ; 
		}
	}

	int peso = 0 ; 

	for(int i = 1 ; i < n ; i++) peso += mst[i].peso ; 

	cout << peso << "\n" ; 

}
