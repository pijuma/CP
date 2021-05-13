#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<ll,ll> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const ll inf = 1e18 ; 
 
ll n, m, dist[maxn], a, b, c, k, pai[maxn], vis[maxn], grau[maxn] ; 
int passou[maxn] ;
int ciclo ;  
vector<int> grafo[maxn] ; 
vector<int> ans ; 
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ;
		grafo[a].push_back(b) ; 
		grau[b]++ ; 
	}
 
	vector<int> fila ; 
 
	for(int i = 1 ; i <= n ; i++) 
		if(!grau[i]) fila.push_back(i) ; 
 
	int ini = 0 ; 
	while(fila.size() > ini){
		int at = fila[ini]; 
		ini++ ;  
		for(int i : grafo[at]){
			grau[i]-- ; 
			if(!grau[i]) fila.push_back(i) ; 
		}
	}
 
	if(fila.size() == n){
		for(int i : fila) cout << i << " " ;
			cout << "\n" ; 
	} 
	else cout << "IMPOSSIBLE\n" ; 
}
