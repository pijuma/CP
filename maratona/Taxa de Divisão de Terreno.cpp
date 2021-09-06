#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 205 ; 
const int inf = 1e9 ; 

int n, v[maxn], resp, ps[maxn], dp[maxn][maxn] ; 
double f ; 

int solve(int i, int j){
	
	if(dp[i][j] != -1) return dp[i][j] ; 
	if(i == j) return 0 ; 

	int ans = inf ; 

	for(int k = i ; k < j ; k++) ans = min(ans, solve(i, k) + solve(k + 1, j) + max(ps[k] - ps[i-1], ps[j] - ps[k])) ;

	return dp[i][j] = ans ;

}

int main(){

	while(true){
		
		scanf("%d%lf", &n, &f) ;
		if(!f && !n) return 0 ; 
		
		for(int i = 1 ; i <= n ; i++) scanf("%d", &v[i]) ;
		for(int i = 1 ; i <= n ; i++) ps[i] = ps[i-1] + v[i] ; 
		for(int i = 1 ; i <= n ; i++) ps[i+n] = ps[i-1+n] + v[i] ; 

		memset(dp, -1, sizeof dp) ; 
	    int resp = inf ; 

	    for(int i = 1 ; i <= n ; i++) resp = min(resp, solve(i, n + i - 1)) ; 

	    printf("%.2lf\n", f*resp) ; 

	}

}
