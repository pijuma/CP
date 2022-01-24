#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int inf = 1e18 ; 

int n, q, mn, vis[maxn], a[maxn], grau[maxn], c[maxn] ; 
vector<int> grafo[maxn] ; 

int f(int u){

	vis[u] = 1 ;  
	int resp = c[u] ; 

	if(!vis[a[u]]) resp = min(resp, f(a[u])) ; 

	return resp ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> c[i] ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a[i] ;
		grau[a[i]]++ ;  
	} 

	queue<int> ans ; 
	for(int i = 1 ; i <= n ; i++) if(!grau[i]) ans.push(i) ; 

	while(!ans.empty()){
		int x = ans.front() ; 
		ans.pop() ; 
		grau[a[x]]-- ; 
		if(grau[a[x]] == 0) ans.push(a[x]) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		if(grau[i] && !vis[i]){
			mn += f(i) ; 
		}
	}

	cout << mn << "\n" ; 

}
