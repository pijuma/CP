    #include<bits/stdc++.h>
     
    #define int long long 
    #define pb push_back
    #define mk make_pair
    #define ff first 
    #define ss second 
    #define pii pair<int,int> 
    #define pil pair<ll, ll>
    #define myheap priority_queue<pii, vector<pii>, greater<pii>>
     
    using namespace std ; 
     
    const int mod = 1e9 + 7 ;
    const int maxn = 2e3 + 5 ; 
    const int inf = 1e9 ; 
    const int INF = 1e16 ; 
     
    int n, k, d ; 
    string s ; 
    vector<int> sheep ; 
     
    // pega 1x o portal 
    // pode usar 1x ou n usar 
     
    void solve(){
     
        cin >> n ; 
        cin >> s ; 
     
        int sum = 0, d = 0 ; 
        sheep.clear() ; 
     
        for(int i = 0 ; i < s.size() ; i++){
        	if(s[i] == '.') continue ; 
        	sum++, sheep.push_back(i) ; 
        }
        
        if(sum == 0){
        	cout << "0\n" ; 
        	return ; 
        }
     
        if(sum%2 == 0) sum /= 2 ; 
        else sum/= 2, sum++ ; 
     
        sum-- ; 
     
        int med = sheep[sum] - 1 ; 
     
        for(int i = sum - 1 ; i >= 0 ; i--){
        	d += abs(sheep[i] - med) ; 
        	// cout << med << " " ;
        	med-- ; 
        }
        
        med = sheep[sum] + 1 ; 
     
        for(int i = sum + 1 ; i < sheep.size() ; i++){
        	d += abs(sheep[i] - med) ; 
        	// cout << med << " " ; 
        	med++ ; 
        }
     
        cout << d << "\n" ; 
    	return ; 
     
    }
     
    int32_t main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	int t ; 
     
    	cin >> t ; 
    	// t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
