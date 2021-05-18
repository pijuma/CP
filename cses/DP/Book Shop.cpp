#include<bits/stdc++.h>
using namespace std ;
 
const int inf = 1e9 + 10 ;
const int maxn = 1e3 + 10 ;
const int maxx = 1e5 + 10 ;
 
int n, x, p[maxn], v[maxn], dp[maxn][maxx], ans ;
int main(){
 
    cin >> n >> x ;
 
    // n - livros, x - pre�o
    // dp[i] valor max utilizando com peso i
    // dp[i][j] max val i obj e com peso j
 
    dp[0][0] = 0 ;
 
    for(int i = 1 ; i <= n ; i++) cin >> p[i] ;
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
 
    for(int i = 1 ; i <= x ; i++) dp[0][i] = -inf ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= x ; j++) dp[i][j] = dp[i - 1][j] ;
 
        for(int j = x ; j - p[i] >= 0 ; j--){
 
            dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i]] + v[i]) ;
 
        }
 
    }
 
    for(int i = 1 ; i <= x ; i++) ans = max(ans, dp[n][i]) ;
 
    cout << ans ;
 
}
