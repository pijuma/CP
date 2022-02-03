#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, ini[maxn], flip[2][maxn], fim[maxn], vis[maxn] ; 
vector<int> ans ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){

	if(ini[v] != fim[v]){ // precisa flipar
		ini[v] ^= 1 ; 
		flip[1][v]++ ; //muda
		ans.push_back(v) ; 
	}

	flip[1][v] %= 2 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ;
		if(flip[1][v]) flip[0][a] = 1 ; 
		if(flip[0][v]){ //propaga
			ini[a] ^= 1 ; 
			flip[1][a]++ ; 
		}
		dfs(a, v) ;
	}

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) cin >> ini[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> fim[i] ; 

	dfs(1, 1) ; 

    cout << ans.size() << "\n" ; 
    for(auto a : ans) cout << a << "\n" ;  

}
