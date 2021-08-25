    // ir de 1 a n  -> mais curto possivel e menor n° s/ funcionar e dxnd o maior n° possivel 
    // das q n funcionam p fora 
    // gangue vai explodir tds as estradas  q funcionam q n estam no caminho
    // printar tds as q devem ser consertadas (serão usadas) com n° 1 
    // e tds q serão destruidas com n° 0 
    // minimiza dist e minimiza qtd de broken 
     
    #include<bits/stdc++.h>
    #define pii pair<int,int>
    using namespace std ; 
     
    const int  maxn = 1e5 + 5 ; 
    const int inf = 1e9 ; 
     
    struct edge{
    	int a, b, c ;
    } ; 
     
    int n, m, work, dist[maxn], dist_broken[maxn] ; 
    pair<int,int> pai[maxn] ; 
    map<pair<int,int>, int> mark ; 
    edge ed[maxn] ; 
    vector<pair<int,int>> grafo[maxn] ; 
     
    void dij(){
     
    	for(int i = 1 ; i <= n ; i++) dist[i] = dist_broken[i] = inf ; 
    	dist[1] = dist_broken[1] = 0 ;
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> fila ; 
        fila.push({0, {0, 1}}) ;
     
        while(!fila.empty()){
     
        	int at = fila.top().second.second ; fila.pop() ;
     
        	for(auto a : grafo[at]){
        		if(dist[a.first] > dist[at] + 1 || (dist[a.first] == dist[at] + 1 && dist_broken[a.first] > dist_broken[at] + (a.second == 0))){
        			dist[a.first] = dist[at] + 1 ; 
        			dist_broken[a.first] = dist_broken[at] + (a.second == 0) ; 
        			fila.push({dist[a.first], {dist_broken[a.first], a.first}}) ; 
        			pai[a.first] = {at, a.second} ;
        		}
        	}
     
        }
     
    }
     
    int main(){
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= m ; i++){
    		int a, b, c ; 
    		cin >> a >> b >> c ;
    		ed[i] = {a, b, c} ;  
    		if(c == 1) work++ ; 
     		grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ; 
    	}
     
    	dij() ; 
     
    	cout << 2*dist_broken[n] + (work - dist[n]) << "\n" ;  
    	
    	int v = n ; 
     
    	while(v != 1){
    		int w = pai[v].second, u = pai[v].first ; 
    		if(w == 0) cout << u << " " << v << " " << 1 << "\n" ; 
    		else mark[{u, v}] = mark[{v, u}] = 1 ; 
    		v = u ; 
    	}
     
    	for(int i = 1 ; i <= m ; i++){
    		if(mark[{ed[i].a, ed[i].b}] == 0 && ed[i].c == 1) cout << ed[i].a << " " << ed[i].b << " " << 0 << "\n" ; 
    	}
     
    }
