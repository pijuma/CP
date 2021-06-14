#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

struct aresta{
	int a, b, peso ; 
} ; 

int pai[maxn], peso[maxn] ; 

struct DSU{

	int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ; 
		if(peso[a] > peso[b]) swap(a, b) ; 
		pai[a] = b ; 
		peso[b] += peso[a] ; 
	}

} dsu ; 

aresta grafo[maxn], resp[maxn] ; 
int n, m, pes ; 

bool cmp(aresta a, aresta b){ return a.peso < b.peso ; }

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++) cin >> grafo[i].a >> grafo[i].b >> grafo[i].peso ; 

	for(int i = 1 ; i <= n ; i++) pai[i] = i ; 

	sort(grafo + 1, grafo + 1 + m, cmp) ;

    int sz = 0 ; 

    for(int i = 1 ; i <= m ; i++){
    	if(dsu.find(grafo[i].a) == dsu.find(grafo[i].b)) continue ; 
    	dsu.join(grafo[i].a, grafo[i].b) ; 
    	resp[++sz] = grafo[i] ; 
    }

    for(int i = 1 ; i < n ; i++) pes += resp[i].peso ; 

}