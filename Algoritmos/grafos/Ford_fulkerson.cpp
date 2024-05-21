#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

/*
acha max_flow 
que é igual em valor ao min_cut 
com otimização "scaling algorithm" O(m^2*log(MaxC)) - rapido enough 
*/
#define pb push_back

const int N = 550 ;

int MaxC ; 

struct Ford {
    struct Edge {
        int to, f, c;
    };

    int vis[N];
    vector<int> adj[N];
    vector<Edge> edges;
    int cur = 0;

    void addEdge(int a, int b, int cap, int rcap) {
        Edge e;// cria aresta de ida
        e.to = b; e.c = cap; e.f = 0;
        edges.pb(e);
        adj[a].pb(cur++);

        e = Edge(); // cria aresta de volta
        e.to = a; e.c = rcap; e.f = 0;
        edges.pb(e);
        adj[b].pb(cur++);
    }

    int dfs(int s, int t, int f, int tempo, int val) {
        
        if(s == t) return f; // f guarda o valor min de capacidade 
        
        vis[s] = tempo;// ja visitou nessa dfs?

        for(int e : adj[s]) {
            if(edges[e].c - edges[e].f < val) continue ; 
            if(vis[edges[e].to] < tempo and (edges[e].c - edges[e].f) > 0) {
                if(int a = dfs(edges[e].to, t, min(f, edges[e].c-edges[e].f) , tempo, val)) {
                    edges[e].f += a; // inversões das arestas
                    edges[e^1].f -= a; // add no sentido contrario e remove no atual 
                    return a;//dfs retorna o min 
                }
            }
        }
        
        return 0;

    }

    int flow(int s, int t) {

        int mflow = 0, tempo = 1;
        
        for(int i = log2(MaxC) ; i >= 0 ; i--){
           while(int a = dfs(s, t, MaxC, tempo, (1<<i))){
                mflow += a; // a -> corte minimo do caminho atual 
                tempo++;
           }
           tempo++ ; 
        }
        
        return mflow; // fluxo maximo = qtd de camnihos de S pra T 
    
    }

};

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    int n, m ; cin >> n >> m ; 

    Ford F ; 

    for(int i = 1 ; i <= m ; i++){
        int a, b, c ; cin >> a >> b >> c ; 
        F.addEdge(a, b, c, 0) ;
        MaxC = max(MaxC, c) ; 
    }

    cout << F.flow(1, n) << "\n" ;

} 
