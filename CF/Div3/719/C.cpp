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
     
    int n, t, x ;
    string s ;  
     
    void solve(){
     
    	cin >> n ; 
    	
    	int m = 1 ; 
     
    	if(n == 2){
    		cout << "-1\n" ; 
    		return ; 
    	}
     
        for(int i = 1 ; i <= n ; i++){
        	for(int j = 1 ; j <= n ; j++){
        		cout << m << " " ; 
        		m += 2 ; 
        		if(m > n*n) m = 2 ; 
        	}
        	cout << "\n" ; 
        }
     
        cout << "\n" ; 
     
    	return ; 
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	cin >> t ; 
    	// t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
