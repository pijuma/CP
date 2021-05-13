#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<ll,ll> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
const ll inf = 1e18 ; 
 
ll n, m, dist[maxn], a, b, c, k ; 
vector<pii> grafo[maxn] ; 
vector<ll> d[maxn] ; 
 
int main(){
 
	cin >> n >> m >> k ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ; 
		a--, b-- ; 
		grafo[a].push_back(mk(c, b)) ; 
	}
 
	priority_queue< pii, vector<pii>, greater<pii> > fila ; 
 
	fila.push(mk(0, 0)) ; 
 
	while(!fila.empty()){
 
		pii at = fila.top() ; 
		fila.pop() ; 
 
		if(d[at.s].size() >= k) continue ; 
		d[at.s].push_back(at.f) ;
 
		for(pii a : grafo[at.s]){
			fila.push(mk(at.f + a.f, a.s)) ;
		}
	}
 
	for(int i = 0 ; i < k ; i++){
		cout << d[n-1][i] << " " ; 
	}
 
}
