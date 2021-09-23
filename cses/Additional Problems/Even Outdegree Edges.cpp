#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int timer, tin[maxn], m, n ; 
pair<int,int> ans[maxn] ; 
vector<pair<int,int>> grafo[maxn] ; 
bool par[maxn] ;
 
void dfs(int v, int p){
 
	tin[v] = ++timer ; 
 
	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		if(!tin[a.first]){
			dfs(a.first, v) ; 
			if(par[a.first]){
				ans[a.second] = {v, a.first} ;
				par[v] ^= 1 ;  
			}
			else{
				ans[a.second] = {a.first, v} ; 
				par[a.first] ^= 1 ; 
			}
		}
		else if(tin[a.first] < tin[v]) {
			ans[a.second] = {v, a.first} ; 
			par[v] ^= 1 ; 
		}
	}
 
}
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back({b, i}), grafo[b].push_back({a, i}) ; 
	}
 
	for(int i = 1 ; i <= n ; i++) par[i] = 1 ; 
 
	for(int i = 1 ; i <= n ; i++){
		if(!tin[i]) dfs(i, i) ; 
	}
 
	for(int i = 1 ; i <= n ; i++){
		if(!par[i]) cout << "IMPOSSIBLE\n", exit(0) ; 
	}
 
	for(int i = 1 ; i <= m ; i++) cout << ans[i].first << " " << ans[i].second << "\n" ; 
 
}
