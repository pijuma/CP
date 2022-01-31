#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, vis[maxn] ; 
char ans[maxn] ; 
int sz[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		dfs(a, v) ; 
		sz[v] += sz[a] ; 
	}

}

int centroid(int v, int p, int szz){

	for(auto a : grafo[v]){
		if(a == p || vis[a] || 2*sz[a] <= szz) continue ; 
		return centroid(a, v, szz) ; 
	}

	return v ; 

}

void make_a(int v, int p){

	dfs(v, v) ; 
	int c = centroid(v, p, sz[v]) ; 

	vis[c] = 1 ; 

	if(p == 0) ans[c] = 'A' ; 
	else ans[c] = ans[p] + 1 ; 

	for(auto a : grafo[c]){
		if(a == p || vis[a]) continue ; 
		make_a(a, c) ; 
	}

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	make_a(1, 0) ;

	for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 

}
