#include<bits/stdc++.h>
#define ll long long 
using namespace std ; 

const int maxn =1e6 + 5 ; 

ll n, k, v[maxn], tot ;

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
	
	cin >> n >> k ; 

	for(int i = 1 ; i <= k ; i++) cin >> v[i] ; 

	for(int i = 1 ; i < k -1; i++){ 
		tot = tot + (v[i]-v[i-1])*(n-v[i+2]+1) ; 
	}

	cout << tot << "\n" ;

}
