#include<bits/stdc++.h> 
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, v[maxn], c, vis[maxn], vis2[maxn], sumcomp[maxn], comp[maxn], sum ; 
vector<int> g[maxn], gc[maxn], g2[maxn] ;
stack<int> fila, h ;  
pair<int, int> edge[maxn] ; 

void dfs1(int v, int p){ //pegar do ultimo ao 1o de cada (p checar se o contrário é vdd)
	vis[v] = 1 ; 
	for(int a : g[v]){ // grafo normal 
		if(a == p || vis[a]) continue ; 
		dfs1(a, v) ; 
	}
	fila.push(v) ;
} 

void dfs2(int u, int p){
	vis2[u] = 1 ; 
	comp[u] = c ; 
	for(int a : g2[u]){ // c o grafo reverso, eu consigo chegar em quais (?) 
		// como já fizemos o caminho de ida, se conseguir voltar é pq estão na msm componente 
		if(a == p || vis2[a]) continue ; 
		dfs2(a, u) ; 
	}
}

long long r(int u){
	
	if(vis[u]) return vis[u] ;
	
	long long ans = 0 ; 

	for(int a : gc[u]){
		ans = max(ans, r(a) + sumcomp[a]) ; //pegando a comp a, quanto fica a soma? (pegando tds os caras possíveis após ir p a)
	} 

	return vis[u] = ans ; // valor max pegando a comp u 

}

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1, a, b ; i <= m ; i++){
		cin >> a >> b ; 
		g[a].push_back(b), g2[b].push_back(a) ; 
	} 

	for(int i = 1 ; i <= n ; i++) if(!vis[i]) dfs1(i, i) ; 

	while(!fila.empty()){
		int at = fila.top() ; fila.pop() ; 
		if(!vis2[at]) c++, dfs2(at, at) ; 
		sumcomp[comp[at]] += v[at] ; // soma o cara "lider" da componente (o resto pega com r)
	}

	for(int i = 1 ; i <= n ; i++){
		for(int j : g2[i]){
		if(comp[i] == comp[j]) continue ; 
		gc[comp[i]].push_back(comp[j]) ; //monta o grafo ligando as componentes 
	    } 
	}

	memset(vis, 0, sizeof vis) ;
	
	long long resp = 0 ; 

	for(int i = 1 ; i <= c ; i++) resp = max(resp, r(i) + sumcomp[i]) ; //qual o mlr caminho começando da componente i? 

	cout << resp << "\n" ;  

}
