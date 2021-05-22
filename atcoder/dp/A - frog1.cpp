#include<bits/stdc++.h>
using namespace std ; 

// i-1, i-2, soma a dif entre os dois
// dp[i] - gasto min p chegar em i 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

int n, v[maxn] ; 
int dp[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

	for(int i = 1 ; i <= n ; i++) dp[i] = inf ; 
	
	dp[1] = 0, dp[0] = inf ; 

    for(int i = 2 ; i <= n ; i++) dp[i] = min(dp[i-1] + abs(v[i] - v[i-1]), dp[i-2] + abs(v[i] - v[i-2])) ;  

    cout << dp[n] << "\n" ; 

}
