#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e5 + 5 ; 

int n, m ; 
vector<int> grafo[maxn], vis[maxn] ;

int qtd(int p, int q){ return lower_bound(grafo[p].begin(), grafo[p].end(), q + 1) - grafo[p].begin() ; }

int dfs(int v, int q){
    
    if(q == vis[v].size()) return 0 ; //ja visitei tds 
    
    int resp = vis[v][q] ; // se eu ja tiver visitado retorno 
    
    if(resp) return resp ;
    
    return vis[v][q] = max(dfs(grafo[v][q], qtd(grafo[v][q], v)) + 1, dfs(v, q + 1)) ; // marco como visitado e calculo o tamanho max
    // ir p cara ou ignorar ele 
    
}

int main(){
    
    cin >> n >> m ; 
    
    for(int i = 1 ; i <= m ; i++){
        
        int a, b ; 
        cin >> a >> b ; 
        
        grafo[a].push_back(b), grafo[b].push_back(a) ;
        vis[a].push_back(0), vis[b].push_back(0) ;
        
    }
    
    for(int i = 1 ; i <= n ; i++) sort(grafo[i].begin(), grafo[i].end()) ; 
    
    for(int i = 1 ; i <= n ; i++) cout << 1 + dfs(i, 0) << " " ;
    cout << "\n" ;
    
}
