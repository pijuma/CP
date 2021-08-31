#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int c, n, ps[maxn] ; 

int main(){

	cin >> c >> n ; 

	for(int i = 0 ; i < n ; i++){
		int a ; 
		cin >> a ; 
		ps[a]++ ; 
	}

	for(int i = 1 ; i < c ; i++) ps[i] += ps[i-1] ; 

	int mx = c/n ; 

	for(int i = 0 ; i < mx ; i++){
		
		bool ok = 1 ; 

		for(int j = 0 ; j < n - 1 ; j++){
			if(ps[i + (j*mx) - 1] + 1 != ps[i + ((j+1)*mx) - 1]){
				ok = 0 ; 
				break ; 
			} 
		}

		if(ok) cout << "S\n", exit(0) ; 

	}

	cout << "N\n" ;

}
