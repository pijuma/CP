#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e5 + 1 ; 

int n, r[maxn], resp, inf ; 

int main(){
    
    cin >> n ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> r[i] ;
    
    int ini = 1, mid, fim = maxn; 
    
    while(ini <= fim){
        
        int inf = 0 ; 
        
        mid = (ini + fim)/2 ;
        
        for(int i = 1 ; i <= n ; i++){
            
            if(r[i] >= mid) inf++ ; 
            
        }
        
        if(inf >= mid){
            
            resp = mid, ini = mid + 1 ; 
            
        }
        
        else fim = mid - 1 ; 
        
    }
    
    cout << resp ; 
}
