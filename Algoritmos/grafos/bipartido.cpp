#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, m, cor[maxn] ; 
vector<int> grafo[maxn] ; 
bool ok = 1 ; 

void dfs(int v, int p, int c){

	cor[v] = c ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		if(cor[a] != -1){
			if(1-c == cor[a]) continue ; 
			else{
				ok = 0 ; 
				continue ;
			}
		}
		dfs(a, v, 1-c) ; 
	}

}

int main(){

	cin >> n >> m ; 

	memset(cor, -1, sizeof cor) ; 

	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	dfs(1, 1, 1) ;

	if(!ok) cout << "NO\n" ; 
	else cout << "YES\n" ; 

}
