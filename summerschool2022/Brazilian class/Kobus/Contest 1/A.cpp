#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

int n, m, vis[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(vis[a]){
			cout << "NO\n" ; exit(0) ; 
		}
		dfs(a, v) ; 
	}

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; 
		grafo[b].push_back(a) ; 
	}

	if(n - 1 != m){
		cout << "NO\n" ; exit(0) ; 
	}

	dfs(1, 1) ; 

	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			cout << "NO\n" ; 
			exit(0) ; 
		}
	}

	cout << "YES\n" ; 

}
