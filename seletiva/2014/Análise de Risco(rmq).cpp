#include<bits/stdc++.h>
#define ll long long 
using namespace std ;

const int maxn = 1e5 + 5 ; 
const int maxl = 20 ; 

int n, l, r, v[maxn], tab[maxl][maxn], _log[maxn] ;
ll res ;

void make(){ //montar base p rmq
    
    for(int i = 1 ; i <= n ; i++) tab[0][i] = v[i] ;
    
    _log[1] = 0 ;
    
    for(int i = 2 ; i <= maxn ; i++) _log[i] = _log[i/2] + 1 ; 
    
    for(int i = 1 ; i < maxl ; i++){
    
        for(int j = 1 ; j + (1<<i) - 1 <= n ; j++){ // indo de j até j + 2^i pegamos o mdc indo de j subindo (1<<(i-1)) com 
            // j subindo ((1<<(i-1))) subindo i-1  
            tab[i][j] = __gcd(tab[i-1][j], tab[i-1][j + (1<<(i-1))]) ;
        }
    
    }
    
}

int query(int l, int r){
    
    int d = _log[r - l + 1] ;
    return __gcd(tab[d][l], tab[d][r - (1<<d) + 1]) ;
    
}

int get_last(int i, int j, int x){
    
    int ini = j, fim = n, mid, best = i ; 
    
    while(ini <= fim){
        mid = (ini + fim) >> 1 ;
        if(query(i, mid) == x) ini = mid + 1, best = mid ; 
        else fim = mid - 1 ; 
    }
    
    return best ;
    // até onde eu consigo manter o msm mdc q tenho de i a j 
    
}

int main(){
    
    cin >> n >> l >> r ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
    
    make() ;
    
    int pr = 1 ; 
    
    for(int i = 1 ; i <= n ; i++){
      
        int _mdc = v[i] ;
        int id = i ;
        
        while(_mdc > l){ // até onde o _mdc tem o msm valor? 
             
            int last = get_last(i, id, _mdc) ;
            
            if(_mdc <= r){ // pss add
               ll ad = r - _mdc + 1, t = last - id + 1 ;
               res += (ad*t) ;
            }
            
            if(last == n) break ; 
            id = last + 1 ; 
            _mdc = query(i, id) ; // mdc de i a id 
            
        }
        
        while(pr < i || (pr <= n && query(i, pr) > l)) pr++ ; // qual o 1o cara q torna meu mdc <= l ? qd começamos d i
        
        if(pr <= n) res += (r - l + 1)*(n - pr + 1) ;
        
    }
    
    cout << res << "\n" ;
    
}
