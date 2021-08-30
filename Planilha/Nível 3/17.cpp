#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

// n lebres 
// a lebre irradia ai se nenhuma adjascente se alimentou 
// bi se apenas uma se alimentou 
// ci se ambas se alimentaram 

const int maxn = 3e3 + 5 ; 

int dp[maxn][3], n, a[maxn], b[maxn], c[maxn] ; 

int solve(int i, int s){
	
	if(dp[i][s] != -1) return dp[i][s] ; 
	if(i == n){
		if(s == 0) return a[i] ; 
		else return b[i] ; 
	}

	if(s == 0) return dp[i][s] = max(a[i] + solve(i + 1, 1), b[i] + solve(i + 1, 0)) ; 
	// o meu a esq n foi alimentado, o da dir pode ter sido ou n 
	// se n foi soma ai e passa p prox falando q o da esq foi 
	// se foi da dir soma bi e passa p dir falando q ele foi alimentado sem o da esq ter sido
	else return dp[i][s] = max(b[i] + solve(i + 1, 1), c[i] + solve(i + 1, 0)) ; 
	// similar 
}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; // nenhum 
	for(int i = 1 ; i <= n ; i++) cin >> b[i] ; // um 
	for(int i = 1 ; i <= n ; i++) cin >> c[i] ; // ambos 

	memset(dp, -1, sizeof dp) ; 

	cout << solve(1, 0) << "\n" ;

}
