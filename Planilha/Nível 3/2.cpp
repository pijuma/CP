// 	A - Xor-tree 
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, val[maxn], fim[maxn], change[2][maxn] ; 
vector<int> ans ; 
vector<int> grafo[maxn] ; 

// dp[1][i] -> flipei o meu -> mantenho o filho 
// se eu mantive o filho (dp[0][i]) de forma obrigatoria foi pq eu flipei 
// algm anterior de tal forma q o filho do filho será flipado 

void dfs(int v, int p){
	
	if(val[v] != fim[v]){ // precisa flipar
		val[v] ^= 1 ; 
		change[1][v]++ ; 
		ans.push_back(v) ; 
	}

	change[1][v] %= 2 ; //pss estar anulando um flip 

	for(auto a : grafo[v]){

		if(a == p) continue ; 

		if(change[1][v]) change[0][a] = 1 ;
		if(change[0][v]){
			val[a] ^= 1 ; 
			change[1][a]++ ; 
		}

		dfs(a, v) ; 
	
	}

}

int main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) cin >> val[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> fim[i] ; 

	dfs(1, 1) ; 
    
    cout << ans.size() << "\n" ; 
	for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << "\n" ;

}
