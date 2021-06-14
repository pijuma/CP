#include<bits/stdc++.h>
using namespace std ; 

const int inf = 1e9 ; 
const int maxn = 550 ; 

int n, a, b, c, q, m, dist[maxn][maxn] ; 

int main(){

	cin >> n >> m >> q ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			dist[i][j] = inf ; 
		}
	}

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ; 
		dist[a][b] = min(dist[a][b], c) ; 
		dist[b][a] = min(dist[b][a], c) ; 
	}

	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){ // ir de i p j passando por k 
			for(int j = 1 ; j <= n ; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ; 
			}
		}
	}

	for(int i = 1 ; i <= q ; i++){
		cin >> a >> b ; 
		cout << dist[a][b] << "\n" ; 
	}

}