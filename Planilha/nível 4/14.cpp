#include<bits/stdc++.h>
using namespace std ; 

// dsu altura 
// dfs p achar o diametro de cada comp inicialmente 
// guarda o menor e o maior lado do diametro 
// qd une pode misturar os maiores ou manter um dos dois (x ou y)

const int maxn = 3e5 + 5 ; 

int n, q, m, sz[maxn], pai[maxn], mark[maxn], ind, dp[maxn], diam ; 
pair<int,int> cam[maxn] ; 
vector<int> grafo[maxn] ; 

struct DSU{

	int find(int a){return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ;  
		if(sz[a] > sz[b]) swap(a, b) ;
		pai[a] = b ; 
		sz[b] += sz[a] ;    
	}

} dsu ;

void dfs(int v, int p){
	
	mark[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p || mark[a]) continue ;
		dfs(a, v) ; 
		diam = max(diam, dp[a] + dp[v] + 1) ; 
		dp[v] = max(dp[v], dp[a] + 1) ;  
	}

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> m >> q ; 

	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
		dsu.join(a, b) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		if(mark[dsu.find(i)]) continue ;
		diam = 0 ;  
		int a = dsu.find(i) ;
		mark[a] = 1 ; 
		dfs(a, a) ;
		cam[a] = {(diam + 1)/2, diam/2} ; 
	}

	for(int i = 1 ; i <= q ; i++){
		
		int t, a, b ;
		cin >> t ; 
		
		if(t == 1){
			cin >> a ;
			a = dsu.find(a) ;
			cout << cam[a].first + cam[a].second << "\n" ;  
		}

		else{
			cin >> a >> b ; 
			a = dsu.find(a), b = dsu.find(b) ;
			if(a == b) continue ; 
			int d = max({cam[a].first + cam[a].second, cam[b].first + cam[b].second, cam[a].first + 1 + cam[b].first}) ; 
			dsu.join(a, b) ; 
			cam[dsu.find(a)] = {(d+1)/2, d/2} ; 
		}

	}

}
