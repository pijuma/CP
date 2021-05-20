    #include<bits/stdc++.h>
    using namespace std ;
     
    const int maxn = 5e3 + 1 ;
    const int inf = 1e9 + 1 ;
     
    int n, m, u[maxn], v[maxn], p1, p[maxn] ;
    int d[maxn] ;
     
    bool belman(int s){
        
        for(int i = 0 ; i < n ; i++) d[i] = inf ;
        
        d[s] = 0 ;
        
        for(int i = 1 ; i < n ; i++){
            
            for(int j = 0 ; j < m ; j++){
                
                if(d[u[j]] + p[j] < d[v[j]]) d[v[j]] = d[u[j]] + p[j] ;
                
            }
            
        }
        
        for(int i = 0 ; i < m ; i++){
            
            if(d[u[i]] + p[i] < d[v[i]]){
                
                return true ;
                
            }
            
        }
        
        return false ;
        
        
    }
    int main(){
        
        while(scanf("%d%d",&n,&m) != EOF){
            
            for(int i = 0 ; i < m ; i++){
                
                cin >> u[i] >> v[i] >> p1 ; 
                p[i] = p1*-1 ;
                
            }
            
            if(belman(u[0])) printf("n\n") ;
            else printf("y\n") ;
            
        }
        
    } 
