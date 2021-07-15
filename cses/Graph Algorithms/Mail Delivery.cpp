// printar caminho euleriano em O(m)
#include<bits/stdc++.h>
using namespace std ; 

//ciclo que começa em 1 

const int maxn = 2e5 + 5 ; 

int n, m, a, b, vis[maxn] ;
vector<pair<int,int>> grafo[maxn] ; 
stack<int> fila ;
vector<int> resp ;  

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].push_back({b, i}), grafo[b].push_back({a, i}) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		if(grafo[i].size()&1){
			cout << "IMPOSSIBLE\n" ; // como qr ciclo n pode ter de grau impar 
			return 0 ; 
		}
	}

	fila.push(1) ; 

	while(!fila.empty()){
		
		int v = fila.top() ; 
		bool f = 0 ; 

		while(!grafo[v].empty()){ //enquanto o grau n eh 0 

			int u = grafo[v].back().first, id = grafo[v].back().second ; 
			grafo[v].pop_back() ; //apaga a aresta 

			if(!vis[id]){ // se n usou a aresta puxa o vertice p fila
				fila.push(u) ; 
				vis[id] = 1 ; 
				f = 1 ; 
				break ; 
			}
		
		}

		if(!f){ //se tds os kras do meu vertice ja foram usados eu add na resp 
			resp.push_back(v) ; 
			fila.pop() ; 
		}

	}

	if(resp.size() != m + 1) cout << "IMPOSSIBLE\n" ; 
	
	else{
		for(int i = 0 ; i < resp.size() ; i++) cout << resp[i] << " " ; 
		cout << "\n" ; 
	}

}
