#include<bits/stdc++.h>
using namespace std ;
 
const int inf = 1e6 + 10 ;
const int maxn = 1e6 + 10 ;
 
int dp[maxn], n, m, v[maxn] ;
int main(){
 
    cin >> n >> m ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> v[i] ;
 
    }
 
    for(int i = 1 ; i <= m ; i++) dp[i] = inf ;
 
    dp[0] = 0 ;
 
    for(int i = 1 ; i <= m ; i++){
 
        for(int j = 1 ; j <= n ; j++){
 
            if(i >= v[j]){
 
                dp[i] = min(dp[i], dp[i - v[j]] + 1) ;
 
            }
        }
    }
 
    if(dp[m] == inf) cout << -1 ;
    else cout << dp[m] ;
}
