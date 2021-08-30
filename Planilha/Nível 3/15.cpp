#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 55 ; 

int n, m, resp, vis[maxn][maxn], ct ; 
char grid[maxn][maxn] ; 

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && grid[i][j] == '#' && !vis[i][j] ; }

void dfs(int i, int j){
	ct++ ; 
	vis[i][j] = 1 ; 
	for(int k = 0 ; k < 4 ; k++){
		if(valid(i + dx[k], j + dy[k])) dfs(i+dx[k], j+dy[k]) ; 
	}
}

bool calc(){

	memset(vis, 0, sizeof vis) ; 

	int k = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(!vis[i][j] && grid[i][j] == '#') dfs(i, j), k++ ; 
		}
	}

	return k > 1 ; 

}

int main(){

	cin >> n >> m ;

	int qtd = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> grid[i][j] ; 
			if(grid[i][j] == '#') qtd++ ; 
		}
	}
	
	if(qtd < 3) cout << "-1\n", exit(0) ; 

	for(int i = 1 ; i <= n ; i++){
		
		for(int j = 1 ; j <= m ; j++){
			if(grid[i][j] == '.') continue ; 
			grid[i][j] = '.' ; 
			if(calc()) cout << "1\n", exit(0) ;  
			grid[i][j] = '#' ; 
		}

	}

	cout << "2\n" ; 

}
