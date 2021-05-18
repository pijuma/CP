#include<bits/stdc++.h>
using namespace std ;
 
const int mod = 1e9 + 7 ;
const int maxn = 1e6 + 3 ;
int n, dp[maxn] ;
int main(){
 
    cin >> n ;
    dp[0] = 1 ;
    //dp[i] -> n� formas p gnt conseguir o valor i
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if(i >= j) dp[i] = (dp[i] + dp[i - j])%mod ;
        }
    }
    cout << dp[n] ;
}
