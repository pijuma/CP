#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, timer, tin[maxn], low[maxn], pto_art[maxn] ; 
vector<int> grafo[maxn] ; 

void find_b(int v, int p){

	tin[v] = low[v] = ++timer ; 
	int child = 0 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(tin[a]){
			low[v] = min(low[v], tin[a]) ; 
			continue ; 
		}
		child++ ; 
		find_b(a, v) ;
		if(p != -1 && low[a] >= tin[v]) pto_art[v] = 1 ; 
		low[v] = min(low[v], low[a]) ;  
	}

	if(p == -1 && child > 1) pto_art[v] = 1 ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	find_b(1, -1) ; 

	vector<int> ans ; 

	for(int i = 1 ; i <= n ; i++) if(pto_art[i]) ans.push_back(i) ; 

	cout << ans.size() << "\n" ; 
	for(auto a : ans) cout << a << " " ; 
	cout << "\n" ; 

}
