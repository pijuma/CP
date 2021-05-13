#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<int,int> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
 
int n, m, a, b, vis[maxn] ; 
vector<pii> par ; 
vector<int>grafo[maxn] ; 
vector<int> v ; 
 
void dfs(int v){
	
	vis[v] = 1 ; 
 
	for(auto a : grafo[v]){
		if(!vis[a]) dfs(a) ; 
	}
 
}
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		int a, b ; 
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}
 
	for(int i = 1 ; i <= n ; i++){
		if(!vis[i]) v.push_back(i), dfs(i) ; 
	}
 
	cout << v.size() - 1 << "\n" ; 
	for(int i = 1 ; i < v.size() ; i++) cout << v[0] << " " << v[i] << "\n" ; 
 
}
