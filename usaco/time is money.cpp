#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 
const int maxm = 510 ; 
const int inf = 1e9 ; 

int n, m, c, val[maxn], vis[maxn][maxm], dp[maxn][maxm] ; 
vector<int> grafo[maxn]  ;

int solve(int v, int t){

	if(t == 509) return -inf ; 
	int &ans = dp[v][t] ;
	if(vis[v][t]) return ans ;  
	vis[v][t] = 1 ; 
	ans = -inf ; 
	if(v == 1) ans = max(ans, -c*(t*t)) ; 
	for(auto a : grafo[v]){
		ans = max(ans, val[a] + solve(a, t+1)) ; 
	}

	return dp[v][t] = max(ans, dp[v][t]) ; 

}

int32_t main(){

	ifstream cin("time.in");
    ofstream cout("time.out");

	cin >> n >> m >> c ; 

	for(int i = 1 ; i <= n ; i++) cin >> val[i] ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b) ;
	}

	cout << max(0LL, solve(1, 0)) << "\n" ; 

}
