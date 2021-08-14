    #include<bits/stdc++.h>
    #define int long long 
     
    #define f first 
    #define s second 
    #define pii pair<int,int>
     
    using namespace std ; 
     
    const int maxl = 22 ; 
    const int maxn = 1e5 + 5 ; 
    const int mod = 1e9 + 7 ; 
     
    int n, timer, tin[maxn], low[maxn], c, q, sz[maxn], comp[maxn] ;
    int bridge[maxn], vis[maxn], m, cnt[maxn], sum_t[maxl][maxn] ; 
    int cor[maxn], tab[maxl][maxn], nivel[maxn] ; 
    vector<pii> grafo[maxn] ; 
    vector<int> tree[maxn] ; 
     
    void find_b(int v, int p){
     
    	tin[v] = low[v] = ++timer ; 
     
    	for(auto a : grafo[v]){
    		
    		if(a.f == p) continue ;
    		if(tin[a.f]){
    			low[v] = min(low[v], tin[a.f]) ; 
    			continue ; 
    		} 
     
    		find_b(a.f, v) ; 
     
    		if(low[a.f] > tin[v]) bridge[a.s] = 1 ; 
     
    		low[v] = min(low[v], low[a.f]) ; 
     
    	}
     
    }
     
    void dfs(int v, int cmp){
    	
    	vis[v] = 1 ; 
    	comp[v] = cmp ; 
     
    	for(auto a : grafo[v]){
    		if(vis[a.f] || bridge[a.s]) continue ; 
    		dfs(a.f, cmp) ; 
    	}
     
    }
     
    void dfs_lca(int v, int p){
     
    	tab[0][v] = p ; 
    	cnt[v] = (cnt[p] + cor[v])%mod ; 
     
    	for(auto a : tree[v]){
    		if(nivel[a] != -1 || a == p) continue ;
    		nivel[a] = nivel[v] + 1 ; 
    		dfs_lca(a, v) ;  
    	}
     
    }
     
    int lca(int a, int b){
     
    	if(nivel[a] > nivel[b]) swap(a, b) ; 
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(tab[i][b] != -1 && nivel[tab[i][b]] >= nivel[a]) b = tab[i][b] ; 
    	}
     
    	if(a == b) return a ; 
     
    	for(int i = maxl - 1 ; i >= 0 ; i--){
    		if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
    	}
     
    	return tab[0][a] ; 
     
    }
     
    int exp(int a, int b){
    	
    	int ans = 1 ; 
     
    	while(b){
    		if(b&1) ans = (ans*a)%mod ; 
    		a = (a*a)%mod ; 
    		b >>= 1 ; 
    	}
     
    	return ans ; 
    	
    }
     
    int32_t main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= m ; i++){
     
    		int a, b ; 
    		cin >> a >> b ; 
     
    		grafo[a].push_back({b, i}), grafo[b].push_back({a, i}) ; 
     
    	}
     
    	find_b(1, 1) ; 
     
    	// acha as pontes, dfs p cada comp (guarda tam tb), comps difs - une, comp sz = 1, branco other - preto 
    	// faz dfs p achar qts pretos p cada u até a raiz 
    	// lca 
     
    	for(int i = 1 ; i <= n ; i++){
    		if(!vis[i]) dfs(i, ++c) ; 
    	}
     
    	for(int i = 1 ; i <= n ; i++){
    		
    		for(auto a : grafo[i]){
    			
    			if(!bridge[a.s]) continue ; 
    			 
    			if(comp[i] != comp[a.f]){
    				// cout << i << " " << a.f << "  " << comp[a.f] << " " << comp[i] << "\n" ; 
    				tree[comp[i]].push_back(comp[a.f]), tree[comp[a.f]].push_back(comp[i]) ; 
    			}
     
    		}
     
    	}
     
    	for(int i = 1 ; i <= n ; i++) sz[comp[i]]++ ;  
     
    	for(int i = 1 ; i <= c ; i++){
    		if(sz[i] > 1) cor[i] = 1 ; // preto 
    		else cor[i] = 0 ; //branco 
    	}
     
    	// for(int i = 1 ; i <= c ; i++) cout << cor[i] << " " ; 
    	// cout << "\n" ; 
     
    	for(int i = 0 ; i < maxl ; i++){
    		for(int j = 1 ; j <= c ; j++){
    			tab[i][j] = -1 ;  
    		}
    	}
     
    	for(int i = 1 ; i <= c ; i++) nivel[i] = -1 ; 
     
    	dfs_lca(1, 1) ; 
     
        for(int i = 1 ; i < maxl ; i++){
        	for(int j = 1 ; j <= c ; j++){
        		if(tab[i-1][j] == -1) continue ; 
        		tab[i][j] = tab[i-1][tab[i-1][j]] ; 
        	}
        }
     
        cin >> q ; 
     
        for(int i = 1 ; i <= q ; i++){
        	int a, b ; 
        	cin >> a >> b ;
        	a = comp[a], b = comp[b] ; 
        	int _lca = lca(a, b) ;  
        	int qtd = (cnt[a] + cnt[b] - 2*cnt[_lca])%mod ;
     
        	if(cor[_lca] == 1) qtd = (qtd + 1)%mod ; 
        	cout << exp(2, qtd) << "\n" ;  
     
        }
     
    }
