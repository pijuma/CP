#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 255 ; 
//ov - k 
int n, m, ov, lo, so, sl, vis[maxn][maxn] ;
char ma[maxn][maxn] ; 

int vx[4] = {0, 0, 1, -1} ; 
int vy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && ma[i][j] != '#' ; }

void bfs(int i, int j){

	// cout << i << " " << j << "\n" ; 

	queue<pair<int,int>> fila ; 
	vis[i][j] = 1 ; 
	fila.push({i, j}) ; 
	if(ma[i][j] == 'k') ov++ ; 
	else if(ma[i][j] == 'v') lo++ ;

	while(!fila.empty()){
		
		int atx = fila.front().first, aty = fila.front().second ; 

		fila.pop() ; 

		for(int i = 0 ; i < 4 ; i++){
			
			int tx = vx[i] + atx, ty = vy[i] + aty ; 

			if(!valid(tx, ty) || vis[tx][ty]) continue ; 

			vis[tx][ty] = 1 ; 
			fila.push({tx, ty}) ; 

			if(ma[tx][ty] == 'k') ov++ ; 
			else if(ma[tx][ty] == 'v') lo++ ; 

		}

	}

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> ma[i][j] ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			lo = ov = 0 ; 
			if(!vis[i][j] && ma[i][j] != '#') bfs(i, j) ; 
			if(ov > lo) so += ov ; 
			else sl += lo ; 
		}
	}

	cout << so << " " << sl << "\n" ; 

}
