#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<int,int> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e3 + 5; 
 
int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 
 
char s[maxn][maxn] ; 
int n, m, dist[maxn][maxn] ;
pii pai[maxn][maxn], ini, fim ;  
string ans ; 
 
bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && s[i][j]!='#' ; }
 
void solve(pii par){
	
	if(par == ini) return ; 
	pii p = pai[par.f][par.s] ;
	solve(p) ; 
	if(par.f == p.f + 1) ans += 'D' ; 
	else if(p.f == par.f + 1) ans += 'U' ; 
	else if(par.s == p.s + 1) ans += 'R' ;
	else ans += 'L' ; 
 
}
 
int main(){
 
	cin >> n >> m ; 
	
	queue< pair<int,int> > fila ; 
 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> s[i][j] ; 
			if(s[i][j] == 'A') ini = mk(i, j) ; 
			if(s[i][j] == 'B') fim = mk(i, j) ; 
		}
	}
	
	dist[ini.f][ini.s] = 0 ; 
	pai[ini.f][ini.s] = mk(-1,-1) ; 
	fila.push({ini.f, ini.s}) ; 
 
	while(!fila.empty()){
		pii att = fila.front() ;
		fila.pop() ; 
		for(int i = 0 ; i < 4 ; i++){
			int cx = dx[i] + att.f ; 
			int cy = dy[i] + att.s ; 
 
			if(!valid(cx, cy) || dist[cx][cy] != 0) continue ; 
 
			dist[cx][cy] = dist[att.f][att.s] + 1 ; 
			pai[cx][cy] = att ; 
			fila.push({cx, cy}) ; 
 
 		}
 
	}

	if(dist[fim.f][fim.s] == 0) cout << "NO\n" ; 
	else{
		cout << "YES\n" ; 
		cout << dist[fim.f][fim.s] << "\n" ; 
		//recuperar cam: 
		solve(fim) ; 
		cout << ans << "\n" ; 
	}
}
