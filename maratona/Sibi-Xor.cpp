#include<bits/stdc++.h>
using namespace std ; 

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 5 ; 

unsigned long long n, qtd[maxn], f[75], ans ; 

int main(){

	cin >> n ;
	
	for(int i = 1 ; i <= n ; i++){
		unsigned long long v = i ;
		unsigned long long q = 0 ; 
		while(v%2 == 0){
			q++ ; 
			v >>= 1 ; 
		}
		qtd[i] = qtd[i-1] + q ;
	}   


	for(int i = 1 ; i <= n ; i++){
		unsigned long long x ; 
		cin >> x ; 
		for(int j = 0 ; j < 64 ; j++){
			if((x&(1ULL<<j))) f[j]++ ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){ // fixa o k 
		for(int j = 0 ; j < 64 ; j++){
			if(f[j] < i) continue ; // fj escolhe i 
			// cout << i << " " << j << " " << f[j] << "\n" ;   
			if(qtd[f[j]] - (qtd[i] + qtd[f[j] - i]) == 0) ans = (ans + (1ULL<<j))%mod ; 
		}
	}

	cout << ans << "\n" ; 

}
