#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 110 ; 

int n, b[maxn], p[maxn] ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 

	for(int i = 1 ; i <= n ; i++) p[i] = p[i-1] + b[i] ; 

	int mx = 100 ; 

    for(int i = 1 ; i <= n ; i++) mx = max(mx, p[i] + 100) ; 

    cout << mx << "\n" ; 

}
