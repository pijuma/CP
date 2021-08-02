#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

//deitado * em pé 

const int maxn = 1e5 + 5 ; 

int n, p, q, r, s, x, val, y, pi, pj, b[maxn], a[maxn] ; 

int32_t main(){

	cin >> n ; 

	cin >> p >> q >> r >> s >> x >> y ; 

	cin >> pi >> pj ; 

	for(int i = 1 ; i <= n ; i++) a[i] = ((p*pi + q*i)%x) ;
	for(int i = 1 ; i <= n ; i++) b[i] = ((r*i + s*pj)%y) ;

	for(int i = 1 ; i <= n ; i++) val += (b[i]*a[i]) ; 

	cout << val << "\n" ; 

}
