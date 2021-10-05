#include<bits/stdc++.h>
#define int long long
using namespace std ;  

const int maxn = 2e6 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, m, dp[maxn], fat[maxn] ; 
vector<pair<int,int>> block ; 

long long exp(int a, int b){
	long long ans = 1 ; 
	while(b){
		if(b&1) ans = (ans*a)%mod ;
		a = (a*a)%mod ; 
		b >>= 1 ;  
	}
	return ans ; 
}

void make_fat(){
	fat[0] = 1;
	for (int i = 1; i <= 2*n ; i++) fat[i] = (fat[i-1]*i) % mod ; 
}

long long calc(int i, int j, int a, int b){
	int x = a - i, y = b - j ; 
	return (fat[x+y] * exp((fat[x]*fat[y])%mod, mod-2))%mod ;
}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> n >> m ; 

	make_fat() ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		block.push_back({a, b}) ; 
	}

	block.push_back({n, n}) ; 

	sort(block.begin(), block.end()) ; 

	for(int i = 0 ; i < block.size() ; i++){
		dp[i] = calc(1, 1, block[i].first, block[i].second) ; 
		for(int j = 0 ; j < i ; j++){
			if(block[j].second > block[i].second) continue ; 
			dp[i] = (dp[i] - (dp[j] * calc(block[j].first, block[j].second, block[i].first, block[i].second)%mod) + mod)%mod ; 
		}
	}

	cout << dp[block.size() - 1] << "\n" ; 

}
