#include<bits/stdc++.h>
using namespace std ; 

// qual dos k anteriores é mlr? 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

int n, k, dp[maxn], v[maxn] ; 

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++) dp[i] = inf ; 

	dp[0] = inf, dp[1] = 0 ; 
    
    for(int i = 2 ; i <= n ; i++){
    	for(int j = i - 1 ; j > max(0, i - k - 1) ; j--){
    		dp[i] = min(dp[i], dp[j] + abs(v[i] - v[j])) ; 
    	}
    }

    cout << dp[n] << "\n" ; 

}
