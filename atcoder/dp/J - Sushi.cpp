#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 305 ; 
const int inf = 1e9 ; 

int v[maxn], qtd[4], mark[maxn][maxn][maxn] ;
double dp[maxn][maxn][maxn], n ;

// p(qx) = qx/n 

double solve(int q1, int q2, int q3){ //qts rodadas esperadas p q1, q2, q3

	if(!q1 && !q2 && !q3) return 0 ; 
	if(q1 < 0 || q2 < 0 || q3 < 0) return 0 ; 

	if(mark[q1][q2][q3] != 0) return dp[q1][q2][q3] ; 

	double m = 1.0*(q1+q2+q3) ; 
	double wait = n/(m) ; 
	double c1 = (q1/(m)) ; 
	double c2 = q2/(m) ; 
	double c3 = q3/(m) ;

	mark[q1][q2][q3] = 1 ; 

	return dp[q1][q2][q3] = wait + (c1*solve(q1-1, q2, q3)) + (c2*solve(q1+1, q2-1, q3)) + (c3*solve(q1, q2+1, q3-1)) ; 


}

int main(){

	scanf("%lf", &n) ; 

	// memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++) scanf("%d", &v[i]) ;  //qts pratos de cada tipo 

	for(int i = 1 ; i <= n ; i++) qtd[v[i]]++ ; 

	printf("%.10lf\n", solve(qtd[1], qtd[2], qtd[3])) ; 

}
