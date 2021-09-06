#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
using namespace std ; 

const int maxn = 1e5 + 5 ; 

// um cara c nivel tecnico menor recebe += OU qd um subordinado seu recebe += 
// monta a arvore 
// faz dfs tin/tout 
// guarda nivel[d].p() // pega tds os caras com nivel d e guarda num vector
// sorta p td nivel do menor nivel tecnico p maior 
// pega primeiro os q tao num nivel maior 
// faz query tin,tout + 1 ou ant + 1 e faz o max entre esses 2 
// e att a posição do tin p at 
// faz uma seg de maximo 

int timer, tree[4*maxn], n, tin[maxn], tout[maxn], nivel_t[maxn] ; 
long long resp ; 
vector<int> nivel[maxn], grafo[maxn] ;

struct SEG{

	void upd(int no, int i, int j, int pos, int val){
		
		if(i == j && i == pos){
			tree[no] = val ; 
			return ; 
		}

		if(pos <= meio) upd(esq, i, meio, pos, val) ; 
		else upd(dir, meio + 1, j, pos, val) ; 
		
		tree[no] = max(tree[esq], tree[dir]) ; 

	}

	int query(int no, int i, int j, int a, int b){
		
		if(a > j || b < i) return 0 ;
		if(a <= i && b >= j) return tree[no] ; 

		return max(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;
	
	}

} seg ; 

void dfs(int v, int p, int d){

	tin[v] = ++timer ; 
	nivel[d].push_back(v) ; 

	for(auto a : grafo[v]){
		if(a == p) continue ; 
		dfs(a, v, d + 1) ; 
	}

	tout[v] = timer ; 

}

bool cmp(int a, int b){ return nivel_t[a] < nivel_t[b] ; }

int32_t main(){

	cin >> n ; 

	for(int i = 2 ; i <= n ; i++){
		int v ;
		cin >> v ; 
		grafo[v].push_back(i), grafo[i].push_back(v) ;
	}

	for(int i = 1 ; i <= n ; i++) cin >> nivel_t[i] ; 

	dfs(1, 1, 0) ; 

	for(int i = 1 ; i <= n ; i++) sort(nivel[i].begin(), nivel[i].end(), cmp) ; 

	for(int i = n ; i >= 0 ; i--){ // o de nivel + baixo eh oq recebe menos ent começa por ele

		int ant = 0 ; 

		for(auto a : nivel[i]){
			long long ans = max(seg.query(1, 1, n, tin[a], tout[a]), ant) + 1 ; // um a mais q o maior subordinado dele ou um a mais q
			// o anterior dele (tem nivel tecnico menor q ele - sortado) 
			resp += ans ; 
			ant = ans ; 
			seg.upd(1, 1, n, tin[a], ans) ;  
		}

	}

	cout << resp << "\n" ; 

}
