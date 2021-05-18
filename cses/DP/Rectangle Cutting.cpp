#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 510 ;
const int inf = 1e9 ;
// dp[ver][hor] = numero de movimentos p cortar
// dp[1][1] = 0, dp[0][0] = 0
// min(vertical, horizontal)
// vertical = dp[ver-i][hor] + 1
// horizontal = dp[ver][hor-i] + 1
// se ver == hor dp[i][j] = dp[i-1][j-1]
int v, h, dp[maxn][maxn] ;
 
int main(){
 
    cin >> v >> h ;
 
    for(int i = 1 ; i <= v ; i++){
 
        for(int j = 1 ; j <= h ; j++){
 
            if(i != j) dp[i][j] = inf ;
 
            for(int k = 1 ; k <= i ; k++){
 
                dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1) ;
 
            }
            for(int k = 1 ; k <= j ; k++){
 
                dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1 ) ;
 
            }
 
        }
 
    }
 
    cout << dp[v][h] ;
 
}
