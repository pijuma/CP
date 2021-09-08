// se tds forem portal - mst 
// 1 dijkstra de cada portal - p cada vertice qual o portal + prox 
// pega o vertice mais prox de cada
// monta novo grafo 
// p cada i ve no grafo se j tem mais prox diferente se tiver ele pode ser util e usado como caminho 
// a aresta vai ter peso d[i] + d[j] + peso aresta dai liga o mais prox de um com o do outro 
// e roda uma mst 

#include<bits/stdc++.h>
#define ll long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const ll inf = 1e18 + 10 ; 

ll dist[maxn], perto[maxn], n, k, m, portal[maxn] ; 
int pai[maxn], sz[maxn], mark[maxn] ; 
vector<pair<int,ll>> grafo[maxn] ;
vector<pair<ll,pair<int,int>>> aresta ; 

struct DSU{

	int find(int a){ return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		
		a = find(a), b = find(b) ; 
		if(sz[a] > sz[b]) swap(a, b) ; 
		
		sz[b] += sz[a] ; 
		pai[a] = b ; 
	} 

} dsu ; 

void ini(){
	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 
}

void mst1(){ // tds vertices são portais 

	ll peso = 0 ; 

	sort(aresta.begin(), aresta.end()) ; 

	for(auto a : aresta){
		if(dsu.find(a.second.second) == dsu.find(a.second.first)) continue ; 
		dsu.join(a.second.second, a.second.first) ; 
		peso += a.first ; 
	}

	// se o 1 n eh portal tem q add ele pois começa no 1 
	bool port1 = 0 ; 
	for(int i = 1 ; i <= k ; i++) if(portal[i] == 1) port1 = 1 ; 
	cout << peso + (port1 ? 0 : dist[1]) << "\n" ; 
	exit(0) ; 
}

void dijkstra(){

	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> fila ; 

	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 

	for(int i = 1 ; i <= k ; i++){
		dist[portal[i]] = 0 ; fila.push({0, portal[i]}) ;
		perto[portal[i]] = portal[i] ;  
	}

	while(!fila.empty()){
		
		int at = fila.top().second ; fila.pop() ; 
		
		if(mark[at]) continue ; 
		mark[at] = 1 ;

		for(auto a : grafo[at]){
			if(dist[a.first] > dist[at] + a.second){
				dist[a.first] = dist[at] + a.second ; 
				perto[a.first] = perto[at] ; 
				fila.push({dist[a.first], a.first}) ; 
			}
		}  

	}

	// for(int i = 1 ; i <= n ; i++) cout << dist[i] << " " ; 
	// cout << "\n" ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}) ; 
		grafo[b].push_back({a, c}) ; 
		aresta.push_back({c, {a, b}}) ; 
	}

	cin >> k ; 

	for(int i = 1 ; i <= k ; i++) cin >> portal[i] ;

	ini() ; 

	if(k == n) mst1() ; 

	dijkstra() ; 

	aresta.clear() ; 

	for(int i = 1 ; i <= n ; i++){ // grafo portais 
		for(auto a : grafo[i]){
			if(perto[i] == perto[a.first]) continue ; 
			aresta.push_back({dist[i] + dist[a.first] + a.second, {perto[i], perto[a.first]}}) ; 
		}
	}

	ini() ; 

	mst1() ; 

}
