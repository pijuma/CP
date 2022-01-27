#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 3e5 + 5 ; 
const int inf = 1e18 + 5 ; 

int l, r, c, n, ini, fim, vis[maxn], v[maxn], ct, dist[maxn] ; 
int imagin[maxn] ;
vector<int> mp ;  
vector<pair<int,int>> grafo[maxn] ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> l >> r >> c ; 
	cin >> ini >> fim ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
	for(int i = 1 ; i <= n ; i++) mp.push_back(v[i]) ; 
	
	sort(mp.begin(), mp.end()) ; 
    mp.erase(unique(mp.begin(), mp.end()), mp.end()) ; 

    for(int i = 1 ; i <= n ; i++) v[i] = lower_bound(mp.begin(), mp.end(), v[i]) - mp.begin() + 1 ; 

	for(int i = 1 ; i <= n ; i++){
		if(i != n) grafo[i].push_back({i+1, r}) ; 
		if(i != 1) grafo[i].push_back({i-1, l}) ; 
	}

	ct = n ; 

	for(int i = 1 ; i <= n ; i++){
		if(imagin[v[i]] == 0) imagin[v[i]] = ++ct ; 
	}

	for(int i = 1 ; i <= n ; i++){
		grafo[imagin[v[i]]].push_back({i, 0}) ;
		grafo[i].push_back({imagin[v[i]], c}) ;  
	}

	for(int i = 1 ; i <= ct ; i++) dist[i] = inf ; 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 
	dist[ini] = 0 ; 
	fila.push({0, ini}) ; 

	while(!fila.empty()){
		int at = fila.top().second ; fila.pop() ; 
		if(vis[at]) continue ; 
		vis[at] = 1 ; 
		for(auto a : grafo[at]){
			if(dist[a.first] > dist[at] + a.second){
				dist[a.first] = dist[at] + a.second ; 
				fila.push({dist[a.first], a.first}) ; 
			}
		}
	}

	cout << dist[fim] << "\n" ; 

}
