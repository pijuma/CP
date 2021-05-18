#include<bits/stdc++.h>

#define ll long long 

using namespace std ; 

const int maxn = 502 ; 
const ll mod = 1e9 + 7 ; 

int n ; 
ll dp[maxn*maxn] ; 

int main(){

	cin >> n ; 

	ll sum = (n*(n+1))/2 ;

	if(sum%2){
		cout << "0\n" ; 
		return 0 ; 
	}  

	sum /= 2 ; 

	dp[0] = 1 ; 

	for(int i = 1 ; i < n ; i++){
		for(int j = sum ; j >= i ; j--){
			dp[j] = (dp[j] + dp[j-i])%mod ; 
		}
	}

	cout << dp[sum] << "\n" ; 

}
