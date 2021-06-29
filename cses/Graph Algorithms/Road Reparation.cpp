#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int maxm = 2e5 + 5 ; 
const int maxn = 1e5 + 5 ; 
 
struct aresta{
	int a, b, pes ; 
} ; 
 
int n, m ; 
int peso, pai[maxn], h[maxn], vis[maxn] ;  
aresta grafo[maxm], ans ;
 
vector<int> graph[maxn] ; 
 
struct DSU{
 
	int find(int a){ return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }
 
	void join(int a, int b){
		
		a = find(a), b = find(b) ; 
 
		if(h[a] > h[b]){
			pai[b] = a ; 
		}
		
		else if(h[b] > h[a]){
			pai[a] = b ; 
		}
 
		else{
			h[a]++ ; 
			pai[b] = a ; 
		}
 
	}
 
} dsu ; 
 
void dfs(int v, int p){
	
	vis[v] = 1 ; 
 
	for(auto a : graph[v]){
		if(a == p || vis[a]) continue ; 
		dfs(a, v) ; 
	}
 
}
 
bool cmp(aresta a, aresta b){ return a.pes < b.pes ; }
 
int32_t main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++) cin >> grafo[i].a >> grafo[i].b >> grafo[i].pes ; 
 
	for(int i = 1 ; i <= n ; i++) pai[i] = i, h[i] = 1 ; 
 
	sort(grafo + 1, grafo + 1 + m, cmp) ; 
    
    int sz = 0 ; 
 
    for(int i = 1 ; i <= m ; i++){
    	
    	if(dsu.find(grafo[i].a) == dsu.find(grafo[i].b)) continue ; 
 
    	dsu.join(grafo[i].a, grafo[i].b) ;
    	
    	peso += grafo[i].pes ; 
 
    	graph[grafo[i].a].push_back(grafo[i].b), graph[grafo[i].b].push_back(grafo[i].a) ;
 
    }
 
    dfs(1, 1) ; 
 
    for(int i = 1 ; i <= n ; i++){
    	if(!vis[i]){
    		cout << "IMPOSSIBLE\n" ; 
    		return 0 ; 
    	}
    }
 
    cout << peso << "\n" ; 
 
}
