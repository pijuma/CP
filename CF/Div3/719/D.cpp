    #include<bits/stdc++.h>
     
    #define ll long long 
    #define pb push_back
    #define mk make_pair
    #define ff first 
    #define ss second 
    #define pii pair<int,int> 
    #define pil pair<ll, ll>
    #define myheap priority_queue<pii, vector<pii>, greater<pii>>
     
    using namespace std ; 
     
    const int mod = 1e9 + 7 ;
    const int maxn = 1e2 + 5 ; 
    const int inf = 1e9 ; 
    const ll INF = 1e18 ; 
     
    int n, t, x, m ;
    int v[maxn] ; 
    string s ;  
     
    void solve(){
     
    	cin >> n ; 
     
    	// a[j] - a[i] = j - i 
    	// a[j] - j = a[i] - i -> p cada cara guarda o valor menos o indice 
    	// e usa map p saber qts caras tem com o valor (on faz c q j > i)
     
    	map<int,ll> f ; 
    	ll ans = 0 ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		cin >> x ; 
    		ans += f[x-i] ; 
    		f[x-i]++ ; 
    	}
     
    	cout << ans << "\n" ; 
     
    	return ; 
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	cin >> t ; 
    	// t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
