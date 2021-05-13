#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, m, a, b, vis1[maxn], vis2[maxn], c, comp[maxn] ;
vector<int> grafo[maxn], grafo2[maxn] ; 
stack<int> g ; 
 
void dfs(int v){
	if(vis1[v]) return ; 
	vis1[v] = 1 ; 
	for(int b : grafo[v]) dfs(b) ;
	g.push(v) ; 
}
 
void dfs2(int v){
	if(comp[v]) return ;
	comp[v] = c ;  
	for(int a : grafo2[v]) dfs2(a) ; 
}
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo2[b].push_back(a) ;
	}
 
	for(int i = 1 ; i <= n ; i++) vis1[i] = comp[i] = 0 ; 
 
	for(int i = 1 ; i <= n ; i++){
		if(!vis1[i]) dfs(i); 
	}
 
	while(!g.empty()){
		int x = g.top() ; 
		//cout << x << " " << comp[x] << "\n" ; 
		g.pop() ; 
		if(!comp[x]) ++c, dfs2(x) ;
	}
 
	cout << c << "\n" ;
 
	for(int i = 1 ; i <= n ; i++) cout << comp[i] << " " ; 
	cout << "\n" ; 
 
}
