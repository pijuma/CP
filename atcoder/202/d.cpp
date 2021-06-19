#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

int a, b, k, dp[34][34] ; 
string w ; 

// dp[i][j] -> n° strings que tem i a's e j b's

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> a >> b >> k ; 

	dp[0][0] = 1 ; 
	
	for(int i = 0 ; i <= a ; i++){
		for(int j = 0 ; j <= b ; j++){
			if(i > 0) dp[i][j] += dp[i-1][j] ; 
			if(j > 0) dp[i][j] += dp[i][j-1] ; 
		}
	}

	int A = a, B = b ; 

	while(A > 0 && B > 0){
		if(k <= dp[A-1][B]){
			cout << "a" ; 
			A-- ; 
		}
		else{
			k -= dp[A-1][B] ; 
			cout << "b" ; 
			B-- ; 
		}
	}

	for(int i = 1 ; i <= A ; i++) cout << "a" ; 
	for(int i = 1 ; i <= B ; i++) cout << "b" ; 

	cout << "\n" ; 

}