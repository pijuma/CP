#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 110 ; 
const int mod = 1e9 + 7 ; 

int n, k, d, dp[maxn][2] ; 

int solve(int s, bool ok){

	if(s > n) return 0 ;
	if(s == n) return ok ; 

	if(dp[s][ok] != -1) return dp[s][ok] ; 

	int ans = 0 ; 

	for(int i = 1 ; i <= k ; i++)  ans = (ans + solve(s+i, ok|(i>=d))%mod)%mod ; 

	return dp[s][ok] = ans ; 

}

int32_t main(){

	cin >> n >> k >> d ; 

	memset(dp, -1, sizeof dp) ; 

	cout << solve(0, 0) << "\n" ; 

}
