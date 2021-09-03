#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std ; 

// qual a dist de cada carinha dos k's p cada casa (bfs 0 1) dist[k][i][j]
// qual a menor dist de cada cara p uma saida (bfs 0 1) começando de tds as saidas possiveis 
// pd pegar um sair pegar outro -> dist[pa][pb] + dist[pc][pd]
// ou pode pegar um ir até o outro e sair 
// testa tds i, j como parada p ir de 0 a 1 
// dai tenta minimizar com dist_k[0] + dist_k[1] + dist[i][j] - (grid[i][j] == '#' ? 2 : 0) 
// dist_k é a dist de k p i, j

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

const int maxk = 110 ; 
const ll inf = 1e18 ; 

int n, m, k ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m >> k ; 
	int nn = n + 3, mm = m + 3, kk = k + 3 ; 
	int grid[nn][mm] ; 
	pii especial[kk] ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			char c ; 
			cin >> c ; 
			grid[i][j] = (c == '#') ; 
		}
	}

	ll dist[kk][nn][mm], dist_fora[nn][mm] ; 

	memset(dist, 0, sizeof dist) ; 

	for(int i = 1 ; i <= k ; i++) cin >> especial[i].first >> especial[i].second ;  

	for(int i = 1 ; i <= k ; i++){
		
		deque<pair<pii, ll>> fila ; 
		bool vis[nn][mm] ;
		memset(vis, 0, sizeof vis) ; 
		fila.push_front({especial[i], 0}) ; 

		while(!fila.empty()){
			
			pii at = fila.front().first ; ll d = fila.front().second ; 
			fila.pop_front() ;

			if(vis[at.first][at.second]) continue ; 
			vis[at.first][at.second] = 1 ;
			dist[i][at.first][at.second] = d ; 

			for(int i = 0 ; i < 4 ; i++){
				
				int ati = at.first + dx[i], atj = at.second + dy[i] ; 
				if(!valid(ati, atj)) continue ; 

				if(grid[ati][atj]) fila.push_back({{ati, atj}, d+1}) ; 

				else fila.push_front({{ati, atj}, d}) ;  

			}

		}

	}

	deque<pair<pii, ll>> fila ; 

	memset(dist_fora, 0, sizeof dist_fora) ; 

	for(int i = 0 ; i <= n + 1 ; i++) fila.push_back({{i, 0}, 0}), fila.push_back({{i, m+1}, 0}) ;
	for(int j = 0 ; j <= m + 1 ; j++) fila.push_back({{0, j}, 0}), fila.push_back({{n+1, j}, 0}) ;   

	bool vis[nn][mm] ; 
    memset(vis, 0, sizeof vis) ;

	while(!fila.empty()){
		
		pii at = fila.front().first ; ll d = fila.front().second ; 
		fila.pop_front() ;

		if(valid(at.first, at.second)){
			if(vis[at.first][at.second]) continue ; 
			vis[at.first][at.second] = 1 ; 
			dist_fora[at.first][at.second] = d ; 
		}

		for(int i = 0 ; i < 4 ; i++){
			
			int ati = at.first + dx[i], atj = at.second + dy[i] ; 
			if(!valid(ati, atj)) continue ; 
			
			if(grid[ati][atj]) fila.push_back({{ati, atj}, d + 1}) ; 
			
			else fila.push_front({{ati, atj}, d}) ; 

		}

	}

	ll best = inf ; 

	for(int i = 1 ; i <= k ; i++){ // ir até 1 voltar dps ir ao outro 
		for(int j = i + 1 ; j <= k ; j++){
			best = min(best, dist_fora[especial[i].first][especial[i].second] + dist_fora[especial[j].first][especial[j].second]) ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){ // fixa pos de troca
		for(int j = 1 ; j <= m ; j++){
			
			ll dist_k[kk] ; 
			memset(dist_k, 0, sizeof dist_k) ; 

			for(int f = 1 ; f <= k ; f++) dist_k[f] = dist[f][i][j] ; 

			sort(dist_k + 1, dist_k + 1 + k) ; // pega os 2 mais proximos de i, j (resto n vale a pena)

		    ll d = dist_k[1] + dist_k[2] + dist_fora[i][j] ;
		    if(grid[i][j]) d -= 2 ;  

		    best = min(best, d) ; 
		}
	}

	cout << best << "\n" ; 

}
