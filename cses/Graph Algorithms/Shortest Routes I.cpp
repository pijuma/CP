#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<ll,ll> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5; 
const ll inf = 1e18 ; 
 
ll n, m, dist[maxn], a, b, c ;  
vector<pii> grafo[maxn] ; 
 
int main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ; 
		grafo[a].push_back(mk(b, c)) ; 
	}
 
	for(int i = 1 ; i <= n ; i++) dist[i] = inf ; 
 
	priority_queue<pii, vector<pii>, greater<pii> > fila ;  
	fila.push(mk(0,1)) ; 
	dist[1] = 0 ; 
 
	while(!fila.empty()){
		pii att = fila.top() ; 
		fila.pop() ; 
		
		if(att.f != dist[att.s]) continue ; 
 
		for(pii a : grafo[att.s]){
 
			if(dist[a.f] > dist[att.s] + a.s){
				dist[a.f] = dist[att.s] + a.s ;
				fila.push(mk(dist[a.f], a.f)) ; 
			}
 
		}
 
	}
 
	for(int i = 1 ; i <= n ; i++) cout << dist[i] << " " ; 
	cout << "\n" ; 
 
}
