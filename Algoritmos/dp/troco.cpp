#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, v[maxn], dp[maxn] ; 

int solve(int i, int x){

	if(x == 0) return 0 ; 
	if(x < 0) return maxn ; 
	if(i == n+1) return maxn ;

	if(dp[x] != -1) return dp[x] ; 

	return dp[x] = min(solve(i+1, x), solve(i + 1, x-v[i])) ;  

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	dp[0] = 0 ; 

	for(int i = 1 ; i <= m ; i++) dp[i] = maxn ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = m ; j - v[i] >= 0 ; j--) dp[j] = min(dp[j], dp[j-v[i]] + 1) ; 
	} 

    cout << dp[m] << "\n" ; 

}
