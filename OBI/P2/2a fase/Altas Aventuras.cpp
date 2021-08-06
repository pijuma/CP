#include<bits/stdc++.h>
using namespace std ; 

const int maxans = 1e5 + 5 ; 
const int maxk = 33 ; 

int n, dp[maxans][maxk], k ; 

// dp[x][k] -> qual o maior n dado que a resp é <= x e temos k balões 

int main(){

	cin >> n >> k ; 

	if(k == 1){
		cout << n << "\n" ; 
		return 0 ; 
	}

	k = min(k, 30) ; 

	for(int i = 0 ; i <= maxans ; i++) dp[i][1] = i ;

	for(int i = 1 ; i <= maxans ; i++){

		for(int j = 1 ; j <= k ; j++){
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + 1 ; 
		}

	} 

	for(int i = 1 ; i <= maxans ; i++){
		
		if(dp[i][k] >= n){
			cout << i << "\n" ; 
			return 0 ; 
		}

	}

	cout << "0\n" ; 

}
