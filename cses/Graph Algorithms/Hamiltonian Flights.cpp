#include<bits/stdc++.h>
using namespace std ; 
#define int long long 
const int maxn = 22 ; 
const int mod = 1e9 + 7 ; 
 
int n, m, a, b, ans, dp[maxn][(1<<maxn)] ;   
vector<int> grafo[maxn] ; 
 
int32_t main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ;
		a--, b-- ; 
		grafo[a].push_back(b) ; 
	}
 
	dp[0][1] = 1 ; 
 
	for(int mask = 0 ; mask < (1<<n) ; mask++){
		if((1<<n)-1 != mask && (mask&(1<<(n-1)))) continue ; 
		for(int j = 0 ; j < n ; j++){
			if(!(mask&(1<<j))) continue ; 
			for(int f : grafo[j]){
				if((mask&(1<<f))) continue ; 
				dp[f][mask|(1<<f)] += dp[j][mask] ; 
				if(dp[f][mask|(1<<f)] >= mod) dp[f][mask|(1<<f)] -= mod ; 
			}
		}
	}
 
	cout << dp[n-1][(1<<n)-1] << "\n" ; 
 
}
