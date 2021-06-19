#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int n, k ; 

int32_t main(){

	cin >> n >> k ; 

	while(k--){
		if(n%200 == 0) n /= 200 ; 
		else{
			string s ; 
			s = to_string(n) ; 
			s = s + "200" ; 
			n = stol(s) ; 
		}
	}

	cout <<  n << "\n" ; 

}