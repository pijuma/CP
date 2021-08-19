#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// bb no tempo 

const int maxn = 2e5 + 5 ; 
const int inf = 1e18 ; 

int n, t, v[maxn] ; 

bool check(int x){

	int resp = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		resp += (x/v[i]) ; 
		if(resp >= t) return 1 ; 
	} 

	return resp >= t ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	
	cin >> n >> t ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	int ini = 1, fim = inf, meio, best ; 
    
    while(ini <= fim){

    	meio = (ini + fim)>>1 ; 

    	if(check(meio)) best = meio, fim = meio - 1 ; 
    	else ini = meio + 1 ; 

    }

    cout << best << "\n" ; 

}
