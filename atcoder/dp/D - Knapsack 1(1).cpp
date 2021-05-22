#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 1e5 + 5 ; 
const ll inf = 1e14 ; 

// dp[i] - qual maior valor dado um peso i
// otimizando memória 

ll dp[maxn], n, w, peso[maxn], valor[maxn] ; 

int main(){

	cin >> n >> w ; 

	for(int i = 1 ; i <= n ; i++) cin >> peso[i] >> valor[i] ; 

	for(int i = 1 ; i <= w ; i++) dp[i] = -inf ; 

	for(int i = 1 ; i <= n ; i++){
		
		for(int j = w ; j - peso[i] >= 0 ; j--){
			dp[j] = max(dp[j-peso[i]] + valor[i], dp[j]) ; 
		}

	}

	cout << *max_element(dp, dp + w + 1) << "\n" ; 
}
