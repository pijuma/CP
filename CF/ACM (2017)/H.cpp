    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    const int maxn = 2e3 + 5 ; 
    const int inf = 1e18 ; 
     
    int n, k, t, price[maxn][6] ; 
    int dp[maxn][maxn] ; 
     
    // k produtos 
    // n lojas 
    // cada loja 3 prods 
    // 2 produtos de cada no maximo 
     
    int solve(int i, int need){
     
    	if(dp[i][need] != -1) return dp[i][need] ; 
    	if(!need) return 0 ; 
    	if(i > n) return inf ; 
     
    	int ans = inf ; 
     
    	for(int j = 0 ; j <= 2 ; j++){
    		int sum = 0 ; 
    		for(int k = 1 ; k <= j ; k++) sum += price[i][k] ; 
    		ans = min(ans, solve(i+1, need - j) + sum) ; 
    	}
     
    	return dp[i][need] = ans ; 
     
    }
     
    int32_t main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> t ; 
     
    	while(t--){
     
    		cin >> n >> k ; 
     
    		for(int i = 1 ; i <= n ; i++){
     
    			vector<int> vec ; 
     
    			for(int j = 1 ; j <= 3 ; j++){
    				int x ; 
    				cin >> x ; 
    				vec.push_back(x) ; 
    			}
     
    			sort(vec.begin(), vec.end()) ; 
     
    			for(int j = 1 ; j <= 3 ; j++) price[i][j] = vec[j-1] ; 
     
    		}
     
    		memset(dp, -1, sizeof dp) ; 
     
    		cout << solve(1, k) << "\n" ; 
     
    	}
     
    }
