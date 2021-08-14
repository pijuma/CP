    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 3e5 + 25 ; 
     
    struct Q{
    	int l, r, id ; 
    } ; 
     
    int n, q, timer, val[maxn], sq, block[maxn] ; 
    int ini[maxn], fim[maxn] ; 
    bool mark[maxn] ; 
    int tin[maxn], tout[maxn], linear[maxn], ans[maxn], freq[maxn], meu_bloco[maxn] ; 
    Q query[maxn] ; 
    vector<int> valors = {0} ; 
    vector<pair<int,int>> grafo[maxn] ; 
     
    void dfs(int v, int pai){
     
    	tin[v] = ++timer ; 
     
    	for(auto a : grafo[v]){
    		if(a.first == pai) continue ; 
    		val[a.first] = a.second ; 
    		dfs(a.first, v) ; 
    	}
     
    	tout[v] = ++timer ; 
     
    	linear[tout[v]] = linear[tin[v]] = v ; //euler tour 
     
    }
     
    void e(int x){
     
    	if(!mark[x]) return ; //retirado ou par 
    	if((--freq[val[x]])) return ; 
    	block[meu_bloco[val[x]]]++ ;  
     
    }
     
    void i(int x){
     
    	if(!mark[x]) return ; 
    	if((freq[val[x]]++)) return ; 
    	block[meu_bloco[val[x]]]-- ; 
     
    }
     
    void change(int x){
     
    	x = linear[x] ; 
     
    	e(x) ; 
    	mark[x] = !mark[x] ; 
    	i(x) ; 
     
    }
     
    bool cmp(Q a, Q b){
     
    	if(meu_bloco[a.l] == meu_bloco[b.l]) return (meu_bloco[a.l]&1 ? a.r < b.r : a.r > b.r) ; 
    	return a.l < b.l ; 
     
    }
     
    int get_ans(){
     
    	for(int i = 1 ; i <= meu_bloco[valors.size()-1] ; i++){
     
    		if(block[i]) for(int j = ini[i] ; j <= fim[i] ; j++) if(!freq[j]) return valors[j] ; 
     
    	}
        
        return 0 ; 
     
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> q ; 
     
    	for(int i = 1 ; i < n ; i++){
     
    		int u, v, w ; 
     
    		cin >> u >> v >> w ; 
    		
    		valors.push_back(w), valors.push_back(w+1) ; 
    		grafo[u].push_back({v, w}), grafo[v].push_back({u, w}) ; 
     
    	}
     
    	sort(valors.begin(), valors.end()) ; 
    	valors.erase(unique(valors.begin(), valors.end()), valors.end()) ; 
     
    	dfs(1, -1) ; 
     
    	for(int i = 1 ; i <= q ; i++){
     
    		int u, v ; 
     
    		cin >> u >> v ; 
     
    		if(u == v) continue ; 
    		if(tin[u] > tin[v]) swap(u, v) ; 
     
    		Q at ; 
    		at.l = tin[u] + 1 ;
    		at.r = tin[v] ;
    		at.id = i ; 
    		query[i] = at ;  
     
    	}
     
    	int m = valors.size() ;  
     
    	sq = sqrt(2*n) + 1 ; 
     
    	for(int i = 1, k = 0, j = sq ; i <= 2*n ; i++, j++){
     
    		if(j == sq){
    			k++ ; 
    			j = 0 ; 
    		}
     
    		meu_bloco[i] = k ; 
     
    	}
     
    	sq = sqrt(m) + 1 ;
     
    	sort(query + 1, query + 1 + q, cmp) ; 
     
    	for(int i = 1 ; i <= n ; i++) val[i] = lower_bound(valors.begin(), valors.end(), val[i]) - valors.begin() ; 
     
    	for(int i = 0, k = 0, j = sq ; i < m ; i++, j++){
     
    		if(j == sq){
    			k++ ; 
    			ini[k] = i ; 
    			j = 0 ; 
    		}
     
    		meu_bloco[i] = k ; 
    		fim[k] = i ; 
     
    	}
     
        for(int i = 0 ; i <= meu_bloco[valors.size()-1] ; i++) block[i] = fim[i] - ini[i] + 1 ; 
     
    	int ini = 1, fim = 0 ; 
     
    	for(int i = 1 ; i <= q ; i++){
     
    		int l = query[i].l, r = query[i].r, id = query[i].id ; 
     
    		while(l < ini) change(--ini) ;
    		while(l > ini) change(ini++) ; 
    		while(r > fim) change(++fim) ;
    		while(r < fim) change(fim--) ; 
     
    		ans[id] = get_ans() ;
     
    	}
     
    	for(int i = 1 ; i <= q ; i++) cout << ans[i] << "\n" ; 
     
    }
