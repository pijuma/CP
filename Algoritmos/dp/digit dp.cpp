#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// digit dp - maior prod 

int dp[12][2][3], n ;
vector<int> num ; 

int solve(int d, bool nonz, bool flag){

	if(d == num.size()) return 1 ;
	if(dp[d][nonz][flag] != -1) return dp[d][nonz][flag] ; 

	int tot = 1 ; 

	if(flag){ // coloca qlqr um 
		tot *= 9*solve(d+1, 1, flag) ; 
	}

	else{
		for(int i = 0 ; i < num[d] ; i++){
			if(i == 0 && nonz == 0) tot = max(tot, solve(d+1, 0, 1)) ;
			else tot = max(tot, i*solve(d+1, nonz|(i != 0), 1)) ;
		}
		tot = max(tot, num[d]*solve(d+1, nonz|(num[d] > 0), 0)) ; 
	}

	return dp[d][nonz][flag] = tot ; 

}

int calc(int x){

	while(x){
		num.push_back(x%10) ; 
		x /= 10 ; 
	}

	reverse(num.begin(), num.end()) ; 

	memset(dp, -1, sizeof dp) ; 

	return solve(0, 0, 0) ; 

}

int32_t main(){

	cin >> n ; 

	cout << calc(n) << "\n" ; 

}
