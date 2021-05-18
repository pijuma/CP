#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 110 ;
const int M = 1e9 + 7 ;
const int MAX = 1e6 ;
 
long long dp[MAX + 2] ;
long long n, x, v[maxn] ;
 
int main(){
 
    cin >> n >> x ;
 
    dp[0] = 1 ;
 
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
 
    for(int i = 1 ; i <= x ; i++){
 
        for(int j = 1 ; j <= n ; j++){
 
            if(i >= v[j]){
 
                dp[i] = (dp[i] + dp[i - v[j]]) % M ;
 
            }
 
        }
 
    }
 
    cout << dp[x] ;
}
