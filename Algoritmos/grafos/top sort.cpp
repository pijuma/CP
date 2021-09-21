#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, a, b, grau[maxn] ; 
vector<int> grafo[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ;
		grau[b]++ ; 
		grafo[a].push_back(b) ;  
	}

	queue<int> fila ; 
	for(int i = 1 ; i <= n ; i++) if(!grau[i]) fila.push(i) ;

	vector<int> v ; 

	while(!fila.empty()){
		int at = fila.front() ; fila.pop() ;
		v.push_back(at) ;  
		for(auto a : grafo[at]){
			if(!(--grau[a])) fila.push(a) ; 
		}
	} 

	for(auto a : v) cout << a << " " ; 
	cout << "\n" ; 

}
