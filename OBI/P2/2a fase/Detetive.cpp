#include<bits/stdc++.h>
using namespace std ; 

// A -> B, se A ocorreu B tb A - causa B - conseq 
// se A -> B e C -> B se B ocorreu n podemos dizer qual ocorreu A ou B 
// se B ocorreu tds os eventos na qual ele é causa ocorreram 
// se B ocorreu e só tem UM EVENTO em que ele é consequência ent esse ocorreu 

const int maxn = 1e3 + 5 ; 

int E, I, V, a, b, grau[maxn], comp, vis[maxn] ;
bitset<maxn> s[maxn] ; 
vector<int> grafo[maxn], vdd, imp ; 

void dfs(int v){

	vis[v] = comp ; 
	s[v].set(imp[comp]) ; // marco tds os caras q se acontecerem eu serei vdd

	for(auto a : grafo[v]){
		if(vis[a] == comp) continue ; 
		dfs(a) ; 
	}

}

int main(){

	cin >> E >> I >> V ; // eventos , implicações, verdades 

	memset(vis, -1, sizeof vis) ; 

	for(int i = 1 ; i <= I ; i++){
		cin >> a >> b ; 
		grafo[a-1].push_back(b-1) ;
		grau[b-1]++ ;  
	}

	for(int i = 1 ; i <= V ; i++){
		cin >> a ;
		vdd.push_back(a-1) ; 
	}

	for(int i = 0 ; i < E ; i++) if(grau[i] == 0) imp.push_back(i) ; // pego tds os caras q se acontecerem o pai eh vdd 
	// e aproveito e marco as conseqs tb  

	for(comp = 0 ; comp < imp.size()  ; comp++) dfs(imp[comp]) ; // faço uma dfs p cada p marcar eles  

	vector<int> ans ; 

    for(int i = 0 ; i < E ; i++){
    	
    	for(int j = 0 ; j < V ; j++){
    		if((s[i]&s[vdd[j]]) == s[vdd[j]]){ // se isso eh vdd eh pq eles "tem" os msms caras ent n tem duas causas 
    			ans.push_back(i) ; 
    			break ; 
    		} 
    	}

    }

    sort(ans.begin(), ans.end()) ;

    for(auto a : ans) cout << a + 1 << " " ; 
    cout << "\n" ; 

}
