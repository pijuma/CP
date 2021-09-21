#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 200 + 5 ; 
const int inf = 1e9 ; 

int n, dp[2*maxn][2*maxn], v[2*maxn], pref[2*maxn] ; 
double f ; 

int solve(int ini, int fim){

	if(ini > fim) return inf ; 
	if(ini == fim) return 0 ; 
	 
	if(dp[ini][fim] != -1) return dp[ini][fim] ; 
	int ans = inf ; 

	for(int k = ini ; k < fim ; k++){
		ans = min(ans, max(pref[k] - pref[ini-1], pref[fim] - pref[k]) + solve(ini, k) + solve(k + 1, fim)) ;  
		// cout << solve(ini, k) << " " << solve(k+1, fim) << "\n" ;
	}

	// cout << ini << " " << fim << " " << ans << "\n" ; 

	return dp[ini][fim] = ans ; 
}

int main(){

	scanf("%d%lf", &n, &f) ; 

	for(int i = 1 ; i <= n ; i++){
		scanf("%d", &v[i]) ; 
		v[i+n] = v[i] ; 
	}

	for(int i = 1 ; i <= 2*n ; i++) pref[i] = pref[i-1] + v[i] ; 

	memset(dp, -1, sizeof dp) ; 

	int resp = inf ; 

	for(int i = 1 ; i <= n ; i++) resp = min(resp,  solve(i, n + i - 1)) ; 

	printf("%.2lf\n", f*resp) ; 
}
