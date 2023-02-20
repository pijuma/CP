// dp com bitset
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e4 + 5 ; 

int n, m, timer, vis[maxn] ; 
vector<int> grafo[maxn] ; 
bitset<maxn> dp[maxn] ; 

void dfs(int v, int p){

	dp[v].reset() ; dp[v].set(v) ;
	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(!vis[a]) dfs(a, v) ; 
		dp[v] |= dp[a] ; 
	} 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		timer++ ;
		dfs(i, i) ; 
		cout << dp[i].count() << " " ;
	}

	cout << "\n" ; 

}
