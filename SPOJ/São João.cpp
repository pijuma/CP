#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

// temos uma arvore 
// inicialmente cada jogador pode percorrer m salas 
// sabendo a sala de inicio queremos saber qual o maior n° salas q podemos percorrer sabendo
// a qtd max de arestas q podemos usar 
// se temos a salas no caminho principal e b salas no secundario 
// iremos usar a + 2b para passar em tds as salas 
// sabendo o diametro 
// teremos 1 + diametro - (m - maior)/2 como resp 
// devemos tomar cuidado p n ficar negativo -> checar se m > maior se n 
// printa 1 + diametro ou o min(diametro, m) + 1
// cout << min(n, min(m+1, diam+1) + max(0, (m-maior)/2))

const int maxn = 1e5 + 5 ; 

int n, dist[4][maxn], q ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p, int turn){
	
	for(auto a : grafo[v]){
		if(a == p || dist[turn][a] > 0) continue ; 
		dist[turn][a] = dist[turn][v] + 1 ; 
		dfs(a, v, turn) ;
	}

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	dfs(1, 1, 1) ; 

	int p1 = 1, mx = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		if(mx < dist[1][i]) mx = dist[1][i], p1 = i ; 
	}

	dfs(p1, p1, 2) ; 

	int p2 = 1 ; mx = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		if(mx < dist[2][i]) mx = dist[2][i], p2 = i ; 
	}

	// cout << p1 << " " << p2 << "\n" ; 

	dfs(p2, p2, 3) ; 

	cin >> q ; 

	while(q--){

		int v, m ; 

		cin >> v >> m ; 

		int diam = max(dist[2][v], dist[3][v]) ; 
		cout << min(n, min(m+1, diam+1) + max(0LL, (m-diam)/(2*1LL))) << "\n" ; 

	}

}
