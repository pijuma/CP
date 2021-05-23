#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 3e3 + 5 ; 

int n ; 
double v[maxn], c[maxn], dp[maxn][maxn] ; 

// dp[i][j] -> pos i com j p cima (i-j p baixo)
// no final tem q pegar tds as dp's com mais de n/2 p cima (quest fala)

int main(){

	scanf("%d",&n) ; 

	for(int i = 1 ; i <= n ; i++) scanf("%lf", &v[i]) ; 

	dp[0][0] = 1 ; 
    
    for(int i = 1 ; i <= n ; i++){
    	for(int j = 0 ; j <= i ; j++){
    		if(j) dp[i][j] += (v[i])*dp[i-1][j-1] + (1-v[i])*dp[i-1][j] ;
    		else dp[i][j] = (1 - v[i])*dp[i-1][j] ; 
    	}
    }

    double ans = 0 ; 

    for(int i = n ; i > n/2 ; i--) ans += dp[n][i] ; 

    printf("%.10lf\n", ans) ;

}
