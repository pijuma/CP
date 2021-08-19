#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, m, v[maxn], a, b, ans, pos[maxn] ; 
 
int main(){
 
	cin >> n >> m ; 
	
	ans = 1 ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i], pos[v[i]] = i ; 
 
	for(int i = 2 ; i <= n ; i++) ans += pos[i-1] > pos[i] ;
 
	while(m--){
 
		cin >> a >> b ; 
 
		int tipo = 1 ; 
 
		if(a > b) swap(a, b) ; // a smp menor 
 
		
		if (v[b] == v[a]+1) tipo = 1;
		else if (v[a] == v[b]+1) tipo = 2;
		else tipo = 0 ; 
 
		if(tipo != 2) ans -= (pos[v[a]-1] > pos[v[a]]) ; 
		ans -= pos[v[a]] > pos[v[a] + 1] ; 
		ans -= pos[v[b]-1] > pos[v[b]] ; 
		ans -= pos[v[b]] > pos[v[b] + 1] ; 
 
		swap(pos[v[a]], pos[v[b]]) ; 
		swap(v[a], v[b]) ; 
 
		if(tipo != 1) ans += pos[v[a]-1] > pos[v[a]] ; 
		ans += pos[v[a]] > pos[v[a] + 1] ;
		ans += pos[v[b]-1] > pos[v[b]] ; 
		ans += pos[v[b]] > pos[v[b]+1] ; 
 
		cout << ans << "\n" ; 
 
	}
 
}
