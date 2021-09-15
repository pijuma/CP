    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 305 ; 
    const int inf = 1e9 ;
     
    int n, v[maxn][maxn], ps[maxn][maxn], dp[2][maxn][maxn] ;
     
    int main(){
     
    	cin >> n ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			cin >> v[i][j] ; 
    			ps[i][j] = ps[i-1][j] + v[i][j] ; 
    		}
    	}
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = i ; j > 0 ; j--) dp[1][i][j] = ps[n][n] - ps[j-1][n] ; 
    	}
     
    	int get = 0, fill = 1 ; 
     
    	for(int c = n-1 ; c > 0 ; c--){
    		swap(get, fill) ;
    		for(int j = n ; j > 0 ; j--){
    			int at = -inf ; 
    			for(int i = n ; i >= j ; i--){
    				at = max(at, dp[get][i][j] + ps[i][c]) ;
    				dp[fill][i][j] = at - ps[i-1][c] ; 
    				if(j != i) dp[fill][i][j] += v[j][c] ; 
    				if(i != j) dp[fill][i][j] = max(dp[fill][i][j], dp[fill][i][j+1] + v[j][c]) ; // andar j 
    				else if(i < n) dp[fill][i][j] = max(dp[fill][i][j], dp[fill][i+1][j+1] + v[i][c]) ; //andar i 
    			}
    		}
    	}
     
    	swap(get, fill) ;
     
    	cout << dp[get][1][1] << "\n" ; 
     
    }
