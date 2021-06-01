#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 550 ; 

int n, m ; 
char g[maxn][maxn] ; 

void dfs(int i, int j){
	g[i][j] = 'o' ; 
	if(i == n) return ; 
	if(g[i+1][j] == '.') dfs(i+1, j) ; 
	if(g[i+1][j] == '#'){
		if(g[i][j+1] == '.') dfs(i, j+1) ; 
		if(g[i][j-1] == '.') dfs(i, j-1) ; 
	}
}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> g[i][j] ; 
		}
	}

	for(int i = 1 ; i <= m ; i++) if(g[1][i] == 'o') dfs(1, i) ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cout << g[i][j] ; 
		}
		cout << "\n" ; 
	}

}
