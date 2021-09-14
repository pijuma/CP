#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int inf = 1e18 ; 
const int maxn = 1e5 + 5 ; 

int dist[maxn][200] ; 
vector<pair<int,int>> grafo[maxn] ;
int n, m, q, ini, fim ;
string s ;
map<pair<int,int>, int> mp ;

struct vertice{

	int a, b, x ;

	int operator>(vertice c) const{return b > c.b ; }
		
} ;

int32_t main() {

	cin >> n >> m >> q >> ini >> fim ;

	getline(cin, s) ; getline(cin, s) ; stringstream ss(s);

	int v = ini;
	int u ; 

	while (ss >> u){	
		mp[{v, u}] = 1 ;
		v = u ;
	}
	
	for(int i = 1 ; i <= m ; i++) {
		int a, b, c ; 
		cin >> a >> b >> c ;
		grafo[a].push_back({b, c}) ;
	}

	priority_queue<vertice, vector<vertice>, greater<vertice> > fila ;

	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 100; j++){
			dist[i][j] = inf ;
		}
	}

	fila.push({ini, 0, 0}) ; dist[ini][0] = 0 ;

	while (!fila.empty()){

		vertice at ; 
		at = fila.top() ; fila.pop() ;
		int b = at.a, p = at.b, x = at.x ; 

		for (auto a : grafo[b])	{
			
			int ve = a.first, pes = a.second ;  
			int qf = min(100*1LL, x + (mp[{b, ve}]^1)) ;
			
			if (dist[ve][qf] > dist[b][x] + pes){ dist[ve][qf] = dist[b][x] + pes ; fila.push({ve, dist[ve][qf], qf}) ;}

		}

	}

	for(int i = 1 ; i <= q ; i++){
		
		int k, d, resp ; 
		cin >> k >> d ; resp = inf ;
		
		for (int j = k ; j <= 100; j++) resp = min(resp, dist[fim][j]) ;
		cout << (abs(resp - dist[fim][0]) > d ?  "NAO" : "SIM") << "\n" ;
	}

}	



