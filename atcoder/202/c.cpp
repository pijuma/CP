#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, a, b[maxn], c ;
map<int,int> f ; 
int ans ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a ; 
		f[a]++ ; 
	}
	for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> c ; 
		ans += f[b[c]] ; 
	}

	cout << ans << "\n" ; 

}