#include<bits/stdc++.h>
#define int long long
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, v[maxn], sum, mx ; 
 
int32_t main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	for(int i = 1 ; i <= n ; i++){
		sum += v[i] ; 
		mx = max(mx, v[i]) ; 
	}
 
	cout << max(sum, 2*mx) << "\n" ; 
 
}
