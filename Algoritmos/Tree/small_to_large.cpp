// faz p filho grande 
// swapa a info dele com o pai 
// faz pros pequenos mudando os valores na mao 
// (nlog) 
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, x[maxn], ans[maxn], sz[maxn] ; 
vector<int> grafo[maxn] ; 
map<int,int> freq[maxn], sum[maxn] ; // freq de cada cor p cada vert e soma dos numeros q p vertice v aparecem l vzs
map<int,int> dom, freq_dom ; // dom p cada vertice e a freq dele 

void dfs2(int v, int p){

	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs2(a, v) ; 
		sz[v] += sz[a] ; 
	}

}

void dfs(int v, int p){

	int bigg = 0 ; int mx = 0 ; 

	for(auto a : grafo[v]){
		if(a != p && sz[a] >= sz[bigg]){
			mx = sz[a] ; bigg = a ; 
		} 
	}

	if(!bigg){
		freq_dom[v] = 1, freq[v][x[v]] = 1 ; sum[v][1] = x[v] ; 
		ans[v] = x[v] ;
		return ; 
	} 

	dfs(bigg, v) ; 

	swap(sum[v], sum[bigg]) ; 
	swap(freq_dom[v], freq_dom[bigg]) ; swap(freq[v], freq[bigg]) ;  

	int ant = freq[v][x[v]] ; 
	freq[v][x[v]]++ ; 
	int neww = freq[v][x[v]] ;
	if(ant != 0) sum[v][ant] -= (x[v]) ;
	sum[v][neww] += (x[v]) ;

	if(freq[v][x[v]] >= freq_dom[v]) freq_dom[v] = freq[v][x[v]] ; 
	int fdm = freq_dom[v] ; 

	for(auto a : grafo[v]){ // smalls 
		if(a == bigg || a == p) continue ; 
		dfs(a, v) ; // dfs p ele e add no meu agr 
		for(auto b : freq[a]){ // n°'s que ele tem 
			int val = b.first, ff = b.second ; 
		    int ant = freq[v][val] ; 
		    freq[v][val] += ff ; 
		    int nww = freq[v][val] ;  
		    if(ant != 0) sum[v][ant] -= (val) ;
		    sum[v][nww] += (val) ; 
		}
		for(auto b : freq[a]){
			if(freq[v][b.first] >= fdm) fdm = freq[v][b.first] ; 
		}
		freq_dom[v] = fdm ; 
	}

	ans[v] = sum[v][freq_dom[v]] ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> x[i] ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	dfs2(1, 1) ; 

	dfs(1, 1) ; 

	for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 

}
