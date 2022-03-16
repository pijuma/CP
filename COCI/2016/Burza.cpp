#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 405 ; 

int n, tin[maxn], tout[maxn], timer, k, nivel[maxn], dp[(1<<20)][maxn] ; 
vector<int> grafo[maxn], vec[maxn] ; 

void dfs(int v, int p){ 

	if(nivel[v] >= 0) vec[nivel[v]].push_back(v) ;

	tin[v] = timer + 1 ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		if(nivel[a] < k) dfs(a, v) ;  
	}

	if(nivel[v] == k-1) timer++ ;

	tout[v] = timer ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> k ; 

	for(int i = 1 ; i < n ; i++){
		int u, v ; 
		cin >> u >> v ; u--, v-- ; 
		grafo[u].push_back(v) ; grafo[v].push_back(u) ; 
	}

	if(k*k >= n){
		cout << "DA\n" ; exit(0) ; 
	}

	nivel[0] = -1 ; 

	dfs(0, 0) ;  

	for(int i = 0 ; i < (1<<k) ; i++) dp[i][0] = 1 ; 

    for(int mask = 1 ; mask < (1<<k) ; mask++){

    	for(int i = 0 ; i < k ; i++){
    		
    		if(!(mask&(1<<i))) continue ; 

    		for(auto at : vec[i]){
    			if(dp[mask^(1<<i)][tin[at]-1]) dp[mask][tout[at]] = 1 ; 
    		}

    	}

    }

    for(int i = 0 ; i < (1<<k) ; i++){
    	if(dp[i][timer]){
    		cout << "DA\n" ; exit(0) ; 
    	}
    }

    cout << "NE\n" ; 

}
