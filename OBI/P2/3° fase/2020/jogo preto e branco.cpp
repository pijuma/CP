#include<bits/stdc++.h>

using namespace std ; 

#define ff first
#define ss second 

const int maxn = 10 ; 

int n, m, p, g[maxn][maxn] ;
vector<pair<int, int>> pos, pretas ; 

bool ok(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int fill(int grid[maxn][maxn], int i){

	if(i >= (int) pos.size()) return 0 ; 
	int li = pos[i].ff, col = pos[i].ss ; 
	int b1 = 0, b2 = 0 ; 
	if(grid[li][col] != 0) return b1 ; 
	b1 = fill(grid, i+1) ; // n colocar branca na atual 
	if(grid[li+1][col] != 2 && grid[li][col+1] != 2 && grid[li][col-1] != 2 && grid[li-1][col] != 2){
		grid[li][col] = 2 ; 
		b2 = 1 + fill(grid, i+1) ;
		grid[li][col] = 0 ; 
	} 
	
	return max(b1, b2) ; 

}

int main(){

	cin >> n >> m ; 

	// 1 -> preta, 2 -> branca, 0 -> nd 

	cin >> p ; 

	for(int i = 1, x, y ; i <= p ; i++){
		cin >> x >> y ; 
		g[x][y] = 1 ; 
		pretas.push_back({x, y}) ; 
	}

	for(auto a : pretas){
		if(!g[a.ff+1][a.ss] && ok(a.ff+1, a.ss)) pos.push_back({a.ff+1, a.ss}) ; 
		if(!g[a.ff][a.ss+1] && ok(a.ff, a.ss+1)) pos.push_back({a.ff, a.ss+1}) ; 
		if(!g[a.ff-1][a.ss] && ok(a.ff-1, a.ss)) pos.push_back({a.ff-1, a.ss}) ; 
		if(!g[a.ff][a.ss-1] && ok(a.ff, a.ss-1)) pos.push_back({a.ff, a.ss-1}) ;  
	}

	cout << fill(g, 0) << "\n" ;

}
