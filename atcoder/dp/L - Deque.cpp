#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 3e3 + 5 ; 
const int inf = 1e18 ; 

int n, v[maxn], dp[maxn][maxn], sum ; 

int solve(int i, int j){

	if(dp[i][j] != -1) return dp[i][j] ; 

	if(i > j) return 0 ; 

	return dp[i][j] = max(v[i] + min(solve(i+2, j), solve(i+1, j-1)), v[j] + min(solve(i, j-2), solve(i+1, j-1))) ; 
	//queremos maximizar oq nós ganhamos minimizando o do outro cara 
}

int32_t main(){

	cin >> n ; 

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], sum += v[i] ;

	int x = solve(1, n) ; 
	int y = sum - x ; 
	int ans = x - y ; 

	cout << ans << "\n" ;

}
