#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, M, d[maxn][maxn] ; 
int ii, ji, fi, fj,  m[maxn][maxn] ; 

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool ok(int i, int j){ return i > 0 && i <= n && j > 0 && j <= M && m[i][j] != 0 ; }

int main(){

	cin >> n >> M ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= M ; j++){
			cin >> m[i][j] ; 
			if(m[i][j] == 2) ii = i, ji = j ; 
			if(m[i][j] == 3) fi = i, fj = j ; 
		}
	}

	queue<pair<int,int>> fila ; 
	d[ii][ji] = 1 ; 
	fila.push({ii, ji}) ; 

	while(!fila.empty()){
		int iat = fila.front().first, jat = fila.front().second ; 
		fila.pop() ; 
		for(int i = 0 ; i < 4 ; i++){
			int newi = iat + dx[i], newj = jat + dy[i] ; 
			if(d[newi][newj] != 0 || !ok(newi, newj)) continue ; 
			d[newi][newj] = d[iat][jat] + 1 ; 
			fila.push({newi, newj}) ; 
		}
	}

	cout << d[fi][fj] << "\n" ; 

}
