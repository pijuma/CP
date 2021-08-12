#include<bits/stdc++.h>
using namespace std ;

// 1/4 + 1/4 -> 1/2 

const int maxn = 1e4 + 5 ; 

int n, m, a[maxn], b[maxn], c[maxn] ;

int main(){
    
    cin >> n >> m ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
    for(int i = 1 ; i <= m ; i++) cin >> b[i] ;
    
    for(int i = 1 ; i <= max(n, m) ; i++) c[i] = a[i] + b[i] ;
    
    for(int i = max(n, m) ; i > 0 ; i--){
        if(c[i] <= 1) continue ; 
        c[i] -= 2 ; 
        c[i-1]++ ; ;
    }
    
    int l = 1 ; 
    
    for(int i = 1 ; i <= max(n, m) ; i++)
        if(c[i] == 1) l = i ; 
    
    for(int i = 1 ; i <= l ; i++) cout << c[i] << " " ; 
    cout << "\n" ;
    
}
