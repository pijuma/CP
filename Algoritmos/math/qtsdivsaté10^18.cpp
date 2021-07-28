// achar a qtd de divs em raiz cubica + miller rabin p ver se é primo + crivo 
#include<bits/stdc++.h>
#define int long long
#define ll long long 
 
using namespace std ; 
 
vector<int> primos = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37} ;
map<int,int> freq ;

int crivo(ll numb){
	
	ll ct = 1 ; 
	
	vector<long long> div ; 
	
	while(numb%2 == 0){
		div.push_back(2) ; 
		numb >>= 1 ; 
	}
 
	for(int i = 3 ; i * i <= numb ; i+=2){
		while(numb%i == 0){
			numb /= i ; 
			div.push_back(i) ; 
		}
	}
 
	if(numb > 2) div.push_back(numb) ; 
	
	for(int i = 0 ; i < div.size() ; i++) freq[div[i]] = 0 ;
	for(int i = 0 ; i < div.size() ; i++) freq[div[i]]++ ;
	
	sort(div.begin(), div.end()) ;
	div.erase(unique(div.begin(), div.end()), div.end()) ;
	
	for(int i = 0 ; i < div.size() ; i++) ct = (ct*(freq[div[i]] + 1)) ; 
	
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
 
int divs(ll numb){
 
	// 3 ops -> primo -> 2, primo^2 -> 3, p1*p2 -> 4 

    if(numb == 1) return 1 ;
	if(primo(numb)) return 2 ; 
 
	int sq = sqrt(numb) ; 
 
	if(sq*sq == numb) return 3 ; 
 
	return 4 ; 
 
}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	ll n ; 
 
	cin >> n ; 
	
	ll q = 1, p = 1 ; // p <= raiz cub, q > 
	ll num = n, fim = 1 ; 
 
	for(int i = 2 ; i * i * i <= num ; i++){
		while(num%i == 0){
			p *= i ; 
			num /= i ; 
		}
		fim = i ; 
	} 
 
	q = num ; 
 
	int qtdp = 0, qtdq = 0 ; //qts divisores p e q tem 
	// como gcd(p, q) = 1, n°div(n) = n°div(p)*n°div(q) 
 
	qtdp = crivo(p) ; 
 
	qtdq = divs(q) ; 
	
	// cout << p << " " << qtdp << " " << qtdq << " " << q << "\n" ; 
 
	cout << qtdp*qtdq << "\n" ; 
 
}
