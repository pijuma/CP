#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxn = 2e3 + 5 ; 
const int MAX = 1e5 + 5 ;
const int inf = 1e9 + 5 ; 
 
int n, p, q, v[maxn], dp[maxn][maxn] ; 
 
// dp[i][j] = k, k é a menor qtd de tp2 que indo de 1 a i eu consigo com até j tp1 
 
int find(int i, int d){
 
	int ini = 1, fim = i, mid, best = 0 ; 
 
	while(ini <= fim){
		
		mid = (ini + fim)>>1 ; 
 
		if(v[i] - v[mid] + 1 > d){
			best = mid ; 
			ini = mid + 1 ; 
		}
 
		else fim = mid - 1 ; 
 
	}
 
	return best ; 
 
}
 
int check(int w){
 
	memset(dp, inf, sizeof dp) ;
 
	for(int j = 0 ; j <= p ; j++) dp[0][j] = 0 ; 
 
	for(int i = 1 ; i <= n ; i++){
		int k1 = find(i, w), k2 = find(i, 2*w) ; // qual o 1o kra q eu n cubro colocando em mim com d dist 
		// cout << k1 << " " << k2 << " " << i << "\n" ; 
		for(int j = 0 ; j <= p ; j++){
			if(j - 1 < 0) dp[i][j] = dp[k2][j] + 1 ; 
			else dp[i][j] = min(dp[k1][j-1], dp[k2][j] + 1) ; 
			// cout << dp[k1][j-1] << " " << dp[k2][j] << "\n" ; 
		}
	}
 
	return dp[n][p] ;
 
}
 
int32_t main(){
 
	cin >> n >> p >> q ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	sort(v + 1, v + 1 + n) ; 

	if(p + q >= n){
		cout << 1 << "\n" ; 
		exit(0) ; 
	}
 
	int ini = 1, fim = inf , mid, best = -1 ; 
 
	// cout << check(3) << "\n"; 
 
	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(check(mid) <= q){
			// cout << mid << "\n" ; 
			best = mid, fim = mid - 1 ; 
		}
		else ini = mid + 1 ; 
	}
 
	cout << best << "\n" ; 
 
}
