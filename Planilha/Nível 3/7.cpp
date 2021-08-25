#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e3 + 5 ; 

int n, m, k, x, y, dist[maxn][maxn], mark[maxn][maxn] ;

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m ; 
	cin >> k ; 
	
	queue<pair<int,int>> fila ; 

	for(int i = 1 ; i <= k ; i++){
		cin >> x >> y ; 
		fila.push({x, y}) ; 
		mark[x][y] = 1 ; 
	}

	while(!fila.empty()){
		
		int ati = fila.front().first, atj = fila.front().second ; fila.pop() ; 

		for(int i = 0 ; i < 4 ; i++){
			int ti = ati + dx[i], tj = atj + dy[i] ; 
			if(!valid(ti, tj) || mark[ti][tj]) continue ; 
			dist[ti][tj] = dist[ati][atj] + 1 ; 
			fila.push({ti, tj}) ; 
			mark[ti][tj] = 1 ; 
		}

	}

	int respi = 1, respj = 1, mx = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(mx < dist[i][j]){
				mx = dist[i][j] ; 
				respi = i, respj = j ; 
			}
		}
	}

	cout << respi << " " << respj << "\n" ; 

}
