    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    const int maxn = 2e5 + 5 ; 
     
    int n, m, a, b, grau[maxn], c, vis[maxn], vis2[maxn], qtd[maxn], comp[maxn] ; 
    vector<int> g1[maxn], g2[maxn] ; 
    pair<int,int> ar[maxn] ; 
    stack<int> fila ; 
     
    // kosaraju + ord topo 
     
    void dfs(int v){
        if(vis[v]) return ; 
    	vis[v] = 1 ; 
    	for(int a : g1[v]) dfs(a) ; 
    	fila.push(v) ; 
     
    }
     
    void dfs2(int v){
    	if(comp[v]) return ; 
    	comp[v] = c ; 
    	qtd[c]++ ; 
    	for(int a : g2[v]) dfs2(a) ; 
    }
     
    int32_t main(){
     
    	cin >> n >> m ;
     
    	for(int i = 1 ; i <= m ; i++){
    		cin >> a >> b ;
    		ar[i] = {a, b} ;  
    		g1[a].push_back(b), g2[b].push_back(a) ; 
    	}
     
    	for(int i = 1 ; i <= n ; i++){
    		if(!vis[i]) dfs(i) ; 
    	}
     
    	while(!fila.empty()){
    		int atual = fila.top() ; fila.pop() ; 
    		if(!comp[atual]) c++, dfs2(atual) ; 
    	}
     
    	for(int i = 1 ; i <= m ; i++){
    		if(comp[ar[i].first] == comp[ar[i].second]) continue ; 
    		grau[comp[ar[i].first]]++ ; 
    	}
     
    	int ok = 0 ; 
    	int resp ; 
     
    	for(int i = 1 ; i <= c ; i++){
    		if(!grau[i]) ok++, resp = i ;
    	}
     
    	if(ok > 1){
    		cout << "0\n" ; 
    		return 0 ; 
    	}
     
    	cout << qtd[resp] << "\n" ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		if(comp[i] == resp) cout << i << " " ; 
    	}
     
    	cout << "\n" ; 
     
    } 
