#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e3 + 5 ; 

int n, m[maxn][maxn], dist[maxn][maxn] ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= n ; }

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> m[i][j] ; 
		}
	}

	queue<pair<int,int>> fila ; 
	dist[1][1] = 0 ; 
	fila.push({1, 1}) ; 

	while(!fila.empty()){
		int ti = fila.front().first, tj = fila.front().second ; 
		fila.pop() ; 
		for(int i = 0 ; i < 4 ; i++){
			int ki = ti + dx[i], kj = tj + dy[i] ; 
			if(!valid(ki, kj)) continue ; 
			dist[ki][kj] = dist[ti][tj] + 1 ; 
			fila.push({ki, kj}) ; 
		}
	}

	cout << dist[n][n] << "\n" ; 

}