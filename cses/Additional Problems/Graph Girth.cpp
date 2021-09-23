#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 5e3 + 5 ; 
const int inf = 1e9 ; 
 
int n, m, mn, dist[maxn] ; 
vector<int> grafo[maxn] ; 
 
void bfs(int v){
 
	queue<pair<int,int>> fila ; fila.push({v, 0}) ;
	memset(dist, 0, sizeof dist) ; 
	dist[v] = 1 ;
 
	while(!fila.empty()){
		int at = fila.front().first, p = fila.front().second ; fila.pop() ; 
		for(auto a : grafo[at]){
			if(a == p) continue ; 
			if(!dist[a]){
				dist[a] = dist[at] + 1 ; 
				fila.push({a, at}) ; 
			}
			else mn = min(mn, dist[at] + dist[a] - 1) ;
		}
	}
 
}
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ;
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}
 
	mn = inf ; 
 
	for(int i = 1 ; i <= n ; i++) bfs(i) ; 
 
	if(mn == inf) cout << "-1\n" ; 
	else cout << mn << "\n" ; 
 
}
