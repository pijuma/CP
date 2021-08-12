// sol lenta  backtracking 
#include<bits/stdc++.h>
using namespace std ; 

int n, m, xi, yi, xf, yf ;
int g[20][20], resp, custo ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && !g[i][j] ; }

int dx[4] = {0, 0, 1, -1} ;
int dy[4] = {1, -1, 0, 0} ;

void solve(int i, int j){
    
    g[i][j] = 1 ; 
    custo++ ; 
    
    if(i == xf && j == yf){
        resp = max(resp, custo) ;
    }
    
    else{
        for(int k = 0 ; k < 4 ; k++){
            int fi = i + dx[k], fj = j + dy[k] ;
            if(!valid(fi, fj)) continue ;
            solve(fi, fj) ;
        }
    }
    
    g[i][j] = 0 ;
    custo-- ; 
}

int main(){
    
    cin >> n >> m ; 
    cin >> xi >> yi >> xf >> yf ;
    
    for(int i = 2 ; i <= n ; i += 2){
        
        for(int j = 2 ; j <= m ; j += 2){
            g[i][j] = 1 ; 
        }
        
    }
    
    solve(xi, yi) ;
    
    cout << resp << "\n" ;
    
}

// sol c poda  backtracking 
// visita de 2 em 2 
#include<bits/stdc++.h>
using namespace std ; 

int n, m, xi, yi, xf, yf ;
int g[20][20], resp, custo ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && !g[i][j] ; }

int dx[4] = {0, 0, 2, -2} ;
int dy[4] = {2, -2, 0, 0} ;

void solve(int i, int j){
    
    g[i][j] = 1 ; 
    custo++ ; 
    
    if(i == xf && j == yf){
        resp = max(resp, custo) ;
    }
    
    else{
        for(int k = 0 ; k < 4 ; k++){
            int fi = i + dx[k], fj = j + dy[k] ;
            if(!valid(fi, fj)) continue ;
            custo++ ;
            solve(fi, fj) ;
            custo-- ;
        }
    }
    
    g[i][j] = 0 ;
    custo-- ; 
}

int main(){
    
    cin >> n >> m ; 
    cin >> xi >> yi >> xf >> yf ;
    
    for(int i = 2 ; i <= n ; i += 2){
        
        for(int j = 2 ; j <= m ; j += 2){
            g[i][j] = 1 ; 
        }
        
    }
    
    solve(xi, yi) ;
    
    cout << resp << "\n" ;
    
}
