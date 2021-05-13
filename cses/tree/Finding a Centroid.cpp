#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, m, sub[maxn], c, d ; 
vector<int> grafo[maxn] ;
 
int centroid(int u, int p, int qtd){
	
	for(int a : grafo[u]){
		if(a == p || sub[a]*2 <= qtd) continue ; 
		return centroid(a, u, qtd) ;
	}
    
    return u ; 
}
 
void dfs(int u, int p){
	
	sub[u] = 1 ; 
	
	for(int a : grafo[u]){
		if(a == p) continue ; 
		dfs(a, u) ; 
		sub[u] += sub[a] ; 
	}
 
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i < n ; i++){
		cin >> c >> d ; 
		grafo[c].push_back(d), grafo[d].push_back(c) ; 
	}
 
	dfs(1, 1) ; 
 
	cout << centroid(1, 1, n) << "\n" ;
 
}
