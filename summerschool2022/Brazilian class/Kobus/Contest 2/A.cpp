#include<bits/stdc++.h> 
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int inf = 1e9 ; 

int n, diam, dist[maxn], cam[maxn], vis[maxn], pa, pb, c ;
pair<int,int> dp[maxn] ;  
vector<int> grafo[maxn] ; 

void dfs_diam(int v, int p){

	vis[v] = 1 ; 

	dp[v] = {0, v} ; 

	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		dfs_diam(a, v) ; 
		if(diam < dp[v].first + 1 + dp[a].first){
			diam = dp[v].first + 1 + dp[a].first ; 
			pa = dp[v].second, pb = dp[a].second ; 
		}
		if(dp[v].first < dp[a].first + 1){
			dp[v] = {dp[a].first + 1, dp[a].second} ; 
		}
	}

}

bool dfs(int v, int p){

	vis[v] = 1 ; 

	if(grafo[v].size() == 0) cam[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ; 
		bool viss = dfs(a, v) ; 
		if(viss) cam[v] = 1 ; 
	}

	return cam[v] ; 
}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i < n ; i++){
		int g, f ; 
		cin >> f >> g ; 
		grafo[f].push_back(g) ; grafo[g].push_back(f) ; 
	}

	dfs_diam(1, 1) ; 

	if(diam == n - 1){
		int pc = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			if(i != pa && i != pb){
				pc = i ; break ; 
			}
		}
		cout << diam << "\n" << pa << " " << pb << " " << pc << "\n" ; 
		exit(0) ; 
	}

	memset(vis, 0, sizeof vis) ; 

	cam[pa] = cam[pb] = 1 ; 
	dfs(pa, pa) ; 

	queue<int> fila ; 

	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 

	for(int i = 1 ; i <= n ; i++){
		if(cam[i]) fila.push(i), dist[i] = 0 ;
	}

	memset(vis, 0, sizeof vis) ; 

	while(!fila.empty()){
		
		int at = fila.front() ; fila.pop() ; 
		vis[at] = 1 ; 

		for(auto a : grafo[at]){
			if(vis[a]) continue ; 
			if(dist[a] > dist[at] + 1){
				dist[a] = dist[at] + 1 ; 
				fila.push(a) ; 
			}
		}

	}

	int mx = 0, ptmx = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(mx < dist[i]){
			mx = dist[i], ptmx = i ; 
		}
	}

	cout << mx + diam << "\n" << pa << " " << pb << " " << ptmx << "\n" ; 

}
