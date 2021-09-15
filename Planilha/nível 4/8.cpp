    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 110 ; 
    const int mod = 1e9 + 7 ; 
     
    int t, dp[maxn][maxn*27] ; 
    // qd muda soma 1 e subtrai 1 ou o contrario 
    int main(){
     
    	cin >> t ; 
     
    	dp[0][0] = 1 ; 
     
    	for(int i = 1 ; i <= 100 ; i++){ // comprimento de si 
    		for(int j = 0 ; j <= 25*maxn ; j++){ //soma 
    			for(int k = 0 ; k <= 25 ; k++){//letra 
    				if(j >= k) dp[i][j] += dp[i-1][j-k] ; 
    				dp[i][j] %= mod ; 
    			}
    		}
    	}
     
    	while(t--){
     
    		string s ; 
     
    		cin >> s ; 
    	
    		int n = s.size() ; 
    		int sum = 0 ; 
    	
    		for(int i = 0 ; i < s.size() ; i++) sum += s[i] - 'a' ; 
     
    		cout << dp[n][sum] - 1 << "\n" ; // qts palavras de msm comprimento tem a msm soma
     
    	}
     
    }
