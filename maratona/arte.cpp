#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 2 ; 

int n, m, k, val[maxn], e[maxn], d[maxn], cima[maxn], baixo[maxn], pai[maxn] ; 

struct C{
	int x, y, raio ; 
} ; 

C v[maxn] ; 

long long dist(C a, C b){ return (a.x - b.x)*(a.x-b.x) + (a.y - b.y)*(a.y-b.y) ; }

struct DSU{

	int find(int a){ return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }

	void join(int a, int b){
		a = find(a), b = find(b) ; 
		if(a == b) return ; 
		e[a] = min(e[a], e[b]), d[a] = max(d[a], d[b]) ; 
		cima[a] = min(cima[a], cima[b]), baixo[a] = max(baixo[a], baixo[b]) ; 
		pai[b] = a ; 
	}

} dsu ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> m >> n >> k ;

	for(int i = 1 ; i <= k ; i++){
		pai[i] = i ; 
		cin >> v[i].x >> v[i].y >> v[i].raio ;
		d[i] = v[i].x + v[i].raio ; e[i] = v[i].x - v[i].raio ; 
		cima[i] = v[i].y - v[i].raio ; baixo[i] = v[i].y + v[i].raio ;  
	}

	for(int i = 1 ; i <= k ; i++){
		for(int j = 1 ; j <= k ; j++){
			if(dist(v[i], v[j]) <= (v[i].raio + v[j].raio)*(v[i].raio + v[j].raio)) dsu.join(i, j) ;
		}
	}

	bool ok = 1 ; 

	for(int i = 1 ; i <= k ; i++){
		if(e[i] <= 0 && cima[i] <= 0) ok = 0 ; 
		if(d[i] >= m && baixo[i] >= n) ok = 0 ; 
		if(e[i] <= 0 && d[i] >= m) ok = 0 ; 
		if(cima[i] <= 0 && baixo[i] >= n) ok = 0 ; 
	}

	cout << (ok ? "S\n" : "N\n") ; 

}
