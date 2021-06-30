#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, sz[maxn], f ; 
bool mark[maxn], ok ; 
vector<int> grafo[maxn], grafoc[maxn] ; 

void dfs(int v, int p){
	sz[v] = 1 ; 
	for(auto a : grafo[v]){
		if(a == p || mark[a]) continue ; 
		dfs(a, v) ; 
		sz[v] += sz[a] ;
	}
}

int find_cent(int v, int p, int qtd){
	for(auto a : grafo[v]){
		if(mark[a] || a == p || 2*sz[a] <= qtd) continue ; 
		return find_cent(a, v, qtd) ; 
	}
	return v ; 
}

void make_a(int v, int p){
     
     dfs(v, p) ; 

     int c = find_cent(v, p, sz[v]) ; 
     if(!ok) f = c, ok = 1 ; 
     mark[c] = 1 ;

     for(auto a : grafo[c]){
     	if(mark[a] || a == p) continue ; 
     	make_a(a, c) ; 
     } 

}

int main(){

	cin >> n ; 

	for(int i = 1, a, b ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	make_a(1, 1) ; 

	cout << f << "\n" ; 

}
