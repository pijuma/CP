    #include<bits/stdc++.h>
    #define ll long long 
    using namespace std ;
     
    const int maxn = 1e5 + 5 ; 
    const int maxl = 20 ; 
    const int inf = 1e9 ; 
     
    int tab[maxl][maxn], max_t[maxl][maxn], min_t[maxl][maxn] ;
    int nivel[maxn], n, a, b, c, q ; 
    map<pair<int,int>, int> g ;
    vector<int> grafo[maxn] ; 
     
    void dfs(int v, int p){
    	
    	tab[0][v] = p ; 
    	max_t[0][v] = g[{v,p}] ; 
    	min_t[0][v] = g[{v,p}] ; 
     
    	for(int i : grafo[v]){
    		if(nivel[i] != -1) continue ; 
    		nivel[i] = nivel[v] + 1 ; 
    		dfs(i, v) ;
    	}
     
    }
     
    pair<int,int> lca(int u, int v){
     
    	int mn = inf, mx = 0 ; 
     
    	if(nivel[u] > nivel[v]) swap(u, v) ; //v mais longe
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(tab[i][v] != -1 && nivel[tab[i][v]] >= nivel[u]){
    			mx = max(max_t[i][v], mx) ; 
    			mn = min(min_t[i][v], mn) ;
    			v = tab[i][v] ; 
    		}
    	}
     
    	if(u == v) return make_pair(mn, mx) ; 
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(tab[i][v] != tab[i][u] && tab[i][u] != -1){
    			mx = max({max_t[i][u],max_t[i][v], mx}) ; 
    			mn = min({min_t[i][v], mn, min_t[i][u]}) ;
    			v = tab[i][v], u = tab[i][u] ; 
    		}
    	}
     
    	mx = max({mx, max_t[0][u], max_t[0][v]}) ; 
    	mn = min({mn, min_t[0][v], min_t[0][u]}) ; 
    	return make_pair(mn, mx) ; 
     
    }
     
    int main(){
     
    	cin >> n ; 
     
    	for(int i = 1 ; i < n ; i++){
    		cin >> a >> b >> c ;
    		grafo[a].push_back(b), grafo[b].push_back(a) ; 
    		g[{a,b}] = c, g[{b,a}] = c ; 
    	}
     
    	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 
     
    	for(int i = 0 ; i < maxl ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			tab[i][j] = -1 ; 
    			max_t[i][j] = 0 ; 
    			min_t[i][j] = inf ; 
    		}
    	}
     
    	nivel[1] = 0 ; 
    	dfs(1, -1) ; 
     
    	for(int i = 1 ; i < maxl ; i++){
    		for(int j = 1 ; j <= n ; j++){
    		    if(tab[i-1][j] == -1) continue ; 
    			tab[i][j] = tab[i-1][tab[i-1][j]] ; 
    			max_t[i][j] = max(max_t[i-1][j], max_t[i-1][tab[i-1][j]]) ; 
    			min_t[i][j] = min(min_t[i-1][j], min_t[i-1][tab[i-1][j]]) ;  
    		}
    	}
     
    	cin >> q ; 
     
    	for(int i = 1 ; i <= q ; i++){
    		cin >> a >> b ; 
    		cout << lca(a, b).first << " " << lca(a, b).second << "\n" ; 
    		//menor - maior
    	}
    }   
