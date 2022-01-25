#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 505 ;
const int inf = 1e9 ; 

int n, l, k, v[maxn], d[maxn], vis[maxn][maxn] ; 
int dp[maxn][maxn] ; 

// dp[i][j] = min tempo entre as cidades usando até i e ignorando j 

int solve(int i, int K){
	
	if(K < 0) return inf ;
	if(i > n) return 0 ;  
	if(vis[i][K]) return dp[i][K] ; 

	int ans = inf ; 

	for(int j = i + 1 ; j <= n + 1 ; j++){ // qual prox q eu pego 
		ans = min(ans, (d[j] - d[i])*v[i] + solve(j, K - (j - i -1))) ; 
	}

	vis[i][K] = 1 ; 
	return dp[i][K] = ans ; 
}

int32_t main(){

	cin >> n >> l >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> d[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	d[n+1] = l ; 

	cout << solve(1, k) << "\n" ; 

}
