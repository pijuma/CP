#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 55 ; 

int n, k, p[maxn], dig[maxn], mxpes, mnpes, dp[maxn][maxn][2] ; 

// digit dp 

void decomp(int x){
	for(int i = n ; i > 0 ; i--){
		if(x >= p[i]) x -= p[i], dig[i] = 1 ; //usar o cara i 
		else dig[i] = 0 ; 
	}
}

int solve2(int i, int qtd, bool ok){

	if(i == 0) return qtd == k ; 

	int& ans = dp[i][qtd][ok] ; 

	if(ans != -1) return ans ; 

	ans = 0 ; 

	int fim = (ok ? dig[i] : 1) ; 

	for(int j = 0 ; j <= fim ; j++) ans += solve2(i-1, qtd+j, ok&(j == fim)) ; //usar ou n usar 
	// se eu n to ok é pq eu já reduzi o valor em algum ent pss escolher usar 

	return ans ; 

}

int solve(int x){

	memset(dp, -1, sizeof dp) ; 
	decomp(x) ; 
	return solve2(n, 0, 1) ; 

}

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i] ; 
	sort(p + 1, p + 1 + n) ; 
	cin >> mnpes >> mxpes ; 

	cout << solve(mxpes) - solve(mnpes - 1) << "\n" ; 

}
