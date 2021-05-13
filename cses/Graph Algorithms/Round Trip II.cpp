#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<ll,ll> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const ll inf = 1e18 ; 
 
ll n, m, dist[maxn], a, b, c, k, pai[maxn], vis[maxn] ; 
int passou[maxn] ;
int ciclo ;  
vector<int> grafo[maxn] ; 
vector<int> ans ; 
 
void dfs(int v){
 
	passou[v] = 1 ; 
	for(int a : grafo[v]){
		if(ciclo) continue ; 
		pai[a] = v ; 
		if(passou[a] == 1) ciclo = v, pai[a] = 0 ; 
		else if(!passou[a]) dfs(a) ; 
	}
 
	passou[v] = 2 ; 
 
}
 
void find(int f){
	
	if(!f) return ; 
	find(pai[f]) ; 
	cout << f << " " ; 
}
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b) ; 
	}
 
	memset(passou, 0, sizeof passou) ;
 
	for(int i = 1 ; i <= n ; i++)
		if(!passou[i]) dfs(i) ;
 
	if(!ciclo){
		cout << "IMPOSSIBLE\n" ;
		return 0 ;  
	}
 
	else{
	    int p = pai[ciclo], resp = 0  ; 
	    while(p){
	    	++resp ; 
	    	p = pai[p] ; 
	    }	
	    cout << resp + 2 << "\n" ; 
	    cout << ciclo << " " ; 
		find(ciclo) ; 
		cout << "\n" ;  
	}
 
}
