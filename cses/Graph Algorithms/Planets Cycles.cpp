#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int inf = 1e9 + 5 ; 

int n, a, ans[maxn], steps, vis[maxn], dp[maxn] ; 
vector<int> grafo[maxn] ; 

// path + ciclo -> retorna c ciclo 
// ciclo sozin 
// se front == back -> ciclo - tds tem o msm ans 
// faz p cada comp -> !vis[i]
// se n for ciclo vai tirando 1 do valor 
// pq ta 1 mais perto 

queue<int> path ; 

void dfs(int v){

	path.push(v) ; 

	if(vis[v]){
		steps += ans[v] ; 
		return ; 
	}

	vis[v] = 1 ; 
	steps++ ; 
	
	dfs(grafo[v][0]) ; 

}

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a ; 
		grafo[i].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++){
		
		if(!vis[i]){
			
			steps = 0 ; 
			dfs(i) ; 
			
			int dec = 1 ;

			while(!path.empty()){
				
				if(path.front() == path.back()){
					dec = 0 ; 
				}

				ans[path.front()] = steps ; 
				steps -= dec ; 
				path.pop() ; 

			}

		}

	} 

	for(int i = 1 ; i <= n ; i++) cout << ans[i] << " " ; 
	cout << "\n" ; 

}
