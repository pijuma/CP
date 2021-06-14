#include<bits/stdc++.h>
using namespace std ; 

const int maxm = 5e4 + 5 ; 
const int maxn = 1e5 + 5 ; 

int dp[maxm], n, m, peso[maxn], valor[maxn] ;

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++) cin >> peso[i] >> valor[i] ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = m ; j - peso[i] >= 0 ; j--) dp[j] = max(dp[j], dp[j-peso[i]] + valor[i]) ; 
	}
    
    cout << *max_element(dp, dp + m + 1) << "\n" ; 
    
}