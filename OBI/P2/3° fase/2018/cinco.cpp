#include <iostream>

using namespace std;

const int maxn = 1e3 + 10 ; 

int d5, n, n0, v[maxn] ; 

int main() {
    
    cin >> n ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
    
    for(int i = 1 ; i <= n ;  i++){
        
        if(v[i] == 5 || v[i] == 0) d5++ ;
        
    }
    
    if(d5 == 0){
        
        cout << -1 ; 
        return 0 ;
        
    }
    
    if(v[n] >= 5){
        
        for(int i = 1 ; i <= n ; i++){
            
            if(v[i] == 5 || v[i] == 0){
                
                swap(v[i], v[n]) ;
                
                break ;
                
            }
            
        }
        
        for(int i = 1 ; i <= n ; i++) cout << v[i] << " " ;
        
    }
    
    else{
        
        for(int i = 1 ; i <= n ; i++){
            
            if(v[i] == 0) n0++ ;
            
        }
        
        if(n0 == 0){
            
            for(int i = n - 1 ; i > 0 ; i--){
                
                if(v[i] == 5){
                    
                    swap(v[i], v[n]) ;
                    break ;
                    
                }
                
            }
            
            for(int i = 1 ; i <= n ; i++) cout << v[i] << " " ;
            
        }
        
        else{
            
            for(int i = 1 ; i <= n ; i++){
                
                if(v[i] == 0){
                    
                    swap(v[i], v[n]) ;
                    
                    break ; 
                    
                }
                
            }
            
            for(int i = 1 ; i <= n ; i++) cout << v[i] << " " ;
            
        }
        
    }
    
}
