#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int inf = 1e9 ; 

// acha qtd de invertido p cada vertice fixando 1 como raiz 
// se enraizar tds no caminho de 1 a u mudam
// e queremos saber qts invertidos teremos -> qts 1's tem 
// qtd de 0's fora do caminho + qtd de 1's no caminho 
// qtd tot de 0 - qtd de 0 no caminho + nivel - qtd de 0's 

int n, dist[maxn], nivel[maxn], qtd ; 
vector<pair<int,int>> grafo[maxn] ; 

void dfs(int v, int p){
	
	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		qtd += a.second ; 
		dist[a.first] = dist[v] + a.second ; 
		nivel[a.first] = nivel[v] + 1 ; 
		dfs(a.first, v) ; 
	}

} 

int main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back({b, 0}) ; 
		grafo[b].push_back({a, 1}) ; 
	}

	dfs(1, 1) ; 
	int mn = inf ; 

	for(int i = 1 ; i <= n ; i++){
		mn = min(mn, qtd - dist[i] + nivel[i] - dist[i]) ; 
	}

	cout << mn << "\n" ; 

	for(int i = 1 ; i <= n ; i++){
		if(mn == qtd - dist[i] + nivel[i] - dist[i]) cout << i << " " ; 
	}

	cout << "\n" ; 

}
