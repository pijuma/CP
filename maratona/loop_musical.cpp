#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e4 + 5 ; 

int n, v[maxn], resp ;

int32_t main(){

	while(true){
		cin >> n ; 
		if(!n) return 0 ; 
		for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
		v[n+1] = v[1] ; v[0] = v[n] ;
	    int resp = 0 ;
	    for(int i = 1 ; i <= n ; i++){
	    	if(v[i] > v[i-1] && v[i] > v[i+1]) resp++ ; 
	    	if(v[i] < v[i-1] && v[i] < v[i+1]) resp++ ; 
	    }
	    cout << resp << "\n" ; 
	}

}
