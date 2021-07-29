#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, p[maxn], a, b, sum, mx, v[maxn] ; 
multiset<int> s ; 
 
int32_t main(){
 
	cin >> n >> a >> b ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i], p[i] = p[i-1] + v[i] ; 
 
	for(int i = a ; i <= b ; i++) s.insert(p[i]) ; //tds os possiveis intervalos 
 
	mx = *s.rbegin() ; 
 
	for(int i = 1 ; i + a <= n ; i++){
		s.erase(p[i+a-1]) ; 
		if(i + b <= n) s.insert(p[i+b]) ; 
		mx = max(mx, *s.rbegin() - p[i]) ; 
	}
 
	cout << mx << "\n" ; 
 
}
