#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int mdc(int a, int b){
	if(a < b) swap(a, b) ; 
	return (b == 0 ? a : mdc(b, a%b)) ; 
}

int mmc(int a, int b){  
	if(!b) return a ;
	if(!a) return b ; 
	return (a*b)/(mdc(a, b)) ; 
}

int n, w[maxn], val[maxn], foia[maxn], tot, mn, lcmm ; 
vector<int> grafo[maxn] ;

void solve(int v, int p){

	int sz = grafo[v].size() ; 

	if(v != 1) sz-- ; // tirar o pai 

	if(sz == 0) foia[v] = 1, sz = 1 ; 

	for(auto u : grafo[v]){
		if(u == p) continue ; 
		val[u] = val[v]*sz ;
		solve(u, v) ; 
		if(val[u] >= (int)1e9) cout << tot << "\n", exit(0) ;
		w[v] += w[u] ;  
	}

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> w[i] ; tot += w[i] ; 
	}

	for(int i = 1 ; i < n ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ;
	}

	val[1] = 1 ; 
	solve(1, 1) ; 

	mn = (long long) 2e18 ; 

	for(int i = 1 ; i <= n ; i++){
		if(!foia[i]) continue ; 
		lcmm = mmc(lcmm, val[i]) ; 
		if(lcmm >= (int)1e9) cout << tot << "\n", exit(0) ;
		mn = min(mn, val[i]*w[i]) ;  
		// cout << lcm << " " << mn << "\n" ; 
	}

	cout << max(0LL, tot - (lcmm*(mn/lcmm))) << "\n" ; 

}
