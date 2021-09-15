    #include<bits/stdc++.h>
    #define int long long
    using namespace std ;
     
    // liga da menor p maior aresta qd ligar eu pego a qtd de uma comp c a qtd de outra
    // e somo a multoplicação -> tds arestas colocadas são menores 
    // dps junta 
    // se tiver peso repetido 
    // monta um grafo e simula o union find dai pega o tot - o meu atual e dps add
     
    const int maxn = 1e5 + 5 ; 
     
    struct A{
    	int u, v, w, ind ; 
    } ; 
     
    int n, pai[maxn], peso[maxn], ans[maxn] ; 
    A aresta[maxn] ;
     
    bool cmp(A a, A b){ return a.w < b.w ; }
     
    struct DSU{
         
        int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }
     
        void join(int a, int b){
        	
        	a = find(a), b = find(b) ; 
        	if(a == b) return ;
        	if(peso[a] > peso[b]) swap(a, b) ; 
        	
        	peso[b] += peso[a] ; 
        	pai[a] = b ; 
     
        }
     
    } dsu ;
     
    struct Make_graph{
     
    	vector<int> grafo[maxn] ; 
    	int fat[maxn], sz[maxn], comp[maxn], tot[maxn] ; 
     
    	void ini(vector<A> &e){
    		for(auto a : e){
    			sz[a.u] = sz[a.v] = 0, tot[comp[a.u]] = tot[comp[a.v]] = 0 ;
    			comp[a.v] = comp[a.u] = 0 ;  
    			grafo[a.u].clear() ; grafo[a.v].clear() ;
    		}
    		for(auto a : e){
    			grafo[a.u].push_back(a.v) ; grafo[a.v].push_back(a.u) ;
    		}
    	}
     
    	void dfs(int v, int p, int cp){
    		
    		fat[v] = p ; 
    		comp[v] = cp ; 
    		sz[v] = peso[v] ; 
     
    		for(auto a : grafo[v]){
    			if(a == p || comp[a]) continue ; 
    			dfs(a, v, cp) ; 
    			sz[v] += sz[a] ; 
    		}
     
    		tot[cp] = sz[v] ; 
    	}
     
    } mk ; 
     
    int32_t main(){
     
    	cin >> n ; 
     
    	for(int i = 1 ; i < n ; i++){
    		int a, b, c ; 
    		cin >> aresta[i].u >> aresta[i].v >> aresta[i].w ; 
    		aresta[i].ind = i ;  
    	}
     
    	for(int i = 1 ; i <= n ; i++) pai[i] = i, peso[i] = 1 ; 
     
    	sort(aresta + 1, aresta + n, cmp) ; 
     
        for(int i = 1 ; i < n ; i++){
     
        	vector<A> graph ; 
     
        	int j ; 
        	for(j = i ; j < n && aresta[j].w == aresta[i].w ; j++){
        		graph.push_back({dsu.find(aresta[j].u), dsu.find(aresta[j].v), -1, aresta[j].ind}) ; 
        	}
     
        	j-- ;
     
        	mk.ini(graph) ; 
        	
        	int ct = 0 ; 
     
        	for(auto a : graph){
        		if(!mk.comp[a.u]) mk.dfs(a.u, a.u, ++ct) ;
        	}
     
        	for(auto a : graph){
        		if(mk.fat[a.u] == a.v) swap(a.u, a.v) ; 
        		ans[a.ind] += mk.sz[a.v]*(mk.tot[mk.comp[a.v]] - mk.sz[a.v]) ;
        	}
     
        	for(auto a : graph) dsu.join(a.u, a.v) ; 
     
        	i = j ; 
     
        }
     
        int mx = 0 ; 
     
        for(int i = 1 ; i < n ; i++) mx = max(mx, 2*ans[i]) ; 
     
        vector<int> resp ; 
     
        for(int i = 1 ; i < n ; i++){
        	if(2*ans[i] == mx) resp.push_back(i) ;  
        }
     
        cout << mx << " " << resp.size() << "\n" ; 
     
        for(auto a : resp) cout << a << " " ; 
        cout << "\n" ; 
     
    }
