#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 3e5 + 5 ; 
const int maxl = 24 ; 

int n, nivel[maxn], bit[maxn][55], v[maxn], q, tipo, u, x, tin[maxn], tout[maxn], tab[maxl][maxn] ; 
int timer = 1 ; 
vector<int> grafo[maxn] ; 

void dfs(int v, int p){
	
	tin[v] = timer++ ; 
	tab[0][v] = p ; 

	for(auto a : grafo[v]){
		if(a == p || nivel[a] != -1) continue ; 
		nivel[a] = nivel[v] + 1 ; 
		dfs(a, v) ; 
	}

	tout[v] = timer++ ; 
}

struct BIT{

	void upd(int pos, int cor, int val){
		for(; pos < maxn ; pos += pos&-pos) bit[pos][cor] += val ; 
	}

    vector<int> query(int r){

    	vector<int> f(52) ; 

    	for(int i = 1 ; i <= 50 ; i++) f[i] = 0 ; 

    	for(; r > 0 ; r -= r&-r){
    		for(int i = 1 ; i <= 50 ; i++){
    			f[i] += bit[r][i] ; 
    		}
    	}

    	return f ; 

    }


} Bit ; 

int solve(int a, int b, int lca){
	//1, até tin[a] 
	vector<int> fa = Bit.query(tin[a]), fb = Bit.query(tin[b]), flca = Bit.query(tin[lca]) ; 

	vector<int> resp(53) ; 

	for(int i = 1 ; i <= 50 ; i++){
		resp[i] = fa[i] + fb[i] - 2*flca[i] ; 
	}

	resp[v[lca]]++ ; 

	int ct = 0 ; 

	for(int i = 1 ; i <= 50 ; i++){
		if(resp[i] > 0) ct++ ; 
	}

	return ct ; 

}

int _lca(int a, int b){

	if(nivel[a] < nivel[b]) swap(a, b) ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && nivel[tab[i][a]] >= nivel[b]) a = tab[i][a] ; 
	}

	if(a == b) return a ; 

	for(int i = maxl - 1 ; i >= 0 ; i--){
		if(tab[i][a] != -1 && tab[i][b] != -1 && tab[i][a] != tab[i][b]) a = tab[i][a], b = tab[i][b] ; 
	}

	return tab[0][a] ; 

}

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1, a, b ; i < n ; i++){
		cin >> a >> b ; 
		grafo[a].push_back(b), grafo[b].push_back(a) ; 
	}

	for(int i = 1 ; i <= n ; i++) nivel[i] = -1 ; 

	for(int i = 0 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			tab[i][j] = -1 ; 
		}
	} // setando 

	nivel[1] = 0 ; 
	dfs(1, -1) ; //nivel, tin, tout, pai

	for(int i = 1 ; i < maxl ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(tab[i-1][j] == -1) continue ; 
			tab[i][j] = tab[i-1][tab[i-1][j]] ; //ancestrais
		}
	}

	for(int i = 1 ; i <= n ; i++) Bit.upd(tin[i], v[i], 1), Bit.upd(tout[i] + 1, v[i], -1) ; //att começo cores

	cin >> q ; 
    
    while(q--){

    	cin >> tipo >> u >> x ; 
    	
    	if(tipo == 1){
    		Bit.upd(tin[u], v[u], -1), Bit.upd(tout[u] + 1, v[u], 1) ; 
    		v[u] = x ; 
    		Bit.upd(tin[u], v[u], 1), Bit.upd(tout[u] + 1, v[u], -1) ; 
    	}

    	else{
    		int lca = _lca(u, x) ; 
    		cout << solve(u, x, lca) << "\n" ; 
    	}

    }

}
