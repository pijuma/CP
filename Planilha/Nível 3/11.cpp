    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    const int maxn = 1e6 + 5 ; 
     
    int n, k, a, t[maxn], in[maxn] ; 
     
    int32_t main(){
     
    	cin >> n >> k ; 
     
    	cin >> a ; 
     
    	k-- ; 
     
    	int timer = 1 ; 
     
    	for(int i = 1, ta ; i < n ; i++){
    		cin >> ta ; 
    		t[i] = ta - a - 1 ; 
    		timer += t[i] + 1 ; 
    		a = ta ; 
    	}
        
        sort(t + 1, t + 1 + n) ; reverse(t + 1, t + 1 + n) ; 
     
    	for(int i = 1 ; i <= k ; i++) timer -= t[i] ; 
     
    	cout << timer << "\n" ; 
     
    }
