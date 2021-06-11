#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5 + 2 ; 

int u, v, n ;
vector<int> grafo[maxn] ;
bool ok ; 

int func(int no){
    
    int tot = 1, peso ; 
    
    for(int i = 0 ; i < (int)grafo[no].size() ; i++){
        
        int atual = func(grafo[no][i]) ; 
        
        if(!i) peso = atual ; 
    
        else if(peso!=atual) ok = 0 ; 
        
        tot += atual ; 
        
    }
    
    return tot ; 
}

int main(){
    
    cin >> n ; 
    
    for(int i = 1 ; i <= n ; i++){
        
        cin >> u >> v ; 
        
        grafo[v].push_back(u) ;
        
    }
    
    ok = 1 ; 
    func(0) ; 
    
    cout << (ok == 1 ? "bem" : "mal") ;
    
}
