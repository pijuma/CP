#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 3e5 + 5 ; 

// pega f1 = px + py + pz, f2 = px + py - pz, f3 = px - py + pz, f4 = px - py - pz
// guarda o maior e o menor p cada componente 
//  na query tenta combinar o maior de uma com o maior da outra p respectivo fx 
// e pega o maior valor
// p rollback guarda o valor anterior de ambos os caras unidos 
// e maximiza p novo valor os 4 primeiros e minimiza os 4 ultimos 

struct P{
	int x, y, z ; 
} ; 

struct info{ // infos p rollback
	
	int era_pai, e_pai, sz_era_pai ; 
	int tab_era_pai[9], tab_e_pai[9] ;

	void ini(){
		era_pai = e_pai = sz_era_pai = -1 ; 
	}

} ; 

int n, q ; 
int pai[maxn], sz[maxn] ; 
int tab[maxn][9] ; 
vector<info> last_op ;  
P p[maxn] ; 

void ini_val(){

	for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

	for(int i = 1 ; i <= n ; i++){ // inicialmente max = min 
		tab[i][1] = tab[i][5] = p[i].x + p[i].y + p[i].z ; 
		tab[i][2] = tab[i][6] = p[i].x - p[i].y + p[i].z ;
		tab[i][3] = tab[i][7] = p[i].x + p[i].y - p[i].z ;
		tab[i][4] = tab[i][8] = p[i].x - p[i].y - p[i].z ;
	}

}

struct DSU{

	int find(int a){ return (pai[a] == a ? a : find(pai[a])) ; }

	void salva_uniao(int a, int b){

		info une ; 
		une.era_pai = a, une.e_pai = b ; 
		une.sz_era_pai = sz[a] ; 

		for(int i = 1 ; i <= 8 ; i++) une.tab_era_pai[i] = tab[a][i] ; 
		for(int i = 1 ; i <= 8 ; i++) une.tab_e_pai[i] = tab[b][i] ; 

		last_op.push_back(une) ;
	}

	void join(int a, int b){
		
		a = find(a), b = find(b) ; 
		
		info neww ; 
		neww.ini() ;
		if(a == b){
			last_op.push_back(neww) ; 
			return ; 
		} 

		if(sz[a] > sz[b]) swap(a, b) ; // b vai ser o pai 

		salva_uniao(a, b) ; 

		pai[a] = b, sz[b] += sz[a] ; 

		for(int i = 1 ; i <= 4 ; i++) tab[b][i] = max(tab[a][i], tab[b][i]) ; 
		for(int i = 5 ; i <= 8 ; i++) tab[b][i] = min(tab[b][i], tab[a][i]) ; 

	}
    
    void rollback(){

    	info voltar = last_op.back() ; last_op.pop_back() ; 

    	if(voltar.e_pai == -1) return ; 
    	pai[voltar.era_pai] = voltar.era_pai ; 
    	sz[voltar.e_pai] -= sz[voltar.era_pai] ;

    	for(int i = 1 ; i <= 8 ; i++) tab[voltar.era_pai][i] = voltar.tab_era_pai[i] ; 
    	for(int i = 1 ; i <= 8 ; i++) tab[voltar.e_pai][i] = voltar.tab_e_pai[i] ;

    }

} dsu ; 

int query(int a, int b){

	a = dsu.find(a), b = dsu.find(b) ; 

	int ans = 0 ; 

	for(int i = 1 ; i <= 8 ; i++){
		
		if(i <= 4){
			ans = max(ans, abs(tab[a][i] - tab[b][4+i])) ; 
		}

		else{
			ans = max(ans, abs(tab[a][i] - tab[b][i - 4])) ; 
		}

	}

	return ans ; 

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i].x >> p[i].y >> p[i].z ; 

	ini_val() ; 

    cin >> q ; 

    for(int i = 1 ; i <= q ; i++){
    	
    	int tipo, a, b ; 
    	cin >> tipo ; 

    	if(tipo == 1){
    		cin >> a >> b ; 
    		dsu.join(a, b) ; 
    	}

    	else if(tipo == 2) dsu.rollback() ; 

    	else{
    		cin >> a >> b ; 
    		cout << query(a, b) << "\n" ; 
    	}

    }

} 
