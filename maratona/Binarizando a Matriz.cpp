#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 110 ; 
const int mod = 1e9 + 7 ; 

int n, m, v[maxn][maxn] ;
int ans, dp[maxn][maxn], ps0[maxn], ps1[maxn] ;
char g[maxn][maxn] ; 

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> g[i][j] ; 
		}
	}

	dp[1][m+1] = 1 ; 

	for(int i = 1 ; i <= n ; i++){
		
		memset(ps0, 0, sizeof ps0) ; memset(ps1, 0, sizeof ps1) ;
		
		for(int j = 1 ; j <= m ; j++){
			if(g[i][j] == '.') continue ; 
			ps0[j] = (g[i][j] == '0'), ps1[j] = (g[i][j] == '1') ; 
		}

		for(int j = 1 ; j <= m ; j++) ps0[j] += ps0[j-1], ps1[j] += ps1[j-1] ; 	

		for(int j = 1 ; j <= m + 1 ; j++){
			if(!dp[i][j]) continue ; 
			for(int k = 1 ; k <= j ; k++){
				int q0, q1 ;
				q0 = ps0[k-1] ; 
				q1 = ps1[m] - ps1[k-1] ; 
				if(!q0 && !q1){
					dp[i+1][k] = (dp[i+1][k] + dp[i][j])%mod ; 
				}
			}
		}

	}

	for(int i = 1 ; i <= m + 1 ; i++) ans = (ans + dp[n+1][i])%mod ; 

	cout << ans << "\n" ; 

}
