#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 550 ; 
const int inf = 1e18 ; 

int n, m, dist[maxn][maxn][2] ; 
pair<int,int> pai[maxn][maxn][2] ; 
vector<int> grafo[maxn] ; 

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			dist[i][j][1] = dist[i][j][0] = inf ; 
		}
	}

	// bfs - dist[i][j][t] -> to em i com o 1o em j com o 2o e o 1 ou 2 vai andar 
	// tomar cuidado p n ficar igual 
	// recuperar o caminho 
	
	queue<pair<pair<int,int>,int>> fila ; 

	dist[1][n][0] = 0 ; 
	fila.push({{1, n}, 0}) ; 

	while(!fila.empty()){
		
		int v = fila.front().first.first, u = fila.front().first.second ; 
		int turn = fila.front().second ; 
		
		fila.pop() ; 

		if(turn){
			for(auto a : grafo[u]){
				if(dist[v][a][0] > dist[v][u][1] + 1){
					dist[v][a][0] = dist[v][u][1] + 1 ; 
					pai[v][a][0] = {v, u} ; 
					fila.push({{v, a}, 0}) ; 
				}
			}
		}
		
		else{
			if(v == u) continue ; 
			for(auto a : grafo[v]){
				if(dist[a][u][1] > dist[v][u][0] + 1){
					dist[a][u][1] = dist[v][u][0] + 1 ; 
					pai[a][u][1] = {v, u} ; 
					fila.push({{a, u}, 1}) ; 
				}
			}
		}

	}

	if(dist[n][1][0] == inf) cout << "-1\n", exit(0) ; 

	int v = n, u = 1, turn = 0 ; 

	vector<int> v1, v2 ; 

	while(v){
		if(!turn){
			v2.push_back(v), v1.push_back(u) ; 
		}
		int lv = v ; 
		v = pai[v][u][turn].first, u = pai[lv][u][turn].second ; 
		turn = 1 - turn ; 
	}

	cout << dist[n][1][0]/2 << "\n" ; 

	for(auto a : v1) cout << a << " " ; 
	cout << "\n" ; 
    for(auto a : v2) cout << a << " " ; 
    cout << "\n" ; 

}
