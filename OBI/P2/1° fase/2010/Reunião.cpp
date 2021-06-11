#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 110 ; 
const int inf = 1e9 ; 

int n, mn, m, a, b, c, dist[maxn], mark[maxn] ; 
vector<pair<int,int>> grafo[maxn] ;

void dij(int ini){

	for(int i = 0 ; i < n ; i++) mark[i] = 0, dist[i] = inf ; 

	dist[ini] = 0 ; 
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
    fila.push({0, ini}) ; 

    while(!fila.empty()){
    	int atual = fila.top().second ; 
    	fila.pop() ; 
    	if(mark[atual]) continue ; 
    	mark[atual] = 1 ; 
    	for(pair<int,int> a : grafo[atual]){
    		if(dist[a.first] > dist[atual] + a.second){
    			dist[a.first] = dist[atual] + a.second ;
    			fila.push({dist[a.first], a.first}) ; 
    		}
    	}
    }

    int mx = 0 ; 

    for(int i = 0 ; i < n ; i++) mx = max(mx, dist[i]) ; 

    mn = min(mn, mx) ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ; 
	}

	mn = inf ; 

	for(int i = 0 ; i < n ; i++) dij(i) ; 

	cout << mn << "\n" ; 

}
