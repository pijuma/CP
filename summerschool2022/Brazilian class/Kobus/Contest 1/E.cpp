#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, k, tin[maxn], timer, vis[maxn], pai[maxn], tout[maxn], nivel[maxn] ; 
vector<int> grafo[maxn] ; 

bool cmp(int a, int b){return nivel[a] < nivel[b] ; }

void dfs(int v, int p){

	tin[v] = ++timer ; 
	pai[v] = p ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		dfs(a, v) ; 
	}

	tout[v] = timer ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	dfs(1, 1) ; 

	while(m--){
		
		cin >> k ; 
		
		vector<int> vec ; 

		for(int i = 1 ; i <= k ; i++){
			int a ; 
			cin >> a ; 
			a = pai[a] ; 
			vec.push_back(a) ; 
		}

		sort(vec.begin(), vec.end(), cmp) ; 

		bool ok = 1 ; 

		for(int i = 1 ; i < k && ok ; i++){
			int p = vec[i - 1], f = vec[i] ; 
			if(tout[p] >= tout[f] && tin[p] <= tin[f]) continue ; 
			ok = 0 ; 
		}

		cout << (ok ? "YES\n" : "NO\n") ; 

	}

}
