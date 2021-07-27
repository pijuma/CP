#include<bits/stdc++.h>

#define int long long 

using namespace std ; 

void fac(int n){

	int ct = 0 ; 

	while(n%2 == 0){
		ct++ ; 
		n /= 2 ;
	}

	if(ct) cout << "2^" << ct << " " ; 

	for(int i = 3 ; i * i <= n ; i+=2){
		
		ct = 0 ; 

		while(n%i == 0){
			ct++ ; n /= i ; 
		}

		if(ct) cout << i << "^" << ct << " " ; 

	}

	if(n > 2) cout << n << "^" << 1 << " " ;   

	return ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	while(true){
		
		int n ; 

		cin >> n ; 
		if(!n) break ; 

		fac(n) ; 

		cout << "\n" ; 
		
	}

}
