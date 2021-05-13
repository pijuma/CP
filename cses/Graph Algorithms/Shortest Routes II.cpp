#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<ll,ll> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 500 + 5; 
const ll inf = 1e18 ; 
 
ll n, m, q, dist[maxn][maxn], a, b, c ; 
 
int main(){
 
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
	cin >> n >> m >> q ; 
	//floyd 
	
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= n ; j++){
			dist[i][j] = inf ; 
			dist[j][j] = 0 ; 
		}
	}
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b >> c ;
		dist[a][b] = min(dist[a][b], c) ; 
		dist[b][a] = min(dist[b][a], c) ; 
	}
 
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ; 
			}
		}
	}
 
	for(int i = 1 ; i <= q ; i++){
		cin >> a >> b ; 
		cout << (dist[a][b] != inf ? dist[a][b] : -1) << "\n" ;
	}
}
