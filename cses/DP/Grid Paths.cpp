#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 1e3 + 10 ;
const int M = 1e9 + 7 ;
 
char grid[maxn][maxn] ;
int n, dp[maxn][maxn] ;
 
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= n ; j++){
 
            cin >> grid[i][j] ;
 
        }
 
    }
 
    if(grid[1][1] != '*') dp[1][1] = 1;
    else dp[1][1] = 0 ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= n ; j++){
 
            if(i == 1 && j == 1) continue ;
 
            else if(grid[i][j] == '*') dp[i][j] = 0 ;
 
            else{
 
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
 
            }
 
        }
 
    }
 
    cout << dp[n][n] ;
}
