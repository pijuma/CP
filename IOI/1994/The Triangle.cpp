#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 110 ; 

long long  n, dp[maxn][maxn], m[maxn][maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			cin >> m[i][j] ; 
		}
	}

	dp[1][1] = m[1][1] ; 

	for(int i = 2 ; i <= n ; i++){
		for(int j = 1 ; j <= i ; j++){
			dp[i][j] = max({dp[i-1][j], dp[i-1][j-1]}) + m[i][j] ; 
		}
	}

	long long ans = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		ans = max(ans, dp[n][i]); 
	}

	cout << ans << "\n" ; 

}
