//B. Cthulhu
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 110 ; 

int n, m, mark[maxn], comp ; 
int tem_ciclo ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	
	mark[v] = 1 ; 

	for(auto a : grafo[v]){
		if(!mark[a]) dfs(a, v) ;
		else if(mark[a] == 1 && a != p) tem_ciclo++ ;  
	}

	mark[v] = 2 ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]) dfs(i, i), comp++ ;
	} 

	cout << (tem_ciclo == 1 && comp <= 1 ? "FHTAGN!\n" : "NO\n") ; 

}
