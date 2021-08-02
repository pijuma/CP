#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 3e4 + 5 ; 
const int inf = 1e9 + 3 ; 

// tem q ir de E a S gastando o menos possivel e sem parar
// semaforos nas ruas podem abrir em multiplos de 3 ou fehar em multiplos 
// 1 - abre nos mutiplos de 3 
// 0 - fecha nos multiplos de 3 
// impossivel - * 
// chegar em um tempo dif pode dar uma resp diferente ent n sign um "ciclo inutil"
// agr chegar c um tempo maior dando o msm resultado de resto eh um ciclo pois n vai mudar e tornar bom 
// os possiveis restos são 0, 1 e 2 

int n, e, s, m, a, b, t, dist[maxn][3], mark[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 

int main(){

	cin >> n >> e >> s >> m ; 

	for(int i = 1 ; i <= m ; i++){

		cin >> a >> b >> t ; 

		grafo[a].push_back({b, t}) ;

	}

	for(int i = 0 ; i <= n ; i++) dist[i][0] = inf, dist[i][2] = inf, dist[i][1] = inf ; 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
	fila.push({0, e}) ; 
	dist[e][0] = 0 ; 

	while(!fila.empty()){

		int at = fila.top().second, tempo = fila.top().first ; fila.pop() ; 

		if(at == s) break ; 

		for(auto a : grafo[at]){

			if(dist[a.first][((tempo+1)%3)] < dist[at][tempo%3] + 1) continue ; 

			if(a.second == 1){ // abre nos multiplos 

				if(tempo%3 == 0){
					dist[a.first][(tempo+1)%3] = dist[at][tempo%3] + 1 ; 
					fila.push({dist[a.first][(tempo+1)%3], a.first}) ; 
				}

			}

			else{

				if(tempo%3){
					
					dist[a.first][(tempo+1)%3] = dist[at][tempo%3] + 1; 
					fila.push({dist[a.first][(tempo+1)%3], a.first}) ;

				}

			}

		}

	}

	int d = min({dist[s][0], dist[s][1], dist[s][2]}) ; 

	if(d == inf) cout << "*\n" ; 
	else cout << d << "\n" ; 

}
