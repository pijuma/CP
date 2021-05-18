#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 110 ;
const int MAX = 1e6 + 10 ;
const int M = 1e9 + 7 ;
 
int n, x, v[maxn], dp[MAX] ;
 
int main(){
 
    cin >> n >> x ;
 
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
 
    dp[0] = 1 ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= x ; j++){
 
            if(j >= v[i]){
 
                dp[j] = (dp[j] + dp[j - v[i]]) % M ;
 
            }
 
        }
 
    }
 
    cout << dp[x] ;
}
