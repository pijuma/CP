    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 5e4 + 1 ; 
    const long long f = 1000000000 + 1 ; 
     
    // tds pegam msm numero de doces 
    // tds os doces pegos tem q ser de apenas uma caixa p cada aluno 
    // mas uma caixa pode ir p mais de um aluno 
     
    int t, n ; 
    long long k, b[maxn] ; 
    long long best ; 
     
    bool valid(int v){
        
        long long qtd = k ;
        
        for(int i = 1 ; i <= n ; i++){
            
            qtd -= (b[i]/v) ;
            if(qtd <= 0) return true ; 
            
        }
        
        return false ; 
        
    }
     
    int main(){
        
        cin >> t ; 
        
        while(t--){
            
            cin >> n >> k ; 
            
            for(int i = 1 ; i <= n ; i++) cin >> b[i] ; 
            
            long long ini = 1, fim = f, mid ; 
            best = 0 ; 
            
            while(ini <= fim){
                
                mid = (ini+fim)/2 ; 
                
                if(valid(mid)){
                    
                    ini = mid + 1 ; 
                    best = mid ; 
                    
                }
                
                else{
                    
                    fim = mid - 1 ; 
                    
                }
                
            }
            
            cout << best << endl ; 
        
        }
        
    } 
