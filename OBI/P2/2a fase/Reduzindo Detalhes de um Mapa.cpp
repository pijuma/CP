#include<bits/stdc++.h>
using namespace std ;

const int maxn = 510 ;
const int maxm = 124750 + 10 ;
struct t_aresta{
    int a, b, peso ; 
};

t_aresta grafo[maxm], mst[maxm] ;
int pai[maxn], peso[maxn], m, n, ans ;

int find(int x){
    
    if(x == pai[x]) return x ; 
    
    return pai[x] = find(pai[x]) ;
    
}

void join(int k, int w){
    
    k = find(k) ; 
    w = find(w) ;
    
    if(peso[k] > peso[w]) pai[w] = k ;
    else if(peso[k] < peso[w]) pai[k] = w ;
    else{
        pai[k] = w ; 
        peso[w] ++ ;
    }
}

bool cmp ( t_aresta a, t_aresta b) {return a.peso < b.peso ; }

int main(){
    
    cin >> n >> m ; 
    
    for(int i = 1 ; i <= m ; i++){
        
        cin >> grafo[i].a >> grafo[i].b >> grafo[i].peso ; 
        
    }
    
    sort(grafo, grafo + 1 + m, cmp) ;
    
    for(int i = 1 ; i <= n ; i++) pai[i] = i, peso[i] = 1 ; 
    
    int size = 0 ; 
    
    for(int i = 1 ; i <= m ; i++){
        
        int f = grafo[i].a, g = grafo[i].b ;
        
        if(find(f) != find(g)){
            
            join(f, g) ; 
            
            mst[++size] = grafo[i] ;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
            
        ans += mst[i].peso ;
    
    }
    
    cout << ans ; 
}
