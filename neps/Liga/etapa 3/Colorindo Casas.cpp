#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, cor[maxn], a, b, c1, vis[maxn], c0 ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	for(auto a : grafo[v]){
		if(a == p) continue ; 
		cor[a] = 1 - cor[v] ; 
		dfs(a, v) ; 
	}
}

bool check(){
	for(int i = 1 ; i <= n ; i++){
		for(int a : grafo[i]){
			if(cor[a] == cor[i]) return false ; 
			if(cor[a] && vis[a] == 0) c1++, vis[a] = 1 ; 
			else if(vis[a] == 0) c0++, vis[a] = 1 ; 
		}
	}
	return c0 == c1 ; 
}

int main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) cor[i] = -1 ; 

	bool ok = 1 ; 

	cor[1] = 0 ; 
	dfs(1, 1) ; 

	cout << (check() ? "Y\n" : "N\n") ; 

}
