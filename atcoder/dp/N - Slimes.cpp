#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 405 ; 
const int inf = 1e18 ; 

int n, dp[maxn][maxn], v[maxn], p[maxn] ; 

int solve(int l, int r){

	if(dp[l][r] != -1) return dp[l][r] ; 
	if(l == r) return 0 ; 

	int mn = inf ; 

	for(int i = l ; i < r ; i++){
		mn = min(mn, solve(l, i) + solve(i + 1, r) + p[r] - p[l-1]) ; // qd formos juntar vamos pegar a soma de tds 
		//de um lado com a soma de tds do outro -> usamos prefix sum
	}

	return dp[l][r] = mn ; 

}

int32_t main(){

	cin >> n ; 

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], p[i] = p[i-1] + v[i] ; 

	cout << solve(1, n) << "\n" ; 

}
