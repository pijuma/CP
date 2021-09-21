#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 200010 ; 

int l[maxn], r[maxn], x[maxn], ct, n, m ;
int vis[5*maxn], grau[5*maxn] ; 
int tree[4*maxn] ;

vector <int> grafo[5*maxn] ;

struct SEG{

	void build(int no, int i, int j){

		if(i == j){

			tree[no] = i ; //está no vetor 
			return ; 

		}

		build(esq, i, meio), build(dir, meio + 1, j) ; 

		tree[no] = ++ct ;

		grafo[tree[no]].push_back(tree[esq]) ; //árvore
		grafo[tree[no]].push_back(tree[dir]) ; 

	}

	void make_graph(int no, int i, int j, int a, int b, int x){

		if(a > j || b < i) return ; 
		
		if(a <= i && b >= j){

			grafo[x].push_back(tree[no]) ; //conecta o vertice x ao bloco no que guarda o intervalo 
			// de valores que gostaríamos de ligar na entrada
			return ; 

		}

		make_graph(esq, i, meio, a, b, x), make_graph(dir, meio + 1, j, a, b, x) ;


	}

} seg ;

void dfs(int x){ // marcar o grau p cada vertice 

	vis[x] = 1 ; 

	for(auto u : grafo[x]){

		grau[u]++ ;

		if(!vis[u]) dfs(u) ;

	}

}

bool check(){

	memset(vis, 0, sizeof vis), memset(grau, 0, sizeof grau) ;

	for(int i = 1 ; i <= 5*maxn ; i++){
		if(!vis[i]) dfs(i) ; //grau 
	}

	vector<int> fila ; 

	for(int i = 1 ; i <= 5*maxn ; i++){
		if(!grau[i]) fila.push_back(i) ; //1os p processar 
	}

	for(int i=0;i<fila.size();i++){
		auto att=fila[i];

		for(auto u : grafo[att]){

			grau[u]-- ; 

			if(!grau[u]) fila.push_back(u) ;

		}

	}
	
	return fila.size() == 5*maxn ; //se pegar tds é pq n tem ciclo 

}
int main(){

	cin >> n >> m ; 
	ct = n ; 

	for(int i = 1 ; i <= m ; i++) cin >> x[i] >> l[i] >> r[i] ;

	seg.build(1, 1, n) ;

	//qual a 1a linha que ao colocarmos a aresta temos um ciclo ? == bb 

	int ini = 1, fim = m, best = -1, mid ; 

	while(ini <= fim){

		mid = (ini + fim)>>1 ; 

		for(int i = 1 ; i <= n ; i++) grafo[i].clear() ; 
		for(int i = 1 ; i <= mid ; i++) seg.make_graph(1, 1, n, l[i], r[i], x[i]) ;

		if(!check()) best = mid, fim = mid - 1 ; 
	    else ini = mid + 1 ; 

	} 

	cout << best << "\n" ;

}
