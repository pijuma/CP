#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 
const int inf = 1e9 ; 

vector<pair<int,int>> grafo[maxn] ; 
int dp[maxn][55], n, k ; 

void solve(int u, int p){

	for(int i = 2 ; i <= k ; i++) dp[u][i] = inf ; 

	for(auto atual : grafo[u]){
		
		if(atual.first == p) continue ; 

		solve(atual.first, u) ; 

		for(int i = k ; i >= 1 ; i--){
			for(int j = 1 ; j < i ; j++){
				dp[u][i] = min(dp[u][i], dp[atual.first][j] + atual.second + dp[u][i-j]) ; 
			}
		}

	}

}

int main(){

	cin >> n >> k ; 

	for(int i = 1, a, b, c ; i < n ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ; 
	}

	solve(1, 0) ; 

	int ans = inf ; 

	for(int i = 1 ; i <= n ; i++) ans = min(ans, dp[i][k]) ; 

	cout << ans << "\n" ; 

}
