#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<int,int> 
#define pb push_back
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 
 
int n, m, a, b, cor[maxn], pai[maxn] ; 
vector<int> grafo[maxn] ; 
 
void dfs(int v, int c){
 
	if(~cor[v]){
		if(cor[v]^c){ //mesma cor em adj 
			cout << "IMPOSSIBLE\n" ; 
			exit(0) ;
		}
		return ; 
	}
	cor[v] = c ; 
	for(int a : grafo[v]) dfs(a, c^1) ; 
 
}
 
int main(){
 
	cin >> n >> m ;
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		grafo[a].pb(b), grafo[b].pb(a) ; 
	}
  
	memset(cor, -1, sizeof cor) ; 
  
	for(int i = 1 ; i <= n ; i++) if(cor[i] == -1) dfs(i, 0) ; 
 
	for(int i = 1 ; i <= n ; i++) cout << ++cor[i] << " " ; 
	cout << "\n" ; 
 
}
