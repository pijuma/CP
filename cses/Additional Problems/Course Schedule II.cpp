#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, m, a, b, grau[maxn] ; 
vector<int> grafo[maxn] ; 
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[b].push_back(a) ; 
		grau[a]++ ; 
	}
 
	priority_queue<int> fila ; 
 
	for(int i = 1 ; i <= n ; i++) if(!grau[i]) fila.push(i) ; 
 
	vector<int> ans ; 
 
	while(!fila.empty()){
		int at = fila.top() ; fila.pop() ; 
		ans.push_back(at) ; 
		for(auto a : grafo[at]){
			if(!(--grau[a])) fila.push(a) ; 
		}
	}
 
	for(int i = ans.size() - 1 ; i >= 0 ; i--) cout << ans[i] << " " ; 
	cout << "\n" ; 
 
}
