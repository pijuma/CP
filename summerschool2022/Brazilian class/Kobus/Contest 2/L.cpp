#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 64 ;

int dp[maxn], n ; 

int main(){

	cin >> n ;

	if(n == 1 || n&1){
		cout << 0 << "\n" ; exit(0) ; 
	} 
	
	cout << (1<<(n/2)) << "\n" ; 

}
