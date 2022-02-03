#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 2e3 + 5 ; 

int n, p, mx, vis[maxn], dp[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p, int d){

	mx = max(mx, d) ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs(a, v, d+1) ; 
	}

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> p ; 
		if(p != -1) grafo[p].push_back(i) ; 
	}

	for(int i = 1 ; i <= n ; i++) if(!vis[i]) dfs(i, i, 0) ; 

	cout << mx + 1 << "\n" ; 

}
