#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e4 + 5 ;

int a, n, v[maxn], qtd ; 

int32_t main(){

	cin >> a ; 
	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++){
		if(v[i]*a >= 40000000) qtd++ ; 
	}

	cout << qtd << "\n" ; 

}
