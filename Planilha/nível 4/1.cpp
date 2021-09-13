#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e3 + 5 ; 

int d, n, v[maxn], dp[maxn], ans, mark[maxn] ; 
vector<int> grafo[maxn] ; 
int mx, mn ; 

const int mod = 1e9 + 7 ; 

void dfs(int i, int p, int menor, int id){

	mark[i] = dp[i] = 1 ; 

	for(auto a : grafo[i]){
		if(mark[a] || a == p) continue ; 
		if(v[a] < menor) continue ; 
		if(v[a] == menor && a > id) continue ; 
		if(v[a] - menor > d) continue ; 
		dfs(a, i, menor, id) ; 
		dp[i] = (dp[i] + (dp[i]*dp[a]))%mod ; 
	}

}

int32_t main(){

	cin >> d >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		memset(dp, 0, sizeof dp), memset(mark, 0, sizeof mark) ; 
		dfs(i, i, v[i], i) ; 
		ans = (ans + dp[i])%mod ; 
	}

	cout << ans << "\n" ; 

}
