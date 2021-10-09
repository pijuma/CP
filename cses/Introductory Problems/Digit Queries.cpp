#include<bits/stdc++.h>
#define int long long
using namespace std ; 

long long q, k ; 

int LOG(long long x){
    int resp = 0 ;
    while (x) x/=10, ++resp ;
    return resp ;
}

int check(int x){

	int tot = 0, y = 1, l = LOG(x) ; 

	for(int i = 1 ; i <= l ; i++){
		tot += (x-y+1) ; y *= 10 ; 
	}

	return tot ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> q ; 

	while(q--){
		
		cin >> k ; 

		long long ini = 1, fim = k, mid, best = 0 ; 

		while(ini <= fim){
			mid = (ini + fim)>>1 ;
			if(check(mid) >= k) best = mid, fim = mid - 1 ; 
			else ini = mid + 1 ;  
		}

		long long resto = check(best) - k ; 

		while(resto--) best /= 10 ; 

		cout << best%10 << "\n" ; 

	}

}
