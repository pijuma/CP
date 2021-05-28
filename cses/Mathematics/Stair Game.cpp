// no par smp joga e acaba q vc perde 
// checa o xor das posições impares
 
#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int t, n, v[maxn] ; 
 
int main(){
 
	cin >> t ; 
 
	while(t--){
		cin >> n ; 
		for(int i = 1 ; i <= n ;  i++) cin >> v[i] ;
		int xr = 0 ;   
		for(int i = 2 ; i <= n ; i+=2) xr ^= v[i] ; 
		cout << (xr == 0 ? "second\n" : "first\n") ; 
	}
 
}
