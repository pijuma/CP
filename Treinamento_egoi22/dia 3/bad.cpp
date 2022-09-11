// https://dmoj.ca/problem/dmopc17c2p3
// n nós - arvore
// estao em x e querem ir pra y 
// qual a menor dist que ele precisa passar de um coelho pra ir de x pra y?
// bfs mult - menor dist de cada vertice p um coelho 
// bb + dfs ? 
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int inf = 1e9 + 5 ; 

int n, r, v[maxn], x, y, dist[maxn], vis[maxn] ; 
vector<int> grafo[maxn] ; 

bool dfs(int v, int p, int fim, int cant){

	if(dist[v] < cant) return 0 ; 
	if(v == fim) return 1 ; 

	bool ok = 0 ; 

	for(auto a : grafo[v]){
		if(a == p || dist[a] < cant) continue ; 
		ok |= dfs(a, v, fim, cant) ; 
	}

	return ok ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> r ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	queue<int> fila ; 

	for(int i = 1 ; i <= n ; i++) dist[i] = inf ;

	for(int i = 1 ; i <= r ; i++){
		int a ; cin >> a ; 
		fila.push(a) ; dist[a] = 0 ; 
	}

	cin >> x >> y ; 

	while(!fila.empty()){
		int at = fila.front() ; fila.pop() ; 
		for(auto a : grafo[at]){
			if(dist[a] > dist[at] + 1) fila.push(a) ; 
			dist[a] = min(dist[a], dist[at] + 1) ; 
		}
	}

	int ini = 0, fim = inf, mid, best = 0 ; 

	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		if(dfs(x, x, y, mid)) best = mid, ini = mid + 1 ; 
		else fim = mid - 1 ; 
	}

	cout << best << "\n" ; 

}
