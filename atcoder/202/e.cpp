#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, p, q, u, d, nivel[maxn], tin[maxn], tout[maxn], timer, vis[maxn] ; 
vector<int> lista[maxn] ; 
vector<int> grafo[maxn] ; 

// There are exactly Di edges in the shortest path from u to the root. -> tem q ter nivel[d]
// Vertex Ui is in the shortest path from u to the root (including the endpoints). ->  tem q estar na sub de Ui
// faz tin/tout e guarda uma lista dos tin's p cada nivel 
// qd for na query responde a dif entre o upper p 1o cara q tem tout maior q o de Ui 
// e o 1o cara q tem tin maior ou igual q Ui - queremos tds os caras q tem tin entre o tin e tout de u 

void dfs(int v, int p){
	
	tin[v] = ++timer ; 
	lista[nivel[v]].push_back(tin[v]) ; 
	
	for(int a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		nivel[a] = nivel[v] + 1 ;
		vis[a] = 1 ;  
		dfs(a, v) ; 
	}
	
	tout[v] = timer ; 

}


int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 2 ; i <= n ; i++){
		cin >> p ;
		grafo[p].push_back(i) ;  
	}

	nivel[1] = 0 ;  
	dfs(1, 1) ; 

	// for(int i = 1 ; i <= n ; i++) cout << nivel[i] << " " ;
	// cout << "\n" ;  
	cin >> q ; 

	while(q--){
		cin >> u >> d ; 
		cout << upper_bound(lista[d].begin(), lista[d].end(), tout[u]) - lower_bound(lista[d].begin(), lista[d].end(), tin[u]) << "\n" ; 
	}

}