#include<bits/stdc++.h>
using namespace std ; 
 
// caminho euleriano ciclico 
 
const int maxn = 2e5 + 5 ;
 
int n, m, vis[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back({b, i}) ; grafo[b].push_back({a, i}) ;
	}
 
	for(int i = 1 ; i <= n ; i++){ // ciclo - deve ser grau par
		if(grafo[i].size()&1){
			cout << "IMPOSSIBLE\n" ; exit(0) ; 
		}
	}
	
	vector<int> ans ; 
 
	stack<int> fila ; 
	fila.push(1) ; 
 
	while(!fila.empty()){
		int at = fila.top() ; bool all_vis = 1 ; 
		while(!grafo[at].empty()){
			int u = grafo[at].back().first, id = grafo[at].back().second ; grafo[at].pop_back() ; 
			if(!vis[id]){
				fila.push(u) ; 
				vis[id] = 1 ; all_vis = 0 ; 
				break ;  
			}
		} 
		if(all_vis){
			fila.pop() ; ans.push_back(at) ; 
		}
	}
 
	if(ans.size() == m + 1){
		for(auto a : ans) cout << a << " " ; 
		cout << "\n" ; 
	}
 
	else cout << "IMPOSSIBLE\n" ; 
 
}
