    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 510 ;
    const long long s = 1e10 ; 
     
    int t, n, c, l[maxn], best ; 
    vector <int> resp ; 
     
    bool busca(long long v){
        
        long long soma = 0 ; 
        long long k = 1 ;
        
        for(int i = n ; i > 0 ; i--){
            
            if(l[i] > v){
                
                k = s ; 
                break ;
                
            }
            
            if(soma + l[i] <= v) soma += l[i] ;
            
            else{
                
                k++ ;
                soma = l[i] ;
                
            }
        
            
        }
        
        if(k <= c) return true ; 
            
        return false ; 
        
    }
     
    void saida(long long v){
        
        long long soma = 0 ; 
        int ct = 0 ; 
        resp.clear() ;
        
        for(int i = n ; i > 0 ; i--){
            
            if(soma + l[i] > v || i == c - ct - 1){
                
                ct++ ; 
                resp.push_back(-1) ;
                soma = 0 ; 
                
            } 
            
            soma += l[i] ; 
            resp.push_back(l[i]) ;
            
        }
        
        reverse(resp.begin(), resp.end()) ; 
        
        for(int i = 0 ; i < (int) resp.size() ; i++){
            
            if(resp[i] == -1) cout << "/ " ; 
            else{
                
                cout << resp[i] << " " ; 
                
            }
            
        }
        
    }
     
    int main(){
        
        cin >> t ; 
        
        while(t--){
            
            cin >> n >> c ;
            
            for(int i = 1 ; i <= n ; i++) cin >> l[i] ; 
            
            long long ini = 1, mid, fim = s ;
            
            while(ini <= fim){
                
                mid = (ini + fim)/2 ;
                
                if(busca(mid)){
                    
                    best = mid ; 
                    fim = mid - 1 ; 
                    
                }
                
                else ini = mid + 1 ; 
                
            }
            
            saida(best) ; 
            cout << endl ; 
            
        }
        
    } 
