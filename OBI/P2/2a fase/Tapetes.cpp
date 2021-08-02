#include<bits/stdc++.h>
#define int long long 

using namespace std ; 

int n, l ; 

int32_t main(){

	cin >> l >> n ; 

	if(n > l) cout << "-1\n" ; 
	else{
		int sz = l - (n-1) ; 
		cout << (sz*sz) + (n-1) << "\n" ; 
	}

}
