#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int inf = 1e9 ; 
const int maxn = 210 ; 

int t, n, p[maxn], c[maxn] ;
int dp[maxn][maxn][maxn] ; 

int solve(int i, int lp, int lc){

	if(i > n) return 0 ; 
	if(dp[i][lp][lc] != -1) return dp[i][lp][lc] ; 

	int &ans = dp[i][lp][lc] ; 

	ans = solve(i+1, lp, lc) ; 

	if(c[i] < lc && p[i] > lp) ans = max(ans, solve(i+1, p[i], c[i]) + 1) ; 

	return ans ; 

}

int toint(string s){

	int qtd = s.size() - 2 ; 
	int pot = 1 ; 

	while(qtd){
		pot *= 10 ; 
		qtd-- ; 
	}

	int ans = 0 ; 

	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '.') continue ; 
		ans += (s[i]-'0')*(pot) ; 
		// cout << s[i] << " " << pot << "\n" ; 
		pot /= 10 ; 
	}

	return ans ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> t ; 

	while(t--){
		
		cin >> n ; 

		memset(dp, -1, sizeof dp) ; 

		for(int i = 1 ; i <= n ; i++){
			string ww, cc ; 
			cin >> ww >> cc ; 
			c[i] = toint(cc), p[i] = toint(ww) ;
			p[i]++ ;  
			// cout << p[i] << " " << c[i] << "\n" ; 
		} 

		cout << solve(1, 0, 101) << "\n" ; 
	}

}
