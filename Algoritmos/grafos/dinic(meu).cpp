/*
Implementação do algoritmo de edmond-karp 
resolve problema do fluxo máximo/corte mínimo
fluxo maximo que consegue ir do source ao sink 
e o corte minimo (igual ao fluxo maximo) é a menor soma das capacidades para 
gerar uma partição no grafo 
Edmonds carp 
usa estrutura de busca em camadas ao invés de bfs/dfs para checar se ainda tem caminho 
o que faz com que a complexidade seja O(E*V^2) diferente do EK que é O(E^2*V)
O uso do ptr evita o recalculo em arestas já processadas
tirando um *E, passamos por cada aresta apenas uma vez 
ptr mantém o indice da proxima aresta a ser processada
na lista de adj do nó u 
iteramos na lista de adj de u a partir do indice ptr[u]
assim evitamos repertir a busca em arestas ja processadas 
o que melhora a eficiencia em grafos densos 
*/

#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

#define f first 
#define s second 
#define pb push_back 
#define pii pair<int,int> 

typedef long long T ; 

struct EK{

    const T inf =  0x3f3f3f3f3f3f3f3fll ;

    struct Edge{
        int u, c, f ; // nó, capacidade e fluxo 
        Edge(int u, int f, int c) : u(u), f(f), c(c) {}
    } ;

    vector<Edge> edges ; // guarda os nós 
    vector<vector<int>> g ; // grafo 
    vector<int> d ; // distancias 
    vector<int> ptr ; // diferente do EK 

    EK(int n){ // inicializacao 
        g.assign(n+5, vector<int>()) ;
        d.resize(n+5) ; 
    }

    void add_edge(int u, int v, int c){
        g[u].pb(edges.size()) ; // adicionando a aresta de u pra v 
        edges.pb({v, 0, c}) ;
        g[v].pb(edges.size()) ; // adicionando v-u 
        edges.pb({u, c, c}) ; // no começo o fluxo passa todo na inversa
    }

    bool bfs(int source, int sink){ // tem algum caminho source->sink que ainda de pra reduzir (cam aumentante)?
        
        fill(d.begin(), d.end(), -1) ; 
        
        queue<int> q ; d[source] = 0 ; 
        q.push(source) ; 

        while(q.size()){
            
            int u = q.front() ; q.pop() ; 

            for(auto a : g[u]){
                
                Edge ed = edges[a] ;

                if(ed.f < ed.c && d[ed.u] == -1){
                    d[ed.u] = d[u] + 1 ; 
                    q.push(ed.u) ;
                }

            }

        }

        return d[sink] != -1 ; // conseguiu visitar = tem caminho aumentante 

    }

    int dfs(int u, int sink, int mn){ // no atual, final, menor fluxo disponivel 
        
        if(mn == 0 || u == sink) return mn ; 

        for(int *i = ptr[u] ; i < g[u]).size() ; i++{
            Edge ed = edges[a] ; 
            if(!(ed.f < ed.c && d[ed.u] == d[u] + 1)) continue ; 
            if(int x = dfs(ed.u, sink, min(mn, ed.c-ed.f)) > 0){// menor valor indo dps 
                //precisa aumentar o fluxo na normal e reduzir na invertida 
                edges[a].f += x ; // normal
                edges[a^1].f -= x ; // invertida
                return x ; 
            }
        }

        return 0 ; 

    }

    int max_flow(int source, int sink){

        int ans = 0 ; 

        while(bfs(source, sink)){ // enquanto tiver caminho aumentante
            fill(ptr.begin(), ptr.end(), 0) ; // diferente do EK 
            ans += dfs(source, sink, inf) ; // pego ele 
        }   

        return ans ; 

    }

} ;

int32_t main(){

    int n, m ; cin >> n >> m ;

    EK ek(n) ;

    for(int i = 1 ; i <= m ; i++){
        int u, v, c ; cin >> u >> v >> c ; 
        ek.add_edge(u, v, c) ;
    }

    cout << ek.max_flow(1, n) << "\n" ; 

}
