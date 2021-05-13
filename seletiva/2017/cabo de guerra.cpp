#include<bits/stdc++.h>
using namespace std ;

const int maxn = 55 ; 

int n, v[maxn], st, dp[maxn][maxn*maxn][maxn/2] ; 
//dp[i][x][qtd] -> até a pos i com x de soma pro time a menor diff eh a dp usando qtd caras 

int solve(int i, int soma, int qtd){

	if(i > n) return (qtd == 0 ? abs(st - 2*soma) : 0x3f3f3f3f)  ;
	if(dp[i][soma][qtd] != -1) return dp[i][soma][qtd] ; 
	return dp[i][soma][qtd] = min(solve(i+1, soma + v[i], qtd - 1), solve(i+1, soma, qtd)) ; 
	//mlr caso eh pegar ou n pegar? 
}

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], st += v[i] ;

	memset(dp, -1, sizeof dp) ; 

	cout << solve(1, 0, n/2) << "\n" ; 

}
