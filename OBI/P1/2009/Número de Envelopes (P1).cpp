#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, k, a, f[maxn] ; 

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> a, f[a]++ ; 

	int mn = (int) 1e9 ; 

	for(int i = 1 ; i <= k ; i++){
		if(f[i] < mn) mn = f[i] ; 
	}

	cout << mn << "\n" ; 

}
