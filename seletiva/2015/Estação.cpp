#include<bits/stdc++.h>
using namespace std ; 

// imp - N S 
// par L O 
// além das restrições dadas n pode cruzar dir dif.
// ord topologica 
// faz 2x p qd colocar os pares como nivel 1 e par c 2 
// e o contrario
// e pega o min 
// qd puxar p fila puxa 
// os impares e pares separados 
// se o meu at eh impar eu somo 2 em tds da lista impar (no nivel)
// se meu at eh par somo 1 em tds da lista par 

const int maxn = 1e5 + 5 ;

int n, m, grau[maxn], grau_antes[maxn], nivel[maxn] ; 
vector<int> grafo[maxn] ;
vector<int> fila ; 

int solve(){

	int ini = 0 ; 

	while(fila.size() >= ini){

	    vector<int> impar, par ; 

		int x = fila[ini] ; ini++ ; 

		for(auto a : grafo[x]){
			grau[a]-- ; 
			if(!grau[a]){
				fila.push_back(a) ;
				if(a&1) impar.push_back(a) ; 
				else par.push_back(a) ;
			}
		}

		if(x&1){

			for(auto a : par) nivel[a] = nivel[x] + 1 ; 
			for(auto a : impar) nivel[a] = nivel[x] + 2 ;
		}

	    else{

	    	for(auto a : par) nivel[a] = nivel[x] + 2 ; 
	    	for(auto a : impar) nivel[a] = nivel[x] + 1 ;

	    }

	}

	int mx = 2 ; 

	for(int i = 1 ; i <= 2*n ; i++) mx = max(mx, nivel[i]) ; 
	fila.clear() ;
	return mx ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b, c ; 
		cin >> a >> c >> b ;
		if(c == -1) swap(a, b) ; 
		grafo[a].push_back(b) ; // A acima de B 
		grau[b]++ ; 
		grau_antes[b]++ ;
	}

	for(int i = 1 ; i <= 2*n ; i++){
		if(!grau[i] && !grafo[i].empty()) fila.push_back(i) ; 
	}

	vector<int> impar, par ; 

	for(auto a : fila){
		if(a&1) impar.push_back(a) ; 
		else par.push_back(a) ; 
	}

	// fixa q par é 1 impar 2 primeiro 
    for(auto a : par) nivel[a] = 1 ; 
	for(auto a : impar) nivel[a] = 2 ; 

	int v1 = solve() ; // ql o maior nivel se eu tiver fixado par-imp

    for(int i = 1 ; i <= 2*n ; i++) grau[i] = grau_antes[i] ; 
    for(int i = 1 ; i <= 2*n ; i++){
    	if(!grau[i] && !grafo[i].empty()) fila.push_back(i) ; 
    }

    impar.clear(), par.clear() ; 

    for(auto a : fila){
    	if(a&1) impar.push_back(a) ; 
    	else par.push_back(a) ; 
    }
    
    for(auto a : par) nivel[a] = 2 ; 
    for(auto a : impar) nivel[a] = 1 ; 

    int v2 = solve() ; 

    cout << min(v1, v2) << "\n" ; 

}
