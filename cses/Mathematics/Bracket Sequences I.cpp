#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e6 + 5 ; 
const int mod = 1e9 + 7 ; 

int fac[maxn], inv[maxn], n, cat[maxn] ; 

int exp(int a, int b){

	int ans = 1 ; 

	a %= mod ; 

	while(b){
	    if(b&1) ans = (ans*a)%mod ; 
	    a = (a*a)%mod ; 
	    b >>= 1 ; 	
	}

	return ans ; 

}

void calc(){

	fac[0] = inv[0] = 1 ; 

	for(int i = 1 ; i <= maxn - 5 ; i++){
		fac[i] = (fac[i-1]*i)%mod ; 
		inv[i] = exp(fac[i], mod-2) ; 
	}

}

int solve(int n, int m) {return fac[n]*inv[m]%mod*inv[n-m]%mod ;} 

int32_t main(){

	cin >> n ; 

	if(n&1){
		cout << 0 << "\n" ;
		return 0 ; 
	}

	calc() ; 

	n /= 2 ; 

	cout << ((solve(2*n, n)%mod)*exp((n+1), mod-2))%mod << "\n" ; 

}
