/*
algoritmo de min cost/max flow ford fulkerson 
O(max_flow*E)
cria aresta normal e invertida com a capacidade - faz uma dfs pra pegar o caminho 
e sai subtraindo a menor capacidade do caminho todo 
dai inverte as arestas - faz isso enquanto der 
*/
const int N = 2000010;

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

    int dfs(int s, int t, int f, int tempo) {
        
        if(s == t) return f; // f guarda o valor min de capacidade 
        
        vis[s] = tempo;// ja visitou nessa dfs?

        for(int e : adj[s]) {
            if(vis[edges[e].to] < tempo and (edges[e].c - edges[e].f) > 0) {
                if(int a = dfs(edges[e].to, t, min(f, edges[e].c-edges[e].f) , tempo)) {
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
        
        while(int a = dfs(s, t, INF, tempo)) {
            mflow += a; // a -> corte minimo do caminho atual 
            tempo++;
        }
        
        return mflow; // fluxo maximo = qtd de camnihos de S pra T 
    
    }

};
