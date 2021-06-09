#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
vector<int> grafo[maxn] ; 
int a, n, b, ans, used[maxn] ;
 
void dfs(int v, int p){
	for(int a : grafo[v]){
		if(a == p || used[a]) continue ;
		dfs(a, v) ; 
		if(!used[v] && !used[a]) used[v] = used[a] = 1, ans++ ; //folha + cara antes 
	}
}
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}
 
	dfs(1, 1) ; 
 
	cout << ans << "\n" ; 
 
}
