#include<bits/stdc++.h>
using namespace std ; 
 
int C, W, v[22] ; 
pair<int,int> dp[(1<<22)] ; 
 
int main(){
 
	cin >> C >> W ; 
 
	for(int i = 0 ; i < C ; i++) cin >> v[i] ; 
 
	dp[0] = {0, W+1} ; 
 
	for(int mask = 1 ; mask < (1<<C) ; mask++){
		dp[mask] = {22, 0} ; 
		for(int i = 0 ; i < C ; i++){
			if(!(mask>>i&1)) continue ; 
			int w = dp[mask^(1<<i)].second, s = dp[mask^(1<<i)].first ; 
			if(w + v[i] > W){
				s++ ; 
				w = min(w, v[i]) ; 
			}
			else{
				w += v[i] ; 
			}
			dp[mask] = min(dp[mask], {s, w}) ; 
		}
	}
 
	cout << dp[(1<<C)-1].first << "\n" ; 
}
