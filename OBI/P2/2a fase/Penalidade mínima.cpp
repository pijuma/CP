#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e3 + 5  ;
const int inf = 1e18 ; 

// k - 1 -> 5 | k - 0 -> 2 
// faço o caminho q pega menor qtd de 2 e de 5 
// e vejo qual eh mlr 

int n, neww[maxn][3], old[maxn][3], a ;

int cont(int a, int b){
    
    int c = 0 ;
    
    while(a%b == 0){
        a /= b ; 
        c++ ;
    }
    
    return c ; 
    
}

int32_t main(){
    
    cin >> n ; 
    
    for (int i = 0 ; i < 2 ; i++){
        old[1][i] = 0 ;
        for (int j = 2 ; j <= n ; j++) old[j][i] = inf ;
        neww[0][i] = inf ;
    }
    
    for(int i = 1 ; i <= n ; i++){
        
        for(int j = 1 ; j <= n ; j++){
            
            cin >> a ; 
            
            if(!a) neww[j][1] = neww[j][0] = inf ;
            
            else for(int k = 0 ; k < 2 ; k++) neww[j][k] = cont(a, (k ? 5 : 2)) + min(neww[j-1][k], old[j][k]) ; //mlr vir de cima ou da esq 
        
        }
        
        for(int k = 0 ; k < 2 ; k++){
            
            for(int j = 1 ; j <= n ; j++){
                old[j][k] = neww[j][k] ; 
            }
    
        }
        
    }
    
    cout << min(neww[n][0], neww[n][1]) << "\n" ;
    
}
