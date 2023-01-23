#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 22 ; 
const int mod = 1e9 + 7 ;
 
int n, m[maxn][maxn], dp[maxn][(1<<maxn)] ;
 
int solve(int i, int mask){
 
	if(i >= n) return 1 ; 
 
	if(dp[i][mask] != -1) return dp[i][mask] ; 
	long long ans = 0 ; 
	for(int j = 0 ; j < n ; j++){
		if(mask&(1<<j) || !m[i][j]) continue ; 
		ans += solve(i+1, (mask|(1<<j))) ;
		if(ans >= mod) ans -= mod ; 
	}
 
	return dp[i][mask] = ans ;
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> m[i][j] ; 
		}
	}
 
	memset(dp, -1, sizeof dp) ; 
 
	cout << solve(0, 0) << "\n" ; 
 
}
