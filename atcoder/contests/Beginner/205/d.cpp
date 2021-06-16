    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 1e5 + 5 ;
     
    long long n, a[maxn], q, k ;
     
     
    int main(){
     
    	cin >> n >> q ; 
     
    	for(int i = 0 ; i < n ; i++) cin >> a[i] ;  
     
    	sort(a, a + n) ; 
        
        vector<long long> low ; 
     
        for(int i = 0 ; i < n ; i++) low.push_back(a[i] - i - 1) ; 
     
        sort(low.begin(), low.end()) ; 
        
        while(q--){
        	cin >> k ; 
        	auto idx = lower_bound(low.begin(), low.end(), k) - low.begin() ; 
        	// se k < qtd menores q n
        	if(idx == n) cout << a[n-1] + k - low[n-1] << "\n" ; 
        	else cout << a[idx] - low[idx] + k - 1 << "\n" ;    
        }
     
    }
