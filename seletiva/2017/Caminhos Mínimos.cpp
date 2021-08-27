#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int, int>
#define pil pair<long long, long long > 
#define ff first 
#define ss second 

using namespace std ;

const int maxn = 1e4 + 5 ; 
const ll INF = 1e18 + 10 ; 
const ll inf = 2e9 + 10 ; 

ll n, m, vis[maxn], cam[maxn], nivel[maxn], dist[maxn] ;
vector< pil > grafo[maxn] ;

void bfs(){

	memset(vis, 0, sizeof vis) ;  
	
	vis[1] = 1 ; 
	nivel[1] = 0 ; 

	queue<int>fila ;
	fila.push(1) ;  

	while(!fila.empty()){

		int att = fila.front() ; 
		fila.pop() ; 

		for(int i = 0 ; i < grafo[att].size() ; i++){
			pil u = grafo[att][i] ; 
			if(vis[u.ss] == 0){
				nivel[u.ss] = nivel[att] + 1 ; 
				vis[u.ss] = 1 ; 
				fila.push(u.ss) ; 
			}
		}
	}

}

void dij(){

	priority_queue< pil, vector< pil >, greater< pil > > fila ; 

	memset(vis, 0, sizeof vis) ; 

	dist[1] = 0 ; 
	cam[1] = 0 ;
	fila.push({0LL, 1}) ;

	while(!fila.empty()){
	
		pil att = fila.top() ; 
		fila.pop() ;
		
		if(vis[att.ss]) continue ;
		vis[att.ss] = 1 ; 

		for(int i = 0 ; i < grafo[att.ss].size() ; i++){

			pil u = grafo[att.ss][i] ;

			if(dist[u.ss] > dist[att.ss] + u.ff){
				dist[u.ss] = dist[att.ss] + u.ff ; 
				fila.push({dist[u.ss], u.ss}) ;
				cam[u.ss] = cam[att.ss] + 1 ; 
			} 

			else if(dist[u.ss] == dist[att.ss] + u.ff){
				cam[u.ss] = min(cam[u.ss], cam[att.ss] + 1) ;
			}

		}
	
	}

}

bool check(ll k){

	bool ok = true ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < grafo[i].size() ; j++){
			grafo[i][j].ff += k ; 
		}
	}

	for(int i = 1 ; i <= n ; i++) cam[i] = INF, dist[i] = INF ; 

	dij() ; 

	for(int i = 2 ; i <= n ; i++){
		if(cam[i] != nivel[i]) ok = false ; 
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < grafo[i].size() ; j++){
			grafo[i][j].ff -= k ; 
		}
	}

	return ok ; 

}

int main(){

	cin >> n >> m ; 
	
	for(int i = 1 ; i <= m ; i++){
		ll a, b, c ; 
		cin >> a >> b >> c ; 
		grafo[a].push_back({c, b}) ;
		grafo[b].push_back({c, a}) ;
	}

	bfs() ; //marcar os niveis p menor qtd de arestas p cada u 
    
    ll ini = 0LL, fim = inf, mid, best = -1LL ;
    
    while(ini <= fim){
    	
    	mid = (fim + ini)/2 ; 

    	if(check(mid)) best = mid, fim = mid - 1 ;
    	else ini = mid + 1 ; 

    }

    cout << best << "\n" ;

}
