#include<bits/stdc++.h>
using namespace std ; 
#define int long long 

const int maxn = 110 ; 

int n, m ; 
int vis[maxn], comp, ciclo ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	vis[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(!vis[a]) dfs(a, v) ; 
		else if(vis[a] == 1) {
			ciclo++; 
		} 
	}

	vis[v] = 2 ; 

}

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			dfs(i, i) ; comp++ ; 
		}
	}

	cout << (ciclo == 1 && comp <= 1 ? "FHTAGN!\n" : "NO\n") ; 

}
