// a*b sem usar bignum 
#include<bits/stdc++.h>
using namespace std ; 

const int mod = 1e9 + 7 ; 

long long a, b ; 

long long fmult(int a, int b){

	a %= mod ; 
	long long ans = 0 ; 

	while(b){
		if(b&1) ans = (ans + a)%mod ; 
		a = (2*a)%mod ; 
		b >>= 1 ; 
	}

	return ans ; 
	
}

int main(){

	cin >> a >> b ; 

	cout << fmult(a, b) << "\n" ; 

}
