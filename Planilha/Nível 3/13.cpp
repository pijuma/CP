#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// boa se n eh sortado nem em a nem em b 
// n! - c1 - c2 + c12 

const int maxn = 3e5 + 15 ;
const int mod = 998244353 ; 

int n, fac[maxn] ;
pair<int,int> v[maxn] ;

bool cmp(pair<int,int> a, pair<int,int> b){ return a.second < b.second ; }

int32_t main(){

	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n ; 

	fac[0] = 1LL ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> v[i].first >> v[i].second ; 
		fac[i] = (fac[i-1]*i)%mod ; 
	}

	long long ans = fac[n] ; 

	int c1 = 1, q = 1 ; 

	sort(v + 1, v + 1 + n) ; 

	for(int i = 2 ; i <= n ; i++){
		if(v[i].first == v[i-1].first) q++ ; 
		else{
			c1 = (c1*fac[q])%mod ; 
			q = 1 ; 
		}
	}

	c1 = (c1*fac[q])%mod ; 
	q = 1 ; 
	ans = (ans - c1 + mod)%mod ; 

	sort(v + 1, v + 1 + n, cmp) ; 

	int c2 = 1 ; 

	for(int i = 2 ; i <= n ; i++){
		if(v[i].second == v[i-1].second) q++ ; 
		else{
			c2 = (c2*fac[q])%mod ; 
			q = 1 ; 
		}
	}

	c2 = (c2*fac[q])%mod ; 
	q = 1 ; 
	ans = (ans - c2 + mod)%mod ; 

	int c12 = 1 ;
	bool inter = 1 ; 

	sort(v + 1, v + 1 + n) ; 

	for(int i = 1 ; i < n ; i++){
		if(v[i].first > v[i+1].first || v[i].second > v[i+1].second) inter = 0 ; 
	} 

	for(int i = 2 ; i <= n ; i++){
		if(v[i] == v[i-1]) q++ ;
		else{
			c12 = (c12*fac[q])%mod ; 
			q = 1 ; 
		} 
	}

	c12 = (c12*fac[q])%mod ; 

	if(inter) ans = (ans + c12)%mod ; 

	cout << ans << "\n" ; 
	
}
