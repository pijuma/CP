#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 1e6 + 10 ;
const int inf = 1e9 + 10 ;
 
int dp[maxn], n ;
 
int main(){
 
    cin >> n ;
 
    dp[0] = 0 ;
 
    for(int i = 1 ; i < maxn ; i++) dp[i] = inf ;
 
    for(int i = 1 ; i <= n ; i++){
 
        int p = i ;
 
        while(p >= 1){
 
            if(i >= p){
 
              dp[i] = min(dp[i], dp[i - p%10] + 1) ;
              p /= 10 ;
 
            }
 
        }
 
    }
 
    cout << dp[n];
 
}
