#include<bits/stdc++.h>
using namespace std ;

const int maxn = 5e4 + 10 ;

int n, m, grau[maxn], a, b ;
vector<int> grafo[maxn] ;
vector<int> r ; 

int main(){
    
    cin >> n >> m ; 
    
    memset(grau, 0, sizeof(grau)) ;
    
    for(int i = 1 ; i <= m ; i++){
        
        cin >> a >> b ;
        grafo[a].push_back(b) ;
        grau[b]++ ;
        
    }
    
    priority_queue< int, vector<int>, greater<int> > fila ; 
    
    for(int i = 0 ; i < n ; i++){
        
        if(grau[i] == 0) fila.push(i) ;
        
    }
    
    int ini = 0 ; 
    while(!fila.empty()) {
        
        int p = fila.top() ;
        fila.pop() ;
        ini ++ ;
        for(int i = 0 ; i < (int) grafo[p].size() ; i++){
            
            int v = grafo[p][i] ;
            
            grau[v] -- ;
            
            if(grau[v] == 0) fila.push(v) ;
            
        }
        r.push_back(p) ;
    }
    
    if(ini < n) cout << "*\n" ;
    else{
        for(int i = 0 ; i < n ; i++) cout << r[i] << "\n" ;
    }
}
