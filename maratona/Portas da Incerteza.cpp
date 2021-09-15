#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int mod = 1e9 + 7 ; 
const int maxn = 1e6 + 2 ; 

int n, f[maxn], x[maxn], y[maxn], dp[maxn][2][2] ; 

int get(int a, int b, int v){
	if(v == -1) return !(a&b) ;
	return v ;  
} 

void solve(int v){
	
	if(v == 0){
		dp[v][0][0] = dp[v][1][1] = 1 ;
		return ;   
	}

	solve(x[v]), solve(y[v]) ; 

	vector<int> vec = {0, 1} ; 

	for(auto a : vec){
		for(auto b : vec){
			for(auto c : vec){
				for(auto d : vec){
					int e = get(a, c, -1), g = get(b, d, f[v]) ; 
					dp[v][e][g] = (dp[v][e][g] + (dp[x[v]][a][b]*dp[y[v]][c][d]))%mod ;  
				}
			}
		}
	}

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i] >> f[i] ; 

	solve(1) ; 

	cout << (dp[1][0][1] + dp[1][1][0])%mod << "\n" ; 

}
