#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 
int n, diam, dp[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){ 

	for(auto a : grafo[v]){
		if(a == p) continue ;
		dfs(a, v) ;   
		diam = max(diam, dp[a] + dp[v] + 1) ; 
		dp[v] = max(dp[v], dp[a] + 1) ; 
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

	cout << diam << "\n" ; 

}
