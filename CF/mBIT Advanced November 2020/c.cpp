#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

// a similaridade é medida por qts pares
// i, j (i < j) tal q ai != aj & bi != bj 

const int maxn = 1e5 + 5 ; 

int n, a[maxn], b[maxn] ; 
map<int,int> aa, bb ; 
map<pair<int,int>, int> f ; 

// ai = aj bi == bj 
// eu qro contar qts vzs o par ai bi aparece 

int32_t main(){

	cin >> n ;  

	for(int i = 1 ; i <= n ; i++) cin >> a[i] ; 
	for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 

	int ans = (n*(n-1))/2 ;

	for(int i = 1 ; i <= n ; i++){
		ans -= aa[a[i]] ; 
		aa[a[i]]++ ; 
	}
	
	for(int i = 1 ; i <= n ; i++){
		ans -= bb[b[i]] ;
		bb[b[i]]++ ; 
	} 

	aa.clear(), bb.clear() ; 

	for(int i = 1 ; i <= n ; i++){
		ans += f[{a[i], b[i]}] ; 
		f[{a[i], b[i]}]++ ;
	}

	cout << ans << "\n" ; 

}
