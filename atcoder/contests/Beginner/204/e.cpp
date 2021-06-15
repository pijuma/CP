    #include<bits/stdc++.h>
    using namespace std ; 
    #define ll long long 
    #define pii pair<ll,ll> 
     
    const int maxn = 1e5 + 5 ;
    const ll inf = 1e15 ;
     
    ll n, m, a, c, b, d, dist[maxn] ; 
    vector<pair<ll, pii>> grafo[maxn] ;
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= m ; i++){
    		cin >> a >> b >> c >> d ; 
    		grafo[a].push_back({b, {c, d}}), grafo[b].push_back({a, {c, d}}) ; 
    	}
     
    	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> fila ; 
     
    	for(ll i = 1 ; i <= n ; i++) dist[i] = inf ; 
    	dist[1] = 0 ;  
        
        fila.push({0, 1}) ; 
     
        while(!fila.empty()){
        	ll at = fila.top().second, d = fila.top().first ; 
        	fila.pop() ; 
            if(dist[at] < d) continue ; 
        	for(pair<ll,pii> a : grafo[at]){
        		ll t = ceil((-1LL + sqrt(4 * a.second.second + 1LL))/2) - 1LL ; 
        		t = max(dist[at], t) ;
        		if(dist[a.first] > t + a.second.first + ((a.second.second)/(t+1))){
        			// cout << a.second.first << " " << a.second.second << " " << dist[at] + 1 << "\n" ; 
        			dist[a.first] = t + a.second.first + ((a.second.second)/(t+1)) ;
        			fila.push({dist[a.first], a.first}) ; 
        		}
        	}
        }
     
        if(dist[n] == inf) cout << "-1\n" ; 
        else cout << dist[n] << "\n" ; 
     
    }
