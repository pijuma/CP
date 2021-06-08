#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

struct p{
	int xi, xf, yi, yf ; 
} ; 

int n, k ; 
p v[maxn] ; 

bool check(int h){

	int ans = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(v[i].yi < h){
			ans += (abs(v[i].xf - v[i].xi))*abs((min(h, v[i].yf) - v[i].yi)) ; 
		}
	}

	return ans >= k ; 

}

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i].xi >> v[i].yi >> v[i].xf >> v[i].yf ; 

	int ini = -inf, fim = inf, mid, best = inf ; 
    
    while(ini <= fim){
    	mid = (ini + fim) >> 1 ; 
    	if(check(mid)){
    		best = mid ; 
    		fim = mid - 1 ; 
    	}
    	else ini = mid + 1 ; 
    }

    if(best == inf) cout << "PERDAO MEU REI\n" ;
    else cout << best << "\n" ; 

}
