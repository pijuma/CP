#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 
const int inf = 1e9 ; 

int n, k, c, dp[maxn][maxn], v[maxn], p[maxn] ;

int main(){

	cin >> n >> k >> c ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], p[i] = p[i-1] + v[i] ; 

	for(int i = 1 ; i <= k ; i++) dp[0][i] = inf ; 

	dp[0][0] = 0 ; 
    
    for(int i = 1 ; i <= n ; i++){
    	for(int j = 1 ; j <= k ; j++){
    		dp[i][j] = dp[i-1][j] ; // n colocar 
    		if(i >= c && j){
    			dp[i][j] = min(dp[i][j], dp[i-c][j-1] + p[i] - p[i-c]) ; // pego a soma dos caras q eu coloco 
    		}
    	}
    }

    cout << p[n] - dp[n][k] << "\n" ; 
}
