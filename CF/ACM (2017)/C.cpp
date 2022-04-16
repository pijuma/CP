    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    int t ; 
     
    int32_t main(){
     
    	cin >> t ; 
     
    	while(t--){
    		int n, p, k ; 
    		cin >> k >> p >> n ; 
    		cout << (k >= p ? (k-p)*n : 0) << "\n" ; 
    	}
     
    }

