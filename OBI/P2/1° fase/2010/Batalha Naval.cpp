#include<bits/stdc++.h>
using namespace std ;

const int maxn = 105 ; 
const int inf = 1e9 ; 

int dist[maxn][maxn], n, m, c, d, l ;
char g[maxn][maxn] ;
bool ok[maxn][maxn], used[maxn][maxn] ;

int dx[4] = {0, 0, -1, 1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && g[i][j] == '#' ; }

bool bfs(int i, int j){
	//pegar tds as # e adjs e checar se tem alguma em q !ok
	queue<pair<int,int>> fila ; 

	fila.push({i, j}) ; 
	dist[i][j] = 0 ; 
	used[i][j] = 1 ; 

	bool nice = 1 ; 

	while (!fila.empty()) {

		int x = fila.front().first, y = fila.front().second ;
		fila.pop() ; 

		if(!ok[x][y]) nice = 0 ; 

		for(int k = 0 ; k < 4 ; k++){
			int fx = dx[k] + x, fy = dy[k] + y ; 
			if(valid(fx, fy) && dist[fx][fy] > dist[x][y] + 1){
				dist[fx][fy] = dist[x][y] + 1 ; 
				used[fx][fy] = 1 ;
				fila.push({fx, fy}) ; 
			}
		}

	}

	return nice ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> g[i][j], dist[i][j] = inf, used[i][j] = 0 ; 
		}
	}

	cin >> d ; 

	for(int i = 1 ; i <= d ; i++){
		cin >> l >> c ; 
		ok[l][c] = 1 ; 
	}

	int ans = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(g[i][j] == '#' && !used[i][j]) ans += bfs(i, j) ; 
		}
	}

	cout << ans << "\n" ; 
	
}
