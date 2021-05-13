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
     
    int n, t, x, m, f[maxn], q ;
    map<int,int> mp ; 
    vector<int> v ; 
     
    void solve(){
     
    	cin >> q ; 
     
    	string s ; 
     
    	for(int i = 1 ; i <= 9 ; i++){
    		for(int j = 1 ; j <= 9 ; j++){
    			int qtd = j ; 
    			s = "" ; 
    			
    			while(qtd--){
    				s += to_string(i) ; 
    			}
     
    			v.push_back(stoi(s)) ; 
     
    		}
    	}
     
    	// for(int i = 0 ; i < v.size() ; i++) cout << v[i] << "\n" ; 
     
    	sort(v.begin(), v.end()) ; 
    	
    	while(q--){
    		
    		cin >> n ;
    		
    		int qtd = 0 ; 
    		int i = 0 ; 
    		while(true){
    			if(v[i] > n) break ; 
    			qtd++, i++ ; 
    		}
     
    		cout << qtd << "\n" ; 
    	}
     
    	return ; 
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	// cin >> t ; 
    	t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
