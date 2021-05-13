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

// sz da subtree
// centroid p cada "nova arvore"

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

	if(v == -1) freq[dist] = inf ; 
	else freq[dist] = min(freq[dist], len) ;

	for(pii a : grafo[u]){
		if(a.f == p || mark[a.f]) continue ; 
		add(a.f, u, v, dist + a.s, len + 1) ; 
	}

}

void solve(int u, int p, int dist, int len){

	if(dist > k) return ; 
	ans = min(ans, freq[k-dist] + len) ; 

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
		solve(a.f, c, a.s, 1) ;
		add(a.f, c, 1, a.s, 1) ;
	}

	// for(int i = 0 ; i <= k ; i++) cout << freq[i] << " " ; 
	// cout << "\n" ; 

	for(pii a : grafo[c]){
		if(mark[a.f] || a.f == p) continue ; 
		add(a.f, c, -1, a.s, 1) ;
	}

	for(pii a : grafo[c]) if(!(a.f == p || mark[a.f])) make_a(a.f, c) ;

}


int best_path(int N, int K, int H[maxn][2], int L[maxn]){

	for(int i = 0 ; i < N - 1 ; i++){
		grafo[H[i][0]].pb(mk(H[i][1], L[i])) ;
		grafo[H[i][1]].pb(mk(H[i][0], L[i])) ;
	}
	
	k = K ; 

	for(int i = 1 ; i <= k ; i++) freq[i] = inf ; 

	make_a(0, -1) ; 
    
    return (ans == inf ? -1 : ans) ;

}

/*int main(){

    int mat[10][2] = {0, 1, 0, 2, 2, 3, 3, 4, 4, 5, 0, 6, 6, 7, 6, 8, 8, 9, 8, 10}, mat2[10] = {3, 4, 5, 4, 6, 3, 2, 5, 6, 7};

    cout << best_path(11, 12, mat, mat2) << endl;

    return 0;
}*/
