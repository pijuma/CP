#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 601 ; 

int a, b, n ; 
double dp[maxn][maxn] ; 

double solve(long long sum, int idx){

	if(dp[sum][idx] != -1) return dp[sum][idx] ;  
	if(idx == n) return (a <= sum && sum <= b) ; 
	double resp = 0 ; 
	for(int i = 1 ; i <= 6 ; i++) resp += solve(sum+i, idx+1)/6 ; 
	return dp[sum][idx] = resp ; 

}

int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d%d%d", &n, &a, &b); 

	for (int i = 0; i < 601; i++) for (int j = 0; j < 101; j++) dp[i][j] = -1;

    printf("%.6lf\n", solve(0, 0)) ;  

}
