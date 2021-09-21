#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e4 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, dp[maxn] ;
// dp[i] -> formas de fzr com i colunas 
int32_t main(){

	cin >> n ; 
	
	dp[1] = dp[0] = 1, dp[2] = 5 ; 

	for(int i = 3 ; i <= n ; i++){
		dp[i] = (dp[i-1] + 2*dp[i-3] + 4*dp[i-2])%mod ; 
	}

	cout << dp[n] << "\n" ; 

}
