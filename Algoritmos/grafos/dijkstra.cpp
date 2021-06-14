#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

int n, a, b, c, dist[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ; 
	}

	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 

	dist[1] = 0 ; 
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
    fila.push({0, 1}) ; 

    while(!fila.empty()){
    	int at = fila.top().second ; fila.pop() ; 
    	for(auto a : grafo[at]){
    		if(dist[a.first] > dist[at] + a.second){
    			dist[a.first] = dist[at] + a.second ; 
    			fila.push({dist[a.first], a.first}) ; 
    		}
    	}
    }

    cout << dist[n] << "\n" ; 
    
}