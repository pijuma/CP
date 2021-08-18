#include<bits/stdc++.h>
#define int long long 
using namespace std ;

// n crianças k doces 
// cada criança pode receber de 1 a ai doces 
// qual a qtd de formas de distribuir % mod?
// dp[n][k]

const int maxn = 1e5 + 5 ; 
const int mod = 1e9 + 7  ;

int n, k, v[110], dp[110][maxn], ps[maxn];

int32_t main(){
    
    cin >> n >> k ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
    
    dp[0][0] = 1 ; // só tem 1 forma de distribuir 0 doces p 0 pessoas 
    
    for(int i = 1 ; i <= n ; i++){
        
        ps[0] = dp[i-1][0] ;
        for(int j = 1 ; j <= k ; j++) ps[j] = (ps[j-1] + dp[i-1][j])%mod ; // prefix sum 
        
        for(int j = 0 ; j <= k ; j++){
            
            int val = ps[j] ; // qtd de formas de distribuir até j doces pras i-1 pessoas é a soma da qtd de formas
            // de distribuir 1, 2, 3... j q está guardado no ps[j] 
            
            int f = j - v[i] - 1 ; // pss passar de j até j - v[i] doces p prox, f é o 1o q eu n alcanço 
            
            if(f >= 0) val = (val + mod - ps[f])%mod ;
            
            dp[i][j] = val ;
            
        }
        
    }
    
    cout << dp[n][k] << "\n" ;
    
}
