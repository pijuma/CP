#include<bits/stdc++.h>
using namespace std ;
 
const int mod = 1e9 + 7 ;
const int maxn = 1e5 + 10 ;
const int maxv = 105 ;
 
//dp[pos][val] = qts seqs diferentes at� pos com pos valendo val
 
int n, m, v[maxn], dp[maxn][maxv] ;
 
int modu(int x, int y){
 
    int sum = x + y ;
 
    if(sum >= mod) sum -= mod ;
 
    return sum ;
 
}
 
int main(){
 
    cin >> n >> m ;
 
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
 
    memset(dp, 0, sizeof(dp)) ;
 
    if(v[1] != 0) dp[1][v[1]] = 1 ;
 
    else{
 
        for(int i = 1 ; i <= m ; i++) dp[1][i] = 1 ;
 
    }
 
    for(int i = 2 ; i <= n ; i++){
 
        if(v[i] != 0) dp[i][v[i]] = modu(modu(dp[i-1][v[i] - 1], dp[i-1][v[i]]), dp[i-1][v[i]+1]) ;
        else{
 
            for(int j = 1 ; j <= m ; j++) dp[i][j] = modu(modu(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) ;
 
        }
 
    }
 
    int maxc = 0;
 
    if(v[n] != 0) cout << dp[n][v[n]] ;
    else{
 
        for(int i = 1 ; i <= m ; i++) maxc = modu(dp[n][i], maxc) ;
        cout << maxc ;
 
    }
 
}
