    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 1e3 + 5 ; 
    const int inf = 1e9 ; 
     
    int n, m, vis[2*maxn], dist[2*maxn] ; 
    char c ;
    vector<int> grafo[2*maxn] ;
     
    int main(){
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= m ; j++){
    			cin >> c ;
    			if(c == '#') grafo[i].push_back(j+n), grafo[j+n].push_back(i) ;
    		}
    	}
     
    	for(int i = 1 ; i <= n ; i++) dist[i] = inf, vis[i] = 0 ; 
     
    	vis[1] = 1, dist[1] = 0 ; 
        queue<int> fila ; 
        fila.push(1) ;
     
        while(!fila.empty()){
        	auto at = fila.front() ; fila.pop() ;
        	for(auto a : grafo[at]){
        		if(!vis[a]){
        			vis[a] = 1 ;
        			dist[a] = dist[at] + 1 ; 
        			fila.push(a) ; 
        		}
        	}
        }
     
        cout << (dist[n] == inf ? -1 : dist[n]) << "\n" ; 
     
    }
