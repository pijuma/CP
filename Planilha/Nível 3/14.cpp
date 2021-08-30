    #include<bits/stdc++.h>
     
    #define int long long 
     
    using namespace std ;
     
    int dp[38][38] ; 
    int n, h ; 
     
    int32_t main(){
     
    	cin >> n >> h ; 
     
    	for(int i = 0 ; i <= n ; i++){
    		
    		for(int j = 0 ; j <= n ; j++){
    			
    			if(i == 0) dp[i][j] = 1 ; // caso base  
     
    			if(j == 0) continue ; 
     
    			for(int k = 0 ; k < i ; k++) dp[i][j] += (dp[k][j-1]*dp[i-k-1][j-1]) ; 
     
    		}
     
    	}
     
    	cout << dp[n][n] - dp[n][h-1] << "\n" ; 
     
    }
