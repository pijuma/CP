    #include<bits/stdc++.h>
    using namespace std ;
     
    const int maxn = 1e5 + 10 ;
    const int LOG = 20 ;
     
    int m, n, v[maxn], f, t, _log[maxn], l[maxn], r[maxn] ;
    int dp[maxn][LOG] ;
     
    void ini(){
        
        for(int i = 1 ; i <= n ; i++) dp[i][0] = v[i] ;
        
        _log[1] = 0 ;
        
        for(int i = 2 ; i <= n ; i++) _log[i] = _log[i>>1] + 1 ;
        
        for(int i = 1 ; i <= _log[n] ; i++){
            
            for(int j = 1 ; j + (1<<i) - 1 <= n ; j++){
                
                dp[j][i] = min(dp[j][i-1], dp[j + (1<<(i - 1))][i-1]) ;
                
            }
            
        }
        
    }
     
    int query(int e, int d){
        
        int k = _log[d - e + 1] ;
        
        return min(dp[e][k], dp[d - (1<<k) + 1][k]) ;
        
    }
     
    int main(){
        
        scanf("%d",&t) ;
        
        while(t--){
            
            scanf("%d%d",&n,&m) ; 
            
            for(int i = 1 ; i <= n ; i++) scanf("%d",&v[i]) ;
            
            ini() ;
            
            for(int i = 1 ; i <= m ; i++){
                
                scanf("%d%d",&l[i],&r[i]) ;
                
            }
            
            printf("Scenario #%d:\n", ++f) ;
            
            for(int i = 1 ; i <= m ; i++) printf("%d\n", query(l[i], r[i])) ;
        }
        
    }  
