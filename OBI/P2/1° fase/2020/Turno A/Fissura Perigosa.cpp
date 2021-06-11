#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 510 ; 

int n, f, grid[maxn][maxn] ; 

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= n && grid[i][j] <= f ; }

void bfs(){

	queue<pair<int,int>> fila ; 
	fila.push({1, 1}) ; 
	grid[1][1] = 14 ; 
	while(!fila.empty()){
		
		int ti = fila.front().first, tj = fila.front().second ; fila.pop() ;

		for(int i = 0 ; i < 4 ; i++){
			int di = dx[i] + ti, dj = dy[i] + tj ; 
			if(!valid(di, dj)) continue ; 
			fila.push({di, dj}) ; 
			grid[di][dj] = 14 ; 
		}

	}

}

int main(){

	cin >> n >> f ; 

	string p ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> p ; 
		for(int j = 0 ; j < p.size() ; j++){
			grid[i][j+1] = p[j] - '0' ; 
		}
	}

	if(grid[1][1] <= f) bfs() ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(grid[i][j] > 9) cout << '*' ; 
			else cout << grid[i][j] ; 
		}
		cout << "\n" ; 
	}

}
