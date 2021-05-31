    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 1e5 + 5 ; 
    const int maxl = 22 ; 
     
    // ans[a] -> guarda a nivelmin de um verm p cada centroid 
    // p outros eh a nivelate o cent + qto ele guarda 
    // ln² upd -> p cada ancestral (c) de a(b) -> fazemos o min entre ans[b] e dist(a, b) (nivelna arvore normal)
    // p query -> p cada ancestral (c) de a(b) -> min dist(a, b) + ans[b] 
     
    int n, m, nivel[maxn] ; 
    int sz[maxn], pai[maxn], ans[maxn] ;
    bool mark[maxn] ;  
    int tab[maxl][maxn] ; 
    vector<int> grafo[maxn] ;
     
    void dfs(int v, int p){ //tamanho das comps
    	sz[v] = 1 ; 
    	for(auto a : grafo[v]){
    		if(mark[a] || a == p) continue ; 
    		dfs(a, v) ; 
    		sz[v] += sz[a] ; 
    	}
    }
     
    int find_cent(int v, int p, int qtd){ // achar o centroide 
    	for(auto a : grafo[v]){ 
    		if(a == p || mark[a] || 2*sz[a] <= qtd) continue ; 
    		return find_cent(a, v, qtd) ; 
    	}
    	return v ; 
    }
     
    void make_a(int v, int p){ // "montar" a arv de cent (precisa saber só pai de cada) 
     
    	dfs(v, p) ; 
    	int c = find_cent(v, p, sz[v]) ; 
    	pai[c] = p ; 
    	mark[c] = 1 ; 
     
    	for(auto a : grafo[c]){
    		if(mark[a] || a == p) continue ; 
    		make_a(a, c) ; 
    	}
     
    }
     
    void dfsd(int v, int p){ //nivel de cada cara e monta a sparse 
    	tab[0][v] = p ; 
    	for(int a : grafo[v]){
    		if(nivel[a] != -1) continue ;
    		// cout << a << " " << p << "\n" ;   
    		nivel[a] = nivel[v] + 1 ; 
    		dfsd(a, v) ; 
    	}
    }
     
    int lca(int a, int b){
    	
    	if(nivel[a] > nivel[b]) swap(a, b) ; // b  
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(nivel[tab[i][b]] >= nivel[a] && tab[i][b] != -1) b = tab[i][b] ;  
    	}
     
    	if(a == b) return a ; 
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(tab[i][a] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
    	}
     
    	return tab[0][a] ; 
     
    }
     
    void upd(int v){
    	
    	int cur = v ; 
    	
    	while(cur){
    		ans[cur] = min(ans[cur], nivel[v] + nivel[cur] - 2*nivel[lca(v, cur)]) ; 
    		cur = pai[cur] ; 
    	}
     
    }
     
    int query(int v){
     
    	int mn = maxn, cur = v ;
     
    	while(cur){
    		mn = min(mn, nivel[v] + nivel[cur] - 2*nivel[lca(cur, v)] + ans[cur]) ; 
    		cur = pai[cur] ; 
    	}
     
    	return mn ; 
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> m ; 
     
    	for(int i = 1, a, b ; i < n ; i++){
    		cin >> a >> b ; 
    		grafo[a].push_back(b), grafo[b].push_back(a) ; 
    	}
     
    	for(int i = 0 ; i < maxl ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			tab[i][j] = -1 ;  
    		}
    	}
     
    	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 
     
    	nivel[1] = 0 ; 
    	dfsd(1, 0) ; //nivel p achar dist(a, b)
     
    	for(int i = 1 ; i < maxl ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			if(tab[i-1][j] == -1) continue ; 
    			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
    		}
    	}
     
    	/*for(int i = 1 ; i <= n ; i++) cout << " pai de " << i << " é " << tab[0][i] << "\n" ; 
    	/*cout << "DEBUG:\n" ; 
    	for(int i = 1 ; i < maxl ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			cout << "subindo " << i << " a partir do " << j << " chegamos em " << tab[i][j] << "\n" ; 
    		}
    	}
     
    	cout << "\n" ;*/ 
     
    	make_a(1, 0) ; // "monta" a tree de cent 
     
    	for(int i = 1 ; i <= n ; i++) ans[i] = maxn ; // nenhum vermei 
    	upd(1) ; // marca o 1o como vermei
     
    	for(int i = 1 ; i <= m ; i++){
    		int u, v ; 
    		cin >> u >> v ; 
    		if(u == 1) upd(v) ; //v vira vermei 
    		else cout << query(v) << "\n" ; //qual vermei + prox ? 
    	}
     
    }
