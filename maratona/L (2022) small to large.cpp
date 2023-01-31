#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, sz[maxn], ans[maxn], x[maxn], ct[maxn] ; 
pair<int,int> ar[maxn] ; 
map<pair<int,int>, int> mp ; 
map<int,int> freq[maxn], sum ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs(a, v) ; 
		sz[v] += sz[a] ; 
	}

}

void dfs_sml(int v, int p){

	int bigg = 0 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(sz[a] >= sz[bigg]) bigg = a ; 
	}

	if(!bigg){
		freq[v][x[v]]++ ; sum[v] = (ct[x[v]]-1) ; ans[mp[{v, p}]] = sum[v] ; 
		return ;  
	}

	dfs_sml(bigg, v) ;  

	swap(freq[v], freq[bigg]) ; swap(sum[v], sum[bigg]) ; 

	int ant = freq[v][x[v]] ; 
	freq[v][x[v]]++ ; 
	int neww = freq[v][x[v]] ; 
	sum[v] -= (ant)*(ct[x[v]] - ant) ;
	sum[v] += (neww)*(ct[x[v]] - neww) ; 

	for(auto a : grafo[v]){
		if(a == p || a == bigg) continue ; 
		dfs_sml(a, v) ; 
		for(auto b : freq[a]){
			int ant = freq[v][b.first] ; 
			freq[v][b.first] += b.second ; 
			int neww = freq[v][b.first] ; 
			sum[v] -= (ant)*(ct[b.first] - ant) ;
	        sum[v] += (neww)*(ct[b.first] - neww) ;
		}
	}

	ans[mp[{v, p}]] = sum[v] ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> x[i] ; 

	for(int i = 1 ; i <= n ; i++) ct[x[i]]++ ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; cin >> a >> b ; 
		mp[{a, b}] = i ; mp[{b, a}] = i ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	dfs(1, 1) ; 
	dfs_sml(1, 1) ;  

	for(int i = 1 ; i < n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 

}
