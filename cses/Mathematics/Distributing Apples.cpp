#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 3e6 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, m, inv[maxn], fac[maxn] ; 

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

void solve(){
	
	fac[0] = inv[0] = 1 ; 

	for(int i = 1 ; i <= maxn - 5 ; i++){
		fac[i] = (i*fac[i-1])%mod ; 
		inv[i] = exp(fac[i], mod - 2) ; 
	}

}

int32_t main(){

	cin >> n >> m ; 

	solve() ; 

	int ans = (((fac[n+m-1]*inv[n-1])%mod)*inv[m])%mod ; 
	cout << ans << "\n" ; 

}
