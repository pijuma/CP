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
    string s ;  
     
    void solve(){
     
    	cin >> n;
    	cin >> s ;
    	bool ok = 1 ;  
    	vector<int> v[maxn] ; 
    	int last = s[0] ; 
    	v[s[0]].push_back(0) ; 
    	for(int i = 1 ; i < s.size() ; i++){
    		if(s[i] == last) continue ; 
    		v[s[i]].push_back(i) ; 
    		// cout << last << "\n" ; 
    		last = s[i] ; 
    	}
    	
    	for(int i = 0 ; i < s.size() ; i++){
    		// cout << v[s[i]].size() << "\n" ; 
    		if(v[s[i]].size() > 1) ok = 0 ; 
    	} 
     
    	cout << (ok ? "YES\n" : "NO\n") ; 
    	return ; 
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	cin >> t ; 
    	// t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
