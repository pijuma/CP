#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 
const int mod = 1e9 + 7 ; 

int n, m, p[maxn], fac[maxn], v[maxn] ; 

int exp(int a, int b){
	
	int ans = 1 ;  

	while(b){
		if(b&1) ans = (ans*a)%mod ;
		a = (a*a)%mod ; 
		b >>= 1 ;  
	}
	
	return ans ; 

}

// ...#...#...
// AAA#BBB#CCC
// temos q acender 9 lamp - 9! formas 
// mas dentro do grupo tem ordens especificas -> a tem q começar dir
// C na esq 
// B tem duas formas de ligar cada lamp - 2^qtdB
// a unica coisa q muda eh a ordem entre os grupos portanto dividimos por qtdX!

int32_t main(){

	cin >> n >> m ; 

	fac[0] = 1, p[0] = 1 ; 

	for(int i = 1 ; i <= n ; i++){
		fac[i] = (fac[i-1]*i)%mod ; 
		p[i] = (p[i-1]*2)%mod ; 
	}

	for(int i = 1 ; i <= m ; i++) cin >> v[i] ; 

	sort(v + 1, v + 1 + m) ;

    int ans = fac[n - m] ; // n° lampa q preciso ligar 
    // precisa dividir pelas qtds dos grupos 
    // 1o e ultimo 

    ans = (ans*exp(fac[v[1] - 1], mod - 2))%mod ;
    ans = (ans*exp(fac[n - v[m]], mod - 2))%mod ; 

    for(int i = 2 ; i <= m ; i++){
    	ans = (ans*exp(fac[v[i] - v[i-1] - 1], mod - 2))%mod ; 
    	if(v[i] != v[i-1] + 1) ans = (ans*p[v[i] - v[i-1] - 2])%mod ; // 2 ops p cada - caso de estar entre
    }

    cout << ans << "\n" ; 

}
