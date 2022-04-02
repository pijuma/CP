#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e3 + 5 ; 
const int inf = 1e18 ; 

int n, t, dist[maxn], mn, ct ; 
vector<pair<int,int>> grafo[maxn] ; 

void dfs(int v, int p){

	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		dist[a.first] = dist[v] + a.second ; 
		dfs(a.first, v) ; 
	}

}

int gett(int v, int p){

	int mx = 0 ; 

	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		mx = max(mx, gett(a.first, v)) ; 
 	}

 	return max(mx, dist[v]) ; 

}

int32_t main(){

	cin >> t ; 

	while(t--){

		cin >> n ; 

		mn = 0 ; 

		for(int i = 1 ; i < n ; i++){
			int a, b, c ; 
			cin >> a >> b >> c ; 
			mn += (2*c) ; 
			grafo[a].push_back({b, c}) ; grafo[b].push_back({a, c}) ; 
		}

		int val = mn ; 

		for(int i = 1 ; i <= n ; i++){
			dist[i] = 0 ; 
			dfs(i, i) ;
			int mx = gett(i, i) ; 
			// cout << mx << "\n" ; 
			mn = min(mn, val - mx) ; 
		}

		cout << "Case #" << ++ct << ": " << mn << "\n" ; 

		for(int i = 1 ; i <= n ; i++) grafo[i].clear() ; 

	}

}
