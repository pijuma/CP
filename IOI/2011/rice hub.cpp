#include<bits/stdc++.h>
// #include <ricehub.h>

#define pii pair<int,int> 
#define f first 
#define ll long long 
#define s second 
#define pb push_back

using namespace std ; 

const int maxn = 1e5 + 5 ; 

ll n, mx, p[maxn], num[maxn], qtd, indbest ; 

bool ok(int k){

	if(k == 1) return true ; 

	cout << "com k = " << k << ":\n" ;

	ll c = p[k] - p[1] -((k-1)*num[1]) ;
	indbest = 1 ; 

	for(int i = 2 ; i <= k ; i++){ 
		
		ll ans = p[k] - p[i] - ((k-i)*num[i]) + ((i - 1)*num[i]) - p[i-1] ; 

		if(ans <= c) c = ans, indbest = i ; 

		cout << i << " " << k-i << " " << ans << "\n" ;  

	}  

	if(c <= mx) return true ;

	for(int i = k+1 ; i <= qtd ; i++){

		c -= (num[indbest] - num[i-k]), c += (num[i] - num[indbest]) ; 
		int j = indbest + 1 ; 

		ll ans = (j-(i-k+1))*num[j] - p[j-1] + p[i-k] + p[i] - p[j] - (i-j)*num[j] ; 
		
		if(ans <= c) c = ans, indbest = j ; 

		cout << i << " " << j << " " << ans << "\n" ; 

		if(c <= mx) return true ; 
	} 

	return false ; 

}

int bb(){

	int ini = 1, fim = qtd ;  
	int best = 1, mid ; 

	while(ini <= fim){
		
		mid = (ini + fim)/2 ; 

		if(ok(mid)){
			best = mid ; 
			ini = mid + 1 ; 
		}

		else fim = mid - 1 ; 
	
	}

	return best ; 

}

void besthub(int R, int L, int x[maxn], ll B){

	mx = B, qtd = R ; 

	for(int i = 1 ; i <= R ; i++){
		num[i] = x[i-1] ; 
		p[i] = p[i-1] + num[i] ; 
	}

	// return bb() ; 

	cout << bb() << "\n" ; 
}

int main(){

	int m[5] = {1, 2, 10, 12, 14} ; 
	besthub(5, 20, m, 6) ; 

}
