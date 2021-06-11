#include <bits/stdc++.h>
using namespace std; 

const int maxn = 1e6 + 5; 

int n, a, b, dist[maxn], p1, p2; 
vector<int> grafo[maxn];

void dfs(int v, int p){
	for(int a : grafo[v]){
		if(a == p || dist[a]) continue; 
		dist[a] = dist[v] + 1; 
		dfs(a, v);
	}
}

int main() {

	cin >> n; 

	for (int i = 1 ; i < n ; i++) {
		cin >> a >> b ; 
		grafo[a].push_back(b);
		grafo[b].push_back(a); 
	}

	dfs(1, 1); 
	
	int mx = 0, p1; 

	for (int i = 1 ; i <= n ; i++) {
		if(dist[i] > mx){
			mx = dist[i], p1 = i; 
		}
		dist[i] = 0; 
	}
	dfs(p1, p1); 
    
    int p2; 
    mx = 0; 

    for(int i = 1 ; i <= n ; i++) if(dist[i] > mx) mx = dist[i];

    cout << mx << "\n"; 

}
