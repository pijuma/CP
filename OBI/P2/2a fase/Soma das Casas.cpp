#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 1 ; 

long long n, k, v[maxn], a ;
map<long long,int> mapa ; 

int main(){
    
    cin >> n ; 
    
    for(int i = 1 ; i <= n ; i++){
        
        cin >> v[i] ; 
        mapa[v[i]] = i ; 
        
    }
    
    cin >> k ;
    
    for(int i = 1 ; i <= n ; i++){
        
        if(mapa.find(k-v[i]) != mapa.end()){
            
            cout << v[i] << " " << k - v[i] ; 
            return 0 ;
            
        } 
        
    }
    
}
