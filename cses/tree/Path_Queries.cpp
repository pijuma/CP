#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = (1<<20) ; 

int v[maxn], tin[maxn], Bit[maxn], tout[maxn], vis[maxn], timer, q, a, n, b, s, x, tipo ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	tin[v] = ++timer ; 
	for(int a : grafo[v]){
		if(a == p) continue ;  
		dfs(a, v) ; 
	}
	tout[v] = ++timer ; 
}

struct BIT{

	void upd(int pos, int val){
		for(; pos < maxn ; pos += pos&-pos) Bit[pos] += val ; 
	}
    
    int query(int pos){
    	int tot = 0 ; 
    	for(; pos > 0 ; pos -= pos&-pos) tot += Bit[pos] ; 
    	return tot ; 
    }

} bit ; 

int32_t main(){

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	dfs(1, 1) ; 

	for(int i = 1 ; i <= n ; i++){
		bit.upd(tin[i], v[i]), bit.upd(tout[i], -v[i]) ; // add na sub 
	}

	while(q--){
		cin >> tipo ; 
		if(tipo == 1){
			cin >> s >> x ; 
			bit.upd(tin[s], x - v[s]), bit.upd(tout[s], -x+v[s]) ; 
			v[s] = x ; 
		}
		else{
			cin >> s ; 
			cout << bit.query(tin[s]) << "\n" ; 
		}
	}

}
