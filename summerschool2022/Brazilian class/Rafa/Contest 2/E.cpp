#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

string a, b ;
int n1, n2, t ; 

bool prime(int n){

	if(n == 1) return 0 ; 

	for(int i = 2 ; i * i <= n ; i++){
		if(n%i == 0) return 0 ; 
	}

	return 1 ; 

}

int32_t main(){

	cin >> t ; 

	while(t--){

		cin >> a >> b ;

		string aa = "", bb = "" ;

		for(int i = 0 ; i < a.size() ; i++){
			if(a[i] == '.') continue ; 
			aa += a[i] ; 
		}

		for(int i = 0 ; i < b.size() ; i++){
			if(b[i] == '.') continue ; 
			bb += b[i] ; 
		}

		int n1 = stoi(aa), n2 = stoi(bb) ; 
		
		if(a == b){
			cout << 2 << " " << 2 << "\n" ; 
		}

		else{
		// cout << n1 << " " << n2 << "\n" ; 

			int mdc = __gcd(n1, n2) ; 

			n1 /= mdc, n2 /= mdc ; 

			if(prime(n1) && prime(n2)) cout << n1 << " " << n2 << "\n" ; 
			else cout << "impossible\n" ; 
		}

	}

}
