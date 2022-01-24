#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int inf = 1e9 ; 
const int maxn = 1e5 + 5 ; 

int n, t, c, qtd, x[maxn] ; 

bool test(long long d){
	
	qtd = 0 ; 

	// cout << d << " " ;  

	for(int i = 1 ; i <= n ; i++){
		qtd++ ; 
		int j = i ; 
		while(j <= n && abs(x[j] - x[i]) < d) j++ ; 
		i = j - 1 ; 
	}

	// cout << qtd << "\n" ; 

	return (qtd >= c) ; 

}

int32_t main(){

	cin >> t ; 

	while(t--){
		
		cin >> n >> c ; 

		for(int i = 1 ; i <= n ; i++) cin >> x[i] ; 

		sort(x + 1, x + n + 1) ; 

	    long long ini = 1, fim = inf, mid, best = 0 ; 

	    while(ini <= fim){
	    	mid = (ini + fim)/2 ;  
	    	if(test(mid)){
	    		best = mid ; 
	    		ini = mid + 1 ; 
	    	}
	    	else fim = mid - 1 ; 
	    }


	    cout << best << "\n" ; 

	}

}
