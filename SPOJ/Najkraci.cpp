    #include<bits/stdc++.h>
    #define int long long 
    using namespace std ; 
     
    const int maxn = 1500 +  5 ;
    const int MAX = 5000 +  5 ; 
    const int inf = 1e9 ; 
    const int mod = 1e9 + 7 ; 
     
    int n, m, a, b ; 
    int dp[maxn], dp2[maxn], ans[MAX], vis[maxn], vis2[maxn], fim ; 
    vector<pair<int,int>> grafo[maxn], g2[maxn] ; 
    vector<pair<int,pair<int,int>>> edges ;
    int dist[maxn] ; 
     
     
    void solve1(int v, int p){ // qts terminam
     
    	for(pair<int,int> a : g2[v]){
    		if(dist[a.first] + a.second != dist[v]) continue ;
    		if(vis[a.first] == 0) solve1(a.first, v) ;
    		dp[v] = (dp[a.first] + dp[v])%mod ;  
    	}
    	
    	vis[v] = 1 ; 
     
    	return ;
     
    }
     
    int dfs(int v, int p){ // qts comeÃ§am 
     
    	for(pair<int,int> a : grafo[v]){
    		if(dist[a.first] != dist[v] + a.second) continue ;
    		// cout << v << " " << a.first << "\n" ; 
    		fim = a.first ; 
    		dfs(a.first, v) ; 
    	}
     
    	return fim;
     
    }
     
    void solve2(int v, int p){ // qts comeÃ§am 
     
    	dp2[v] = 1 ; 
     
    	for(pair<int,int> a : grafo[v]){
    		if(dist[a.first] != dist[v] + a.second) continue ; 
    		if(vis2[a.first] == 0) solve2(a.first, v) ; 
    		dp2[v] = (dp2[a.first] + dp2[v])%mod ; //qts caras comeÃ§am no filho dele + qts comeÃ§am nele de outros
    		vis2[a.first] = 1 ; 
    	}
     
    	return ;
     
    }
     
    int32_t main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> m ; 
     
    	for(int i = 1, a, b, c ; i <= m ; i++){
    		cin >> a >> b >> c ; 
    		grafo[a].push_back({b, c}) ; g2[b].push_back({a, c}) ; 
    		edges.push_back(make_pair(c,make_pair(a,b))); 
    	}
     
    	for(int i = 1 ; i <= n ; i++){
    	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > fila ; 
     
    	for(int j = 1 ; j <= n ; j++) dist[j] = inf ; 
     
    	dist[i] = 0 ; 
    	fila.push({0, i}) ; 
     
    	while(!fila.empty()){
    		
    		int at = fila.top().second ; fila.pop() ; 
     
    		for(pair<int,int> a : grafo[at]){
    			
    			if(dist[a.first] > (dist[at] + a.second)){
    				dist[a.first] = (dist[at] + a.second) ; 
    				fila.push({dist[a.first], a.first}) ; 
    			}
     
    		}
     
    	}
     
    	for(int j = 1 ; j <= n ; j++) dp[j] = 0, dp2[j] = 0, vis[j] = 0, vis2[j] = 0 ; 
     
        fim = 0 ; 
    	// int last = dfs(i, i) ;
    	dp[i] = 1 ; 
    	for(int j = 1 ; j <= n ; j++) if(!vis[j]) solve1(j, j) ; 
    	solve2(i, i) ; 
     
    	for(int j = 0; j < m; j++) {
            int a = edges[j].second.first, b = edges[j].second.second, c = edges[j].first ;
            
            if(dist[b] == dist[a] + c) {
                ans[j]+= (dp[a]*dp2[b])%mod;
                ans[j]%= mod;
            }
        }
        }
     
    	for(int i = 0 ; i < m ; i++) cout << ans[i] << "\n" ; 
     
    } 
