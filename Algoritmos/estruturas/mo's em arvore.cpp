#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, difc, sq, id2, a, b, pos[maxn], resp[maxn], timer, cor[maxn], vis[maxn], f[maxn], tin[maxn], tout[maxn] ; 
map<int,int> mapa ; 
 
struct Q{
	int l, r, idx ; 
} ; 
 
Q q[maxn] ; 
vector<int> grafo[maxn] ; 
vector<int> arr ;
 
bool cmp(Q a, Q b){
	if(a.l/sq != b.l/sq) return a.l < b.l ; 
	return (((a.l/sq) & 1) ? (a.r < b.r) : (a.r > b.r));
}
 
void add(int x){
	if(!f[arr[x]]) difc++ ; 
	f[arr[x]]++ ; 
}
 
void remove(int x){
	f[arr[x]]-- ; 
	if(!f[arr[x]]) difc-- ; 
}
 
void dfs(int v, int p){
 
	arr.push_back(cor[v]) ; 
	pos[v] = timer++ ; 
	vis[v] = 1 ; 
 
	for(auto a : grafo[v]){
		if(a == p || vis[a]) continue ;
		dfs(a, v) ;  
	}
 
	arr.push_back(cor[v]) ; 
	q[id2++] = {pos[v], timer++, v} ; 
 
}
 
int main(){
 
	cin >> n ; 
 
	int ct = 0 ; 
 
	for(int i = 1 ; i <= n ; i++){
		cin >> cor[i] ; 
		if(mapa.find(cor[i]) == mapa.end()) mapa[cor[i]] = ++ct ;
		cor[i] = mapa[cor[i]] ;  
	}
 
	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ;
	}
 
	dfs(1, 1) ; 
 
	sq = 300 ; 
 
	sort(q, q + n, cmp) ;
 
	int ini = 0, fim = -1 ; 
 
	for(int i = 0 ; i < n ; i++){
		
		int L = q[i].l, R = q[i].r ; 
 
		while(ini > L) add(--ini) ;  
		while(ini < L) remove(ini++) ; 
		while(fim < R) add(++fim) ; 
		while(fim > R) remove(fim--) ;
 
		resp[q[i].idx] = difc ;
 
	} 
 
	for(int i = 1 ; i <= n ; i++) cout << resp[i] << " " ; 
 
	cout << "\n" ; 
 
}
