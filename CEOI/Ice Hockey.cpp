    #include<bits/stdc++.h>
    using namespace std ; 
    #define int long long 
     
    const int maxn = 40 ; 
     
    int x, n, v[maxn], ans ; 
    vector<int> m1, m2 ; 
     
    int32_t main(){
     
    	cin >> n >> x ; 
     
    	for(int i = 0 ; i < n ; i++) cin >> v[i] ; 
     
    	int esq = (n+1)>>1 ; 
        int dir = (n>>1) ; 
     
    	for(int mask = 0 ; mask < (1<<dir) ; mask++){
    		int s = 0 ; 
    		for(int i = 0 ; i < dir ; i++){
    			if(mask&(1<<i)) s += v[i] ; 
    		}
    		m1.push_back(s) ; 
    	}
     
    	for(int mask = 0 ; mask < (1<<esq) ; mask++){
    		int s = 0 ;
    		for(int i = 0 ; i < esq ; i++){
    			if(mask&(1<<i)) s += v[i+dir] ; 
    		} 
    		m2.push_back(s) ; 
    	}
     
    	sort(m2.begin(), m2.end()) ; 
     
    	for(int i = 0 ; i < m1.size() ; i++){
    		int u = upper_bound(m2.begin(), m2.end(), x - m1[i]) - m2.begin() ; 
    		ans += u ; 
    	}
     
    	cout << ans << "\n" ; 
     
    } 
