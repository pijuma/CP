#include<bits/stdc++.h>
#define int long long
#define ll long long 
using namespace std ;

const int maxn = 1e4 + 5 ; 

ll n, ans, v[maxn] ;
map<ll, bool> dist ;
map<ll,ll> pai ; 

void solve(){

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
    pai.clear() ;
	for(int i = 1 ; i <= n ; i++){
		v[i] += v[i-1] ; 
		pai[v[i]] = i ; 
	} 

	for(int i = n ; i > 2 ; i--){
		if(v[n]%i) continue ;
		dist.clear() ;
		int last = 0 ;   
		for(int j = 1 ; j <= n ; j++){
			if(v[j] > (v[n]/i)) break ; 
			dist[v[j]] = 1 ; 
			last = j ; 
		}
		int pto = 0 ; 
		for(int j = 1 ; j <= n ; j++){
			if(v[j] <= (v[n]/i)) continue ; 
			if(dist[v[j] - (v[n]/i)] == 1){
				dist[v[j]] = 1 ; 
				last = j ;
			}
		}

		int u = last ; 
		int x = i ; 
		x-- ; 
		
		while(true){
			if(u == 1 || x == 0) break ;
			if(pai.find(v[u] - (v[n]/i)) == pai.end()) break ;   
			x-- ; 
			u = pai[v[u] - (v[n]/i)] ; 
		}

		if(!x){
			cout << n - i << "\n" ; 
			return ; 
		}
	} 

	cout << "-1\n" ; 

}

int32_t main(){
    
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    while(true){
        cin >> n ;
        if(!n) return 0 ;
        solve() ; 
    }
    
}
