// dado um l, um r e um m diga qual a resp da multiplicacao de l a r modulo m 
#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int MAX = 110 ; 

int n, t, v[maxn], f[maxn][MAX], primo[maxn] ; 
vector<int> primos ; 

void crivo(){
	
	for(int i = 1 ; i <= MAX ; i++) primo[i] = -1 ; 

	for(int i = 2 ; i <= MAX ; i++){
		if(primo[i] == -1){
			primo[i] = 1 ; 
			primos.push_back(i) ; 
			for(int j = i ; j <= MAX ; j += i) primo[j] = 0 ; 
		}
	}

}

int exp(int a, int b, int mod){

	int ans = 1 ;  

	while(b){
		if(b&1) ans = (ans*a)%mod ; 
		a = (a*a)%mod ; 
		b >>= 1 ; 
	}

	return ans ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){

		cin >> v[i] ;
		int x = v[i] ; 

		for(int j = 2 ; j * j <= x ; j++){
			while(x%j == 0){
				f[i][j]++ ; 
				x /= j ; 
			}
		}

		if(x > 1) f[i][x]++ ;  

	} 

	crivo() ; 

	for(int i = 1 ; i <= n ; i++){
		for(auto j : primos){
			f[i][j] += f[i-1][j] ; 
		}
	}

	cin >> t ;

	while(t--){
		
		int l, r, m ; 

		cin >> l >> r >> m ; 

		int ans = 1 ; 

		for(int i = 0 ; i < primos.size() ; i++){
			ans = (ans*exp(primos[i], f[r][primos[i]] - f[l-1][primos[i]], m))%m ; 
		}

		cout << ans << "\n" ; 

	}

}
