#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<int,int> 
#define pb push_back
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 
 
int n, m, a, b, dist[maxn], vis[maxn], pai[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int u, int p){
	vis[u] = 1 ; 
	pai[u] = p ; 
	for(int a : grafo[u]){
		if(a == p) continue ; 
		if(vis[a]){
			vector<int> ans ; 
			int p = u ; 
			while(a^u){
				ans.pb(u) ; 
				u = pai[u] ;  
			}
			ans.pb(a), ans.pb(p) ; 
			cout << ans.size() << "\n" ; 
			for(int b : ans) cout << ++b << " " ; 
			cout << "\n" ; 
			exit(0) ; 
		}
	    else dfs(a, u) ; 
	}
}
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		a--, b-- ; 
		grafo[a].pb(b), grafo[b].pb(a) ; 
	}
 
	for(int i = 0 ; i < n ; i++) 
		if(!vis[i]) dfs(i, -1) ; 
 
	cout << "IMPOSSIBLE\n" ;
 
}
