#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e6 + 5 ;

int n, q, sz[maxn], pai[maxn], w[maxn] ;
vector<int> grafo[maxn] ;

struct DSU{
    
    int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }
    
    void join(int a, int b, int ar){ // aresta de a até b 
        
        int val = w[b] - w[a] + ar ; //vou ligar o meu ao meu novo pai - "zero o meu valor" e agr tenho o valor da aresta 
        //+ o valor do cara q eu vou ligar
        a = find(a), b = find(b) ;
        
        if(a == b) return ; 
        
        if(grafo[a] > grafo[b]){ // vai ligar de b pra a -> inverte valor 
            val = -val ; 
            swap(a, b) ;
        }
        
        for(auto g : grafo[a]){
            w[g] += val ; 
            pai[g] = b ;
            grafo[b].push_back(g) ;
        }
        
    }
    
} dsu ; 

int32_t main(){
    
    cin >> n >> q ; 
    
    for(int i = 1 ; i <= n + 2 ; i++){
         pai[i] = i, grafo[i].push_back(i) ;
    }
    
    for(int i = 1 ; i <= q ; i++){
        
        char t ; 
        int a, b, sum ; 
        
        cin >> t >> a >> b ; 
        
        b++ ; 
        
        if(t == 'L'){
            cin >> sum ; 
            dsu.join(a, b, sum) ; 
            continue ; 
        }
        
        if(dsu.find(a) != dsu.find(b)) cout << "Esquecido\n" ;
        else cout << w[a] - w[b] << "\n" ;
        
    }

    
}
