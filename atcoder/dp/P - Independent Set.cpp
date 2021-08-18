#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, a, b, dp[maxn], dp2[maxn] ; 
vector<int> grafo[maxn] ; 
// dp - branco, dp2 - preto 

void dfs(int v){

	dp[v] = dp2[v] = 1 ; 

	for(auto a : grafo[v]){
		
		if(dp[a] != -1) continue ; 

		dfs(a) ; 

		dp2[v] *= dp[a] ; dp2[v] %= mod ; // eu preto e tds filhos brancos 
		dp[v] *= (dp2[a] + dp[a]) ; dp[v]%=mod ; // se eu for branco meu filhos podem ser brancos ou pretos

	}

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		
		int a, b ; 
		cin >> a >> b ; 
		
		grafo[a].push_back(b), grafo[b].push_back(a) ; 

	}

	for(int i = 1 ; i <= n ; i++) dp[i] = dp2[i] = -1 ; 

	dfs(1) ; 
    
    cout << (dp2[1] + dp[1])%mod << "\n" ; 

}
