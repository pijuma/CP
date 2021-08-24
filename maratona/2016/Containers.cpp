// dijkstra
#include<bits/stdc++.h>
#define piiv pair<int, vector<int>> 
using namespace std ; 

const int inf = 1e9 ; 

map<vector<int>, int> dist ; 
vector<int> destino(9), origem(9), f, vec ; 
priority_queue<piiv, vector<piiv>, greater<piiv>> fila ; 

void compute(vector<int> v){

	vec = v ; 

	for(int i = 0 ; i < 8 ; i++){
		
		int k = (i < 4 ? i + 4 : i - 4) ; // trocar verticalmente 
		swap(vec[i], vec[k]) ; 
		
		if(!dist[vec]) dist[vec] = inf ;  
		if(dist[vec] > dist[v] + vec[i] + vec[k]){ // dist p ir ate o anterior + valores dos pesos 
			dist[vec] = dist[v] + vec[i] + vec[k] ; 
			fila.push({dist[vec], vec}) ;  
		}
		
		swap(vec[i], vec[k]) ; 

		if((i < 4 && i > 0) || (i > 4)){ // pode tentar trocar com o de tras
			swap(vec[i], vec[i-1]) ; 
			if(!dist[vec]) dist[vec] = inf ; 
			if(dist[vec] > dist[v] + vec[i] + vec[i-1]){
				dist[vec] = dist[v] + vec[i] + vec[i-1] ; 
				fila.push({dist[vec], vec}) ; 
			}
			swap(vec[i], vec[i-1]) ; 
		}

		if((i < 4 && i < 3)||(i > 4 && i < 7)){
			swap(vec[i], vec[i+1]) ; 
			if(!dist[vec]) dist[vec] = inf ; 
			if(dist[vec] > dist[v] + vec[i] + vec[i+1]){
				dist[vec] = dist[v] + vec[i] + vec[i+1] ; 
				fila.push({dist[vec], vec}) ; 
			}
			swap(vec[i], vec[i+1]) ; 
		}

	}

}

int main(){


	for(int i = 0 ; i < 8 ; i++) cin >> origem[i] ;
	for(int i = 0 ; i < 8 ; i++) cin >> destino[i] ;

	fila.push({-1, origem}) ;
	dist[origem] = -1 ; 

	while(!fila.empty()){
		f = fila.top().second ; int d = fila.top().first ; fila.pop() ; 
		if(d > dist[f]) continue ; 
		if(f == destino) break ; 
		compute(f) ; 
	} 

	cout << dist[destino] + 1 << "\n" ; 

}
