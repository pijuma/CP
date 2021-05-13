#include<bits/stdc++.h>
#define int long long 
using namespace std ; 
 
const int maxn = 1e5 + 5 ; 
 
int n, m, a, b, vis1[maxn], vis2[maxn] ; 
vector<int> g1[maxn], g2[maxn] ; 
 
void dfs(int v, int p){
	vis1[v] = 1 ; 
	for(int a : g1[v]){
		if(vis1[a] || a == p) continue ; 
		dfs(a,v) ; 
	}
}
 
void dfs2(int v, int p){
	vis2[v] = 1 ; 
	for(int a : g2[v]){
		if(vis2[a] || p == a) continue ; 
		dfs2(a,v) ; 
	}
}
 
int32_t main(){
 
	cin >> n >> m ; 
 
	for(int i = 1 ; i <= m ; i++){
		cin >> a >> b ; 
		g1[a].push_back(b), g2[b].push_back(a) ; 
	}
 
	dfs(1,1), dfs2(1,1) ;
 
	int k1 = 0, k2 = 0 ; 
	bool ok = 1 ; 
 
	for(int i = 1 ; i <= n ; i++){
		if(vis1[i] == 0) ok = 0, k1 = i ;
		if(vis2[i] == 0) ok = 0, k2 = i ; 
	} 
 
	if(ok) cout << "YES\n" ;
    else{
        cout << "NO\n" ;
        if(k1 != 0) cout << 1 << " " << k1 << "\n" ;
        else cout << k2 << " " << 1 << "\n" ;
    }
 
