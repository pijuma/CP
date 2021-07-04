#include<bits/stdc++.h>
#include "race.h"
#define mk make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int inf = 1e9 + 5 ; 
const int maxn = 2e5 + 5 ; 
const int MAX = 1e6 + 5 ; 
 
int ans = inf ;
int freq[MAX], k, sz[maxn], mark[maxn] ;  
vector<pii> grafo[maxn] ; 
 
void dfs(int v, int p){
	
	sz[v] = 1 ; 
 
	for(pii a : grafo[v]){
		
		if(mark[a.f] || a.f == p) continue ; 
		dfs(a.f, v) ;  
		sz[v] += sz[a.f] ; 
 
	}
 
}
 
int centroid(int u, int p, int qtd){
 
	for(pii a : grafo[u]){

		if(a.f == p || mark[a.f] || sz[a.f]*2 <= qtd) continue ; 
		
		return centroid(a.f, u, qtd) ; 
	
	}
 
	return u ; 
 
}
 
void add(int u, int p, int v, int dist, int len){
	
	if(dist > k) return ; 
 
	if(v == -1) freq[dist] = inf ; //voltar p fzr p prox cent 
	else freq[dist] = min(freq[dist], len) ; //unir c a outra sub 
 
	for(pii a : grafo[u]){

		if(a.f == p || mark[a.f]) continue ; 
		add(a.f, u, v, dist + a.s, len + 1) ; 
	
	}
 
}
 
void solve(int u, int p, int dist, int len){
 
	if(dist > k) return ; //n tem como ter tam k 
	ans = min(ans, freq[k-dist] + len) ; // quais caras eu uso com tam k -> usamos len p ter dist -> queremos minimizar
 
	for(pii a : grafo[u]){
		if(a.f == p || mark[a.f]) continue ; 
		solve(a.f, u, dist + a.s, len+1) ;  
	}
 
}
 
void make_a(int v, int p){
 
	dfs(v, p) ; 
 
	int c = centroid(v, p, sz[v]) ;
 
	mark[c] = 1 ; 
	
	freq[0] = 0 ; 
 
	for(pii a : grafo[c]){
		if(mark[a.f] || a.f == p) continue ; 
		solve(a.f, c, a.s, 1) ; //resolver p minha 
		add(a.f, c, 1, a.s, 1) ; //add a minha p fzr c proxs 
	}
 
	for(pii a : grafo[c]){
		if(mark[a.f] || a.f == p) continue ; 
		add(a.f, c, -1, a.s, 1) ; //retirar tds p fzr p prox 
	}
 
	for(pii a : grafo[c]) if(!(a.f == p || mark[a.f])) make_a(a.f, c) ; //prox cent
 
}
 
 
int best_path(int N, int K, int H[maxn][2], int L[maxn]){
 
	for(int i = 0 ; i < N - 1 ; i++){
		grafo[H[i][0]].pb({H[i][1], L[i]}) ;
		grafo[H[i][1]].pb({H[i][0], L[i]}) ;
	}
	
	k = K ; 
 
	for(int i = 1 ; i <= k ; i++) freq[i] = inf ; 
 
	make_a(0, -1) ; 
    
    return (ans != inf ? ans : -1) ;
 
}
