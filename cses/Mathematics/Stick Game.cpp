#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 1e6 + 5 ; 
 
int n, k, v[maxn] ;
bool dp[maxn] ; 
 
int main(){
 
	cin >> n >> k ; 
 
	for(int i = 1 ; i <= k ; i++) cin >> v[i] ; 
 
	dp[0] = 0 ; 
 
	for(int i = 1 ; i <= n ; i++){
		bool win = 1 ; 
		for(int j = 1 ; j <= k ; j++){ 
			if(v[j] > i) continue ;
			win &= dp[i-v[j]] ;  
		}
		dp[i] = !win ; 
	}
 
	for(int i = 1 ; i <= n ; i++) cout << (dp[i] ? "W" : "L" ) ; 
	cout << "\n" ; 
 
}
