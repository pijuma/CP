// bidirecionado pode ter dois impares e ligamos ele p fzr o ciclo dps tiramos 
// nesse ele precisa ir de 1 a n
// caminho euleriano

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, a, b, vis[maxn] ; 
vector<pair<int,int>> grafo[maxn], grafo2[maxn] ; 
vector<int> resp ; 
stack<int> fila ; 

int main(){

	cin >> n >> m ; 

	//ir de 1 a n (n tem ciclo) -> tem q ter dois impares -> (a, b) - vai de a p b 

	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ;
		grafo[a].push_back({b, i}) ;
		grafo2[b].push_back({a, i}) ; 
	}

	int v1 = -1, v2 = -1 ; 
	bool bad = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		
		if((grafo[i].size() + grafo2[i].size())&1){
			if(v1 == -1) v1 = i ; 
			else if(v2 == -1) v2 = i ; 
			else bad = 1 ; 
		}

	}

	if(bad || v2 == -1 || v1 != 1 || v1 == -1 || v2 != n){ // queremos ir de 1 a n ent se os impares n forem 1 e n n tem como
		cout << "IMPOSSIBLE\n" ; 
		return 0 ; 
	}

	cout << v1 << " " << v2 << "\n" ; // os de grau impar  

	grafo[v1].push_back({v2, m+1}) ; grafo[v2].push_back({v1, m+2}) ; //crio uma aresta ligando os impares

	fila.push(1) ; 

	while(!fila.empty()){
		
		int v = fila.top() ;
		bool f = 0 ; 

		while(!grafo[v].empty()){ // enquanto tem caras p visitar q são meus filhos
			
			int u = grafo[v].back().first, id = grafo[v].back().second ;
			grafo[v].pop_back() ; //visito eles e apago 

			if(!vis[id]){ // se nunca foi visitado vou p ele 
				vis[id] = 1 ; 
				fila.push(u) ; // puxo p fila 
				f = 1 ; 
				break ; 
			}

		}

		if(!f){ // n tinha ngm p visitar ent eu pss ir p resp e apago da fila 
			resp.push_back(v) ; 
			fila.pop() ; 
		}

	}

	vector<int> resp2 ; 

	for(int i = 0 ; i < resp.size() - 1 ; i++){ // tem q ignorar os impares add's 
		if((resp[i] == v1 && resp[i+1] == v2) || (resp[i] == v2 && resp[i+1] == v1)){
			for(int j = i + 1 ; j < resp.size() ; j++) resp2.push_back(resp[j]) ; 
			for(int j = 0 ; j < i ; j++) resp2.push_back(resp[j]) ; 
			resp = resp2 ;
		    break ; 
		}
	}

	for(int i = 0 ; i < resp2.size() ; i++) cout << resp2[i] << " " ;
	cout << "\n" ; 
	
}
