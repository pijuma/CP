#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// dijkstra 

const int maxn = 2e5 + 5 ; 
const int mod = 1e9 + 7 ; 
const int inf = 1e18 ; 

int n, m, dist[maxn], menor[maxn], maior[maxn], qtd[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 

void dij(int v){

	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
	fila.push({0, v}) ;

	dist[v] = 0, qtd[v] = 1 ; 

	while(!fila.empty()){
		
		int at = fila.top().second, d = fila.top().first ; fila.pop() ; 
		if(d > dist[at]) continue ; 

		for(auto a : grafo[at]){

			if(dist[a.first] == dist[at] + a.second){
				menor[a.first] = min(menor[a.first], menor[at] + 1) ; 
				maior[a.first] = max(maior[a.first], maior[at] + 1) ; 
				qtd[a.first] = (qtd[a.first] + qtd[at])%mod ; 
			}

			if(dist[a.first] > dist[at] + a.second){
				dist[a.first] = dist[at] + a.second ; 
				menor[a.first] = menor[at] + 1, maior[a.first] = maior[at] + 1 ; 
				qtd[a.first] = qtd[at] ; 
				fila.push({dist[a.first], a.first}) ; 
			}

		}

	}  

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){

		int a, b, c ; 
		cin >> a >> b >> c ; 

		grafo[a].push_back({b, c}) ; 
	}

	dij(1) ; 

	cout << dist[n] << " " << qtd[n] << " " << menor[n] << " " << maior[n] << "\n" ; 

}
