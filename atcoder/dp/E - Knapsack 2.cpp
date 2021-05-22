#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

// dp[i] - menor peso p conserguir o valor i 

const int maxn = 110 ; 
const int maxv = 1e5 + 5 ; 
const ll inf = 1e18 ; 

ll n, p, peso[maxn], valor[maxn], dp[maxn][maxv], max_val ; 

int main(){

	cin >> n >> p ; 

	for(int i = 1 ; i <= n ; i++) cin >> peso[i] >> valor[i] ; 

	for(int i = 1 ; i <= n ; i++) max_val += valor[i] ;

	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= max_val ; j++){
			dp[i][j] = inf ; 
		}
	}

	dp[0][0] = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= max_val ; j++){
			ll coloca = inf ; 
			if(j - valor[i] >= 0) coloca = dp[i-1][j-valor[i]] + peso[i] ; 
			dp[i][j] = min(coloca, dp[i-1][j]) ;    
		}
	} 

	for(int i = n ; i >= 0 ; i--){
		for(int j = max_val ; j >= 0 ; j--){
			if(dp[i][j] <= p){
				cout << j << "\n" ; 
				return 0 ; 
			}
		}
	} 

}
