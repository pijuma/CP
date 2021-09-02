
    art

    #include<bits/stdc++.h>
     
    #define ll long long 
     
    using namespace std ; 
     
    const int maxn = 500010 ; 
    const ll inf = 1e18 ; 
     
    ll n, best, mx, sum[maxn] ;  
    pair<ll, ll> a[maxn] ; 
     
    int main(){
     
    	cin >> n ; 
     
    	for(int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second ; 
     
    	sort(a + 1, a + 1 + n) ; 
        
        for(int i = 1 ; i <= n ; i++) sum[i] = sum[i-1] + a[i].second  ; 
     
        best = -inf ;
     
    	for(int i = 1 ; i <= n ; i++){
    		best = max(best, -sum[i-1] + a[i].first) ; 
    		mx = max(mx, sum[i] - a[i].first + best) ; 
    	}  
     
    	cout << mx << "\n" ; 
     
    }
