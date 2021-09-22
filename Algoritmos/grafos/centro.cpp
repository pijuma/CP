#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, dist[maxn], dist2[maxn], vis[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		dist[a] = dist[v] + 1 ; 
		dfs(a, v) ; 
	}
}

void dfs2(int v, int p){
	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		dist2[a] = dist2[v] + 1 ; 
		dfs2(a, v) ; 
	}
}

int main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	dfs(1, 1) ; 

	int fim = 0 , mx = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		if(mx < dist[i]) mx = dist[i], fim = i ; 
	}
	
	memset(dist, 0, sizeof dist) ; memset(vis, 0, sizeof vis) ; 
	dfs(fim, fim) ;

	int p2 = 0 ; mx = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		if(mx < dist[i]) mx = dist[i], p2 = i ; 
	}

	int diam = (mx) ; 
	int raio = (diam + 1)/2 ; 

	cout << mx << "\n" ; 
	
	memset(vis, 0, sizeof vis) ; 
	dfs2(p2, p2) ; 

	int cent = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(max(dist[i], dist2[i]) == raio && dist[i] + dist2[i] == diam) cent = i ; 
	}

	cout << cent << "\n" ; 

}
