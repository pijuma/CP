#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, k, ans, mxlvl, f[maxn], sub[maxn], mark[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){ //pegar a sub de tds

	sub[v] = 1 ; 

	for(int a : grafo[v]){
		if(a == p || mark[a]) continue ; 
		dfs(a, v) ; 
		sub[v] += sub[a] ; 
	}

}

void add(int v, int p, bool type, int nivel){
	
	if(nivel > k) return ; // n tem como ter caminho de tam k 
	
	mxlvl = max(nivel, mxlvl) ; //qual o maior nivel q temos ? (precisa zerar dps)

	if(type){
		ans += f[k-nivel] ;
		// cout << v << " " << nivel << " " << f[k-nivel] << " " << ans << "\n" ;
	}  // se eu estiver incrementando, qts caminhos k-nivel tenho?
	else f[nivel]++ ; //estou marcando minha sub e tenho dep de nivel 

	for(int a : grafo[v]){
		if(a == p || mark[a]) continue ; 
		add(a, v, type, nivel + 1) ; // add os proxs 
	}

}

int finding_cent(int v, int p, int qtd){

	for(int a : grafo[v]){ // acha o cent
		if(a == p || mark[a] || 2*sub[a] <= qtd) continue ; 
		return finding_cent(a, v, qtd) ; 
	}

	return v ; 

}

void make_a(int v, int p){

	dfs(v, p) ; //achar os tam's da subs
	int cent = finding_cent(v, p, sub[v]) ; // achar o centroid

	// cout << cent << ":\n" ; 

	mark[cent] = 1 ; //marca 
	mxlvl = 0 ; 
	f[0] = 1 ; 

	for(int a : grafo[cent]){
		if(a == p || mark[a]) continue ; 
		add(a, cent, 1, 1) ; //fzr tds os caminhos que passam pelo centroid "combinando as subs" 
		add(a, cent, 0, 1) ; //colocar minha sub 
	} 

	// cout << ans << "\n" ; 

	for(int i = 1 ; i <= mxlvl ; i++) f[i] = 0 ; 

	for(int a : grafo[cent]){
		if(mark[a]) continue ; 
		make_a(a, cent) ; //outros cents
	}	

}

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1, a, b ; i < n ; i++){ 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	make_a(1, 0) ; //montar a arvore de cent 

	cout << ans << "\n" ; 

}
