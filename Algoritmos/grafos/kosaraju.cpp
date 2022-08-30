#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int mod = 1e9 + 7 ;
const int maxn = 2e5 + 5 ; 
 
int n, m, q, k, tab[32][maxn], c, comp[maxn], dp[maxn], grau[maxn], vis[maxn], pai[maxn] ;
vector<int> grafo[maxn], grafo2[maxn], cam, ans ; 
stack<int> fila ; 
 
void dfs(int v){
	if(vis[v]) return ; 
	vis[v] = 1 ; 
	for(auto a : grafo[v]) dfs(a) ;
	fila.push(v) ;
}
 
void dfs2(int v){
	if(comp[v]) return ; 
	comp[v] = c ; 
	for(auto a : grafo2[v]) dfs2(a) ; 
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo2[b].push_back(a) ; 
	}
 
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]) dfs(i) ; 
	}
 
	while(!fila.empty()){
		int at = fila.top() ; fila.pop() ; 
		if(!comp[at]) {++c; dfs2(at) ; }
	}
 
	cout << c << "\n" ;
	for(int i = 1 ; i <= n ; i++) cout << comp[i] << " " ; 
	cout << "\n" ; 
 
}
