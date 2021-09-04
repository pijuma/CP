#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// tem q ir p um lugar q tenha ciclo p poder voltar
// acha c pontes os ciclos e monta o novo grafo 
// guarda a dist total de tds os ciclos 
// a resp vai ser cj + 2*dist(v, j)
// cj eh o peso de um ciclo q eh maior q meu trem 
// e dist eh a dist do cara q eu começo p 1o cara do ciclo 

const int maxn = 2e4 + 5 ; 
const int inf = 1e9 + 5 ;

int n, timer, m, c, comp[maxn], q, vis[maxn], bridge[maxn] ;
int tin[maxn], low[maxn], sz[maxn], dist[maxn], dist_near[maxn], dist_dij[maxn] ;  
vector<pair<int,int>> tree[maxn] ; 
vector<int> pai[maxn] ;
vector<pair<int,pair<int,int>>> grafo[maxn] ; 
bitset<maxn> chega[maxn], chega2[maxn] ; 

void find_b(int v, int p){

	tin[v] = low[v] = ++timer ; 

	for(auto a : grafo[v]){
		
		if(a.first == p) continue ; 
		if(tin[a.first]){
			low[v] = min(low[v], tin[a.first]) ; 
			continue ; 
		}

		find_b(a.first, v) ; 

		if(low[a.first] > tin[v]) bridge[a.second.second] = 1 ; 

		low[v] = min(low[v], low[a.first]) ; 

	}

}

void dfs(int v, int p){

	comp[v] = c ; 

	for(auto a : grafo[v]){
		if(a.first == p || vis[a.first] || bridge[a.second.second]) continue ; 
		vis[a.first] = 1 ; 
		dist[c] += a.second.first ; 
		dfs(a.first, v) ; 
	}

}

void dij(int ini){
	
	for(int i = 1 ; i <= n ; i++) dist_dij[i] = inf ; 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
    fila.push({0, ini}) ; 
    dist_dij[ini] = 0 ; 

    while(!fila.empty()){
    	
    	int at = fila.top().second ; fila.pop() ; 

    	for(auto a : grafo[at]){
    		if(dist_dij[a.first] > dist_dij[at] + a.second.first){
    			dist_dij[a.first] = dist_dij[at] + a.second.first ; 
    			fila.push({dist_dij[a.first], a.first}) ; 
    		}
    	}

    } 

}

int find_near(int v, int tam){

	int mn = inf ;   
	dij(v) ;

	for(int i = 1 ; i <= c ; i++){ // qual o menor ciclo mais prox c dist maior q tam 
		if(sz[i] == 1) continue ; 
		if(dist[i] < tam) continue ;
		int mn_dist = inf ; 
		for(auto a : pai[i]) mn_dist = min(mn_dist, dist_dij[a]) ; 
		if(i == comp[v]) mn = min(mn, dist[i]) ;
		else mn = min(mn, 2*mn_dist + dist[i]) ;
	}

	return mn ; 

}

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, {c, i}}), grafo[b].push_back({a, {c, i}}) ; 
	}

	find_b(1, 1) ; // achar tds as pontes 

	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]){
			c++ ; 
			dfs(i, i) ; // quebrar nos ciclos 
		}
	}

	for(int i = 1 ; i <= n ; i++) sz[comp[i]]++ ; 

	for(int i = 1 ; i <= n ; i++){
		for(auto a : grafo[i]){
			if(comp[i] == comp[a.first] || !bridge[a.second.second]) continue ; 
			pai[comp[i]].push_back(i), pai[comp[a.first]].push_back(a.first) ; 
			tree[comp[i]].push_back({comp[a.first], a.second.first}) ; 
			tree[comp[a.first]].push_back({comp[i], a.second.first}) ; 
		}
	} 

	for(int i = 1 ; i <= n ; i++){
		sort(pai[i].begin(), pai[i].end()) ; 
		pai[i].erase(unique(pai[i].begin(), pai[i].end()), pai[i].end()) ;
	}

	cin >> q ; 

	for(int i = 1 ; i <= q ; i++){
	 	int x, t ; 
	 	cin >> x >> t ; // ini, tam 

	 	int resp = find_near(x, t) ;
	 	if(resp == inf) cout << "-1\n" ; 
	 	else cout << resp << "\n" ;  	

	} 

}
