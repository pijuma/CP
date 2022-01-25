#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 
const int inf = 1e9 ; 

int t, n, m, dist[maxn][maxn], dist_fire[maxn][maxn], ti, tj, col, lin ; 
char g[maxn][maxn] ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= lin && j <= col && g[i][j] != '#' ; }

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> t ; 

	while(t--){

		cin >> col >> lin ; 

		queue<pair<int,int>> fila, fila_fire ; 

 		for(int i = 1 ; i <= lin ; i++){
			for(int j = 1 ; j <= col ; j++){
				dist_fire[i][j] = dist[i][j] = inf ; 
				cin >> g[i][j] ; 
				if(g[i][j] == '@') dist[i][j] = 0, fila.push({i, j}) ; 
				if(g[i][j] == '*') dist_fire[i][j] = 0, fila_fire.push({i, j}) ; 
			}
		}

		while(!fila_fire.empty()){ // menor time do fogo p cda casa
			int xi = fila_fire.front().first, xj = fila_fire.front().second ; 
			fila_fire.pop() ; 
			for(int i = 0 ; i < 4 ; i++){
				int yi = xi + dx[i], yj = xj + dy[i] ; 
				if(!valid(yi, yj)) continue ;
				if(dist_fire[yi][yj] < dist_fire[xi][xj] + 1) continue ; 
				dist_fire[yi][yj] = dist_fire[xi][xj] + 1 ;
				fila_fire.push({yi, yj}) ; 
			}
		}

		// for(int i = 1 ; i <= lin ; i++){
		// 	for(int j = 1 ; j <= col ; j++){
		// 		cout << dist_fire[i][j] <<"  " ; 
		// 	}
		// 	cout << "\n" ; 
		// }

		int mn = inf ; 

		while(!fila.empty()){
			int xi = fila.front().first, xj = fila.front().second ; 
			fila.pop() ; 
			
			if(xi == 1 || xi == lin) mn = min(mn, dist[xi][xj]) ; 
			if(xj == 1 || xj == col) mn = min(mn, dist[xi][xj]) ; 

			for(int i = 0 ; i < 4 ; i++){
				int yi = xi + dx[i], yj = xj + dy[i] ; 
				if(!valid(yi, yj)) continue ;
				if(dist[yi][yj] < dist[xi][xj] + 1) continue ;
				if(dist_fire[yi][yj] <= dist[xi][xj] + 1) continue ;  
				dist[yi][yj] = dist[xi][xj] + 1 ;
				fila.push({yi, yj}) ; 
			}
		}

		if(mn == inf) cout << "IMPOSSIBLE\n" ; 
		else cout << mn + 1 << "\n" ; 

	}

}
