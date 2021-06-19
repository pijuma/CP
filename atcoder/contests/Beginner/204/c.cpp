    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 2e3 + 5 ; 
     
    int n, sub[maxn], m, a, b, mark[maxn] ; 
    vector<int> grafo[maxn] ; 
     
    void dfs(int v, int p){
    	sub[v] = 1 ;
    	mark[v] = 1 ; 
    	for(int a : grafo[v]){
    		if(a == p || mark[a]) continue ; 
    		dfs(a, v) ;
    		sub[v] += sub[a] ;
    	}
    }
     
    int main(){
     
    	cin >> n >> m ; 
     
    	for(int i = 1 ; i <= m ; i++){
    		cin >> a >> b ; 
    		grafo[a].push_back(b) ; 
    	}
     
    	int ans = 0 ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int i = 1 ; i <= n ; i++) sub[i] = 0, mark[i] = 0 ; 
    		dfs(i, i) ; 
    	    ans += sub[i] ; 
    	}
     
    	cout << ans << "\n" ; 
     
    }
