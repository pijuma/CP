#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 5e3 + 5 ; 

int t, n, sum[maxn][maxn], ct, mn, grid[maxn][maxn] ; 
char g[maxn][maxn] ; 

int32_t main(){

	cin >> t ; 

	while(t--){

		cin >> n ; 

		mn = 2*n*2*n ; 

		for(int i = 1 ; i <= 2*n ; i++){
			for(int j = 1 ; j <= 2*n ; j++){
				cin >> g[i][j] ; 
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (g[i][j] == 'I') ; 	
			}
		}

		for(int i = n ; i <= n ; i++){
			for(int j = n ; j <= n ; j++){
				int a = 0, b = 0, c = 0, d = 0 ; 
				a = sum[i][j] ; 
				b = sum[i][2*n] - sum[i][j] ;
				c = sum[2*n][j] - sum[i][j] ;  
				d = (sum[2*n][2*n] - sum[i][2*n] - sum[2*n][j] + sum[i][j]) ; 
				int sm = abs(a - d) + abs(b - c) ;
				mn = min(mn, sm) ;   
				// cout << sm << " " ; 
			}
			// cout << "\n" ; 
		}

		cout << "Case #" << ++ct<< ": " << mn << "\n" ; 

	}

}
