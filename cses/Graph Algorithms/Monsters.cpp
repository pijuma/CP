#include<bits/stdc++.h>
#define mk make_pair 
#define pii pair<int,int> 
#define ll long long 
#define f first 
#define s second 
 
using namespace std ; 
 
const int maxn = 1e3 + 5; 
const int inf = 1e9 ; 
 
int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 
 
char s[maxn][maxn] ; 
int n, m, dist[maxn][maxn], distm[maxn][maxn] ;
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
	
	queue< pair<int,int> > fm ;
	queue<pii> fila ; 
 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			dist[i][j] = distm[i][j] = inf ; 
		}
	}
 
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> s[i][j] ; 
			if(s[i][j] == 'M') fm.push(mk(i, j)), distm[i][j] = 0, s[i][j] = '.' ; 
			if(s[i][j] == 'A') ini = mk(i, j), s[i][j] = '.' ; 
		}
	}
 
	while(!fm.empty()){
		pii att = fm.front() ; 
		fm.pop() ; 
		for(int i = 0 ; i < 4 ; i++){
			int cx = att.f + dx[i] ; 
			int cy = att.s + dy[i] ; 
 
			if(!valid(cx, cy) || distm[cx][cy] != inf) continue ; 
 
			distm[cx][cy] = distm[att.f][att.s] + 1 ; 
			fm.push(mk(cx, cy)) ; 
		}
	}
	
	dist[ini.f][ini.s] = 0 ; 
	pai[ini.f][ini.s] = mk(-1,-1) ; 
	fila.push(ini) ; 
 
	while(!fila.empty()){
		pii att = fila.front() ;
		fila.pop() ; 
		for(int i = 0 ; i < 4 ; i++){
			int cx = dx[i] + att.f ; 
			int cy = dy[i] + att.s ; 
 
			if(!valid(cx, cy) || s[cx][cy] == 'M' || dist[att.f][att.s] + 1 >= distm[cx][cy] || dist[cx][cy] != inf) continue ; 
 
			dist[cx][cy] = dist[att.f][att.s] + 1 ; 
			pai[cx][cy] = att ; 
			fila.push({cx, cy}) ; 
 
 		}
 
	}
	
	pii mn ;
	int mnn = inf ;  
	for(int i = 1 ; i <= n ; i++){
		if(mnn > dist[i][1]) mnn = dist[i][1], mn = mk(i, 1) ; 
		if(mnn > dist[i][m]) mnn = dist[i][m], mn = mk(i, m) ; 
	}
 
	for(int j = 1 ; j <= m ; j++){
		if(mnn > dist[1][j]) mnn = dist[1][j], mn = mk(1, j) ; 
		if(mnn > dist[n][j]) mnn = dist[n][j], mn = mk(n, j) ; 
	}
 
	vector<char> s ; 
	if(mnn == inf) cout << "NO\n" ; 
	else{
		cout << "YES\n" ; 
		cout << dist[mn.f][mn.s] << "\n" ; 
		//recuperar cam: 
		solve(mn) ; 
		cout << ans << "\n" ; 
	}
}
