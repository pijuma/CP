#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxm = 110 ; 
const int maxn = 1e5 + 5 ; 
const ll inf = 1e14 ; 

// dp[i] - qual maior valor dado um peso i
// otimizando memória 

ll dp[maxm][maxn], n, w, peso[maxn], valor[maxn] ; 

int main(){

	cin >> n >> w ; 

	for(int i = 1 ; i <= n ; i++) cin >> peso[i] >> valor[i] ; 

	for(int i = 1 ; i <= w ; i++) dp[0][i] = -inf ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = w ; j >= 0 ; j--) dp[i][j] = dp[i-1][j] ; 
		for(int j = w ; j - peso[i] >= 0 ; j--) dp[i][j] = max(dp[i][j], dp[i-1][j-peso[i]] + valor[i]) ; 
	}
    
    ll ans = 0 ; 
    for(int i = 1 ; i <= w ; i++) ans = max(ans, dp[n][i]) ; 
    cout << ans << "\n" ; 

}
