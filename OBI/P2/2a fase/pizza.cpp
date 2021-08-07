#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, maior, resp, resp2, maior2, v[maxn], soma, vec[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> v[i] ; 
		vec[i] = -v[i] ;  
		soma += vec[i] ; 
	}

	for(int i = 1 ; i <= n ; i++){
		maior = max(maior + vec[i], 0) ; // maior resp usando oposto
		resp = max(resp, maior) ; 
		maior2 = max(0, maior2 + v[i]) ; //maior resp usando + 
		resp2 = max(resp2, maior2) ; 
	}

	cout << max(resp2, resp - soma) << "\n" ; 

}
