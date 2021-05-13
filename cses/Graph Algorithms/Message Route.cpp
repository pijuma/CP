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
 
int n, m, a, b, dist[maxn], pai[maxn] ; 
vector<int> grafo[maxn] ; 
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].pb(b), grafo[b].pb(a) ; 
	}
 
	queue<int> fila ; 
	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 
	dist[1] = 1 ; 
	pai[1] = - 1; 
	fila.push(1) ; 
 
	while(!fila.empty()){
		int att = fila.front() ;
		fila.pop(); 
 
		for(int u : grafo[att]){
			if(dist[u] != inf) continue ; 
			dist[u] = dist[att] + 1 ; 
			fila.push(u) ; 
			pai[u] = att ; 
		}
	}
 
	if(dist[n] == inf) cout << "IMPOSSIBLE\n" ;
	else{
		cout << dist[n] << "\n" ; 
		int p = n ; 
		vector<int> ans ; 
		while(p != -1){
			ans.pb(p) ; 
			p = pai[p] ; 
		}
		reverse(ans.begin(), ans.end()) ; 
		for(int a : ans) cout << a << " " ; 
		cout << "\n" ;  
	}
}
