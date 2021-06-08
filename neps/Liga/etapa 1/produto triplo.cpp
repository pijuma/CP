#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, v[maxn] ; 

int32_t main(){
	
	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	sort(v + 1, v + 1 + n) ; 
    
    if(n == 3) cout << v[1]*v[2]*v[3] << "\n" ; 
    else{
    	int pos = v[n]*v[n-1]*v[n-2] ; 
    	int neg = v[1]*v[2]*v[n] ;
    	cout << max(pos, neg) << "\n" ; 
    }
}
