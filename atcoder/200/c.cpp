#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, a[maxn], m, f[220] ;

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ; 
		f[a[i]%200]++ ; 
	} 

	for(int i = 0 ; i <= 200 ; i++){
		 m += f[i]*(f[i] - 1)/2 ;  
	}

	cout << m << "\n" ; 

}