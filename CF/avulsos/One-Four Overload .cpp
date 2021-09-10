#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 550 ;

int n, m, a[maxn][maxn] ; 
char g[maxn][maxn] ; 

// se uma marcada tiver apenas 1 ou 3 adjascentes n tem como 
// se tiver duas - 14
// se tiver 4 - 14 14 

int dx[4] = {0, 0, -1, 1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> g[i][j] ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			
			if(g[i][j] == '.') continue ;
			int ct = 0 ; 
			
			for(int k = 0 ; k < 4 ; k++){
				if(!valid(i + dx[k], j + dy[k]) || g[i+dx[k]][j+dy[k]] == 'X') continue ; 
				ct++ ; 
			} 

			if(ct&1) cout << "NO\n", exit(0) ; 

		}
	}

	int qtd = 0 ; 

	for(int i = 1 ; i <= n ; i++){ // 11111 4###4 -> # muda - paridade (i+qtd#) - par - 1 imp - 4 
		for(int j = 1 ; j <= m ; j++){
			if(g[i][j] == '.') a[i][j] = ((i+qtd)%2 != 0 ? 4 : 1) ;
			else if(g[i-1][j] == 'X') qtd++ ;  
		}
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			
			if(g[i][j] == '.') continue ;
			
			for(int k = 0 ; k < 4 ; k++){
				if(!valid(i + dx[k], j + dy[k]) || g[i+dx[k]][j+dy[k]] == 'X') continue ; 
				a[i][j] += a[i+dx[k]][j+dy[k]] ; 
			} 

		}

	}

	cout << "YES\n" ;
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cout << a[i][j] << " " ; 
		}
		cout << "\n" ; 
	}

}
