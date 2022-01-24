#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, t, m, sz[maxn], vis[maxn], ways, cmp ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 
	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		dfs(a, v) ; 
		sz[v] += sz[a] ; 
	}

}

int32_t main(){

	cin >> t ; 

	while(t--){

		cin >> n >> m ; 

		ways = 1, cmp = 0 ; 

		for(int i = 1 ; i <= n ; i++) grafo[i].clear(), vis[i] = 0 ; 

		for(int i = 1 ; i <= m ; i++){
			int a, b ; 
			cin >> a >> b ; 
			grafo[a].push_back(b) ; grafo[b].push_back(a) ;  
		}

		for(int i = 1 ; i <= n ; i++){
			if(!vis[i]){
				dfs(i, i) ; 
				cmp++ ; 
				ways = (ways*sz[i])%mod ; 
			}
		}

		cout << cmp << " " << ways << "\n" ; 

	}

}
