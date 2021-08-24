// D - Gargari and Permutations 
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, k, a, pos[maxn][6], resp, dp[maxn] ; 

int solve(int val){
	
	if(dp[val] != -1) return dp[val] ; 

	int ans = 0 ; 
	vector<int> okay ; 

	for(int i = 1 ; i <= n ; i++){
		int ct = 0 ; 
		for(int j = 1 ; j <= k ; j++){
			if(pos[i][j] > pos[val][j]) ct++ ; 
		}
		if(ct == k) okay.push_back(i) ; // i fica dps de val em tds as seqs 
	}

	for(int i = 0 ; i < okay.size() ; i++) ans = max(ans, solve(okay[i]) + 1) ; // qual prox mlr ? 
	return dp[val] = ans ; 

}

// dp[i] -> se começar com o val i qual a maior lcs q eu consigo ?
int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= k ; i++){
		for(int j = 1 ; j <= n ; j++){
			int a ; 
			cin >> a ; 
			pos[a][i] = j ; 
		}
	}

	memset(dp, -1, sizeof dp) ; 

	for(int i = 1 ; i <= n ; i++) resp = max(resp, solve(i) + 1) ; //começa com i 
	cout << resp << "\n" ; 

}
