#include<bits/stdc++.h>
#define int long long
#define ll long long 
 
using namespace std ; 
 
vector<int> primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37} ;
 
int crivo(ll numb){
	
	ll ct = 1 ; 
	
	while(numb%2 == 0){
		ct++ ; 
		numb >>= 1 ; 
	}
 
	for(int i = 3 ; i * i <= numb ; i+=2){
		while(numb%i == 0){
			numb /= i ; 
			ct++ ; 
		}
	}
 
	if(numb > 2) ct++ ; 
 
	return ct ; 
 
}
 
int mult(int a, int b, int mod){
	
	int res = 0 ; 
 
	while(b){
		if(b&1) res = (res + a)%mod ; 
		a = (a+a)%mod ; 
		b >>= 1 ; 
	}
 
	return res ; 
 
}
 
ll _pow(ll a, ll b, ll mod){
	
	ll res = 1 ; 
 
	b %= mod ; 
 
	while(b){
		if(b&1) res = mult(res, a, mod) ; 
		a = mult(a, a, mod) ; 
		b >>= 1 ; 
	}
 
	return res ; 
 
}
 
bool check_comp(ll n, ll a, ll d, ll r){
 
	ll x = _pow(a, d, n) ; 
 
	if(x == 1 || x == n-1) return false ; 
 
	for(int i = 1 ; i < r ; i++){
		x = mult(x, x, n) ; 
		if(x == n-1) return false ; 
	}
 
	return true ; 
 
}
 
bool primo(ll n){
 
	if(n < 2) return false ; 
 
	int r = 0 ; 
	int d = n - 1 ; 
 
	// fatora -> 2^r * d -> d impar 
	// a^(2^r * d) = 0 mod n -> fatora ... 
	// a^(2^r-1 * d)....(a^d + 1)(a^d - 1) = 0 mod n 
	// se n eh primo precisa ser vdd logo precisa dividir algum dos fatores para qlqr a 
	// checa a^d = 1 mod n ou a^(2^r * d) = -1 mod n -> n - 1
 
	while(d%2 == 0){
		r++ ; 
		d >>= 1 ; 
	}
 
	for(int a : primos){
		if(a == n) return true ; 
		if(check_comp(n, a, d, r)) return false ; 
	}
 
	return true ; 
 
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	int t ; 
	ll n ; 
	
	cin >> t ; 
	
	while(t--){
	    cin >> n ;
        cout << (primo(n) ? "YES\n" : "NO\n") ; 
	}
	
 
}
