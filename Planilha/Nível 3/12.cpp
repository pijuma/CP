#include<bits/stdc++.h>
#define ll long long 
using namespace std ; 

const int maxn = 2e3 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, k ; 
ll dp[maxn][maxn], ans ; 

ll solve(int i, int k){
	
	if(dp[i][k] != -1) return dp[i][k] ; 
	if(k == 0) return 1 ; 
	int resp = 0 ; 
	
	for(int j = 1 ; j * j <= i ; j++){
		if(i%j) continue ; 
		resp = (resp + solve(j, k-1))%mod ; 
		if(i/j != j) resp = (resp + solve(i/j, k-1))%mod ;
	}

	return dp[i][k] = resp ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> k ; 

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++) ans = (ans + solve(i, k-1))%mod ; // fixa o 1o 

	cout << ans << "\n" ; 

}
