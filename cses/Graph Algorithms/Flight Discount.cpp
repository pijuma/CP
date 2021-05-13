#include<bits/stdc++.h>
#define mk make_pair 
#define ll long long 
#define pii pair<int, int> 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 2e5 + 5 ;  
const ll inf = 1e18 ; 
 
ll n, m, q, dist[maxn][2], a, b, c, vis[maxn] ; 
vector<pii> grafo[maxn] ; 
ll pai[maxn] ; 
 
int main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back({b, c}) ; 
	}
 
	for(int i = 1 ; i <= n ; i++) dist[i][1] = dist[i][0] = inf ; 
 
	priority_queue< pair<ll,pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>> > fila ; 
    dist[1][0] = dist[1][0] = 0 ; 
    fila.push({0, {1, 0}}) ;
 
    while(!fila.empty()){
    	
    	int at = fila.top().second.first ;
    	ll d = fila.top().first ;
    	int k = fila.top().second.second ; 
    	fila.pop() ; 
    	if (dist[at][k] != d) continue;
    	for(pii a : grafo[at]){
    		
    		if(!k && dist[a.first][1] > d + a.second/2){
    			dist[a.first][1] = dist[at][0] + a.second/2 ;
    			fila.push({dist[a.first][1],{a.first, 1}}) ; 
    		}
 
    		if(dist[a.first][k] > d + a.second){
    			dist[a.first][k] = d + a.second ; 
    			fila.push({dist[a.first][k],{a.first, k}}) ; 
    		}
 
    	}
 
    }
 
    cout << dist[n][1] << "\n" ; 
 
}
