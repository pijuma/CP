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
    const int maxn = 2e3 + 5 ; 
    const int inf = 1e9 ; 
    const ll INF = 1e16 ; 
     
    int n, k, ans ; 
     
    // pega 1x o portal 
    // pode usar 1x ou n usar 
     
    void solve(){
    	
    	int t ; 
     
    	cin >> n >> t ;
    	cin >> k ; 
     
    	int ini = 1, fim = n, mid, best = -1 ; 
     
    	while(ini <= fim){
     
    		mid = (ini + fim)/2 ; 
     
    		cout << "? " << 1 << " " << mid << endl  ; 
    		cin >> ans ; 
    		int valor = ans ; 
     
    		if(mid - valor >= k) best = mid, fim = mid - 1 ; 
    		else ini = mid + 1 ;  
     
    	} 
     
    	cout << "! " << best << endl ;  
     
    	return ; 
     
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	int t ; 
    	t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
