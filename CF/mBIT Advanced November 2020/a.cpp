#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, k, v[maxn] ;

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	sort(v + 1, v + 1 + n) ; 
    
    int ans = 0, mx = 0 ; 

    for(int i = 1 ; i <= n ; i++){
    	ans += v[i] ; 
    	if(abs(v[i] - v[i+1]) > k){
    		mx = max(mx, ans) ;
    		ans = 0 ;  
    	} 
    }

    cout << mx << "\n" ; 

}
