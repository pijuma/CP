#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m ; 
int dx[maxn], dy[maxn], vis[maxn], a, b ; 
vector<int> gc[maxn], gq[maxn] ; 

int diam(int f, vector<int> grafo[maxn], int t){

	for(int i = 1 ; i <= t ; i++) dx[i] = -1, dy[i] = -1, vis[i] = 0 ; 

	vector<int> fila ; 
    fila.push_back(f), vis[f] = 1 ; 
    int ini = 0 ; 
    
    while(ini < fila.size()){
    	
    	int a = fila[ini] ; 
    	ini++ ; 
    	
    	for(int b : grafo[a]){
    		if(vis[b]) continue ;
    		vis[b] = 1 ; 
    		fila.push_back(b) ;  
    	}

    }

    int last = fila[fila.size()-1] ; 
    fila.clear() ; 
    dx[last] = 0, fila.push_back(last), ini = 0 ; 

    while(ini < fila.size()){
    	
    	int a = fila[ini] ; 
    	ini++ ; 

    	for(int b : grafo[a]){
    		if(dx[b] != -1) continue ; 
    		dx[b] = dx[a] + 1 ; 
    		fila.push_back(b) ; 
    	}

    }

    int ponta2 = fila[fila.size()-1] ; 
    int d = dx[ponta2] ; 
    int raio = (d+1)/2 ; 

    fila.clear() ; 
    dy[ponta2] = 0, fila.push_back(ponta2), ini = 0 ; 

    while(ini < fila.size()){
    	
    	int a = fila[ini] ; 
    	ini++ ; 

    	for(int b : grafo[a]){
    		if(dy[b] != -1) continue ; 
    		dy[b] = dy[a] + 1 ; 
    		fila.push_back(b) ; 
    	}

    }
    
    int centro ; 

    for(int i = 1 ; i <= t ; i++){
    	if(dx[i] + dy[i] == d && max(dx[i], dy[i]) == raio) centro = i ; 
    }

    return centro ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		gq[a].push_back(b), gq[b].push_back(a) ; 
	}

	for(int i = 1 ; i < m ; i++){
		cin >> a >> b ; 
		gc[a].push_back(b), gc[b].push_back(a) ; 
	}

	int cq = diam(1, gq, n), cc = diam(1, gc, m) ; 

	cout << cq << " " << cc << "\n" ; 

}
