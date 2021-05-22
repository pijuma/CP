#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, m, g[maxn][maxn], dp[maxn][maxn] ; 
char x ; 

int solve(int i, int j){
	if(i > n || j > m || !g[i][j]) return 0 ; 
	if(i == n && j == m) return 1 ; 
	if(dp[i][j] != -1) return dp[i][j] ;  
	return dp[i][j] = (solve(i+1, j) + solve(i, j+1))%mod ; 
}

int main(){

	cin >> n >> m ;

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> x ;
			g[i][j] = (x == '.' ? 1 : 0) ;   
		}
	}

	cout << solve(1, 1) << "\n" ; 

}
