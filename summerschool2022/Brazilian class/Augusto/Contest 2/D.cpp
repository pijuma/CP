#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

int t, n, x, y ; 

int32_t main(){

	cin >> t ; 

	while(t--){
		cin >> n >> x >> y ;
		for(int i = 1 ; i < n ; i++){
			if(i%x == 0 && i%y != 0) cout << i << " " ; 
		} 
		cout << "\n" ; 
	}


}
