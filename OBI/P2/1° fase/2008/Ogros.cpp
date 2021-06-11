#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 1 ; 
int n, m, a[maxn], p[maxn], o[maxn] ;

int pont(int v){
    
    int ini = 0, fim = n ; 
    
    while(fim - ini > 1){
        
        int mid = (ini + fim)/2 ;
        
        if(a[mid] <= v) ini = mid ; 
        else fim = mid ;
    
    }
    
    return p[fim - 1] ;
}
int main(){
    
    cin >> n >> m ; 
    
    a[0] = 0 ;
    
    for(int i = 0 ; i < n - 1 ; i++) cin >> a[i+1] ;
    for(int i = 0 ; i < n ; i++) cin >> p[i] ;
    for(int i = 0 ; i < m ; i++) cin >> o[i] ; 
    
    for(int i = 0 ; i < m ; i++) cout << pont(o[i]) << " " ;
    
}
