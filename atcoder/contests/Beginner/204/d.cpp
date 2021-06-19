#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 110 ; 
const int maxm = 1e3 + 5 ; 
 
int n, dp[maxn][maxn*maxm], p[maxn], v[maxn] ; 
 
int solve(int i, int t1){
	if(i > n) return max(t1, p[n] - t1) ; 
	if(dp[i][t1] != -1) return dp[i][t1] ; 
	return dp[i][t1] = min(solve(i+1, t1+v[i]), solve(i+1, t1)) ; 
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i], p[i] = p[i-1] + v[i] ; 
 
	memset(dp, -1, sizeof dp) ; 
 
    cout << solve(1, 0) << "\n" ; 
 
