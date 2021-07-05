//  QTREE 
#include<bits/stdc++.h>

#define pii pair<int,int> 

#define esq (2*no)
#define dir ((2*no)+1) 
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e4 + 5 ; 

int n, t, c, qtd ; 
int sz[maxn], pai[maxn], edge[maxn], nivel[maxn] ; 
int tree[4*maxn] ; 
int head[maxn], pos[maxn], camin[maxn] ; 
//qual o "pai" do meu caminho, qual a pos do meu vertice num geral e a qual caminho eu faço parte
vector<pii> grafo[maxn] ; 
pii edge_ind[maxn] ; 


struct SEG{

	void update(int no, int i, int j, int pos, int val){
		
		if(i == j && pos == i){
			tree[no] = val ; 
			return ; 
		}

		if(pos <= meio) update(esq, i, meio, pos, val) ; 
		else update(dir, meio + 1, j, pos, val) ; 

		tree[no] = max(tree[esq], tree[dir]) ; 

	}

	int query(int no, int i, int j, int l, int r){

		if(l > j || r < i) return -1 ; 

		if(l <= i && r >= j) return tree[no] ; 

		return max(query(esq, i, meio, l, r), query(dir, meio + 1, j, l, r)) ; 

	}

} seg ; 

void dfs(int v, int p){

	sz[v] = 1 ; 

	for(auto a : grafo[v]){
		if(a.first == p) continue ; 
		nivel[a.first] = nivel[v] + 1 ; 
		pai[a.first] = v ; 
		edge[a.first] = a.second ; 
		dfs(a.first, v) ; 
		sz[v] += sz[a.first] ;  
	}

}

void hld(int v){

	if(!head[c]) head[c] = v ; //se eu for o 1o do meu caminho -> sou o pai dela 

	pos[v] = ++qtd, camin[v] = c ; //faço parte do caminho c

	seg.update(1, 1, n, pos[v], edge[v]) ; //marcar minha pos com o valor da minha aresta 

	int maior = -1, id = -1 ; 

	for(auto a : grafo[v]){
		if(a.first == pai[v]) continue ; 
		if(sz[a.first] > maior){
			maior = sz[a.first], id = a.first ; 
		} 
	}

	if(id != -1) hld(id) ; // faz p componente pesada primeiro -> fica mais rapido 

	for(auto a : grafo[v]){
		if(a.first == pai[v] || a.first == id) continue ;
		c++ ; //cria um novo caminho p cada leve 
		hld(a.first) ;  
	}

}

void update(int a, int b){ //updata o de maior nivel 
	
	if(nivel[edge_ind[a].first] < nivel[edge_ind[a].second]) swap(edge_ind[a].first, edge_ind[a].second) ; 
	
	edge[edge_ind[a].first] = b ; 
	seg.update(1, 1, n, pos[edge_ind[a].first], b) ; 

}

int lca(int a, int b){

	// se o lca estiver no "meio do caminho" ambos tem q estar na msm corrente 

	while(camin[a] != camin[b]){
		if(nivel[head[camin[a]]] > nivel[head[camin[b]]]) a = pai[head[camin[a]]] ; 
		else b = pai[head[camin[b]]] ; 
	}

	if(nivel[a] < nivel[b]) return a ; 
	else return b ; 

}

int query_path(int a, int b){

	int ans = 0 ; 

	while(camin[a] != camin[b]){
		ans = max(ans, seg.query(1, 1, n, pos[head[camin[a]]], pos[a])) ; //sobe nas chains 
		a = pai[head[camin[a]]] ; 
	}

	if(pos[a] == pos[b]) return ans ; 

	return ans = max(ans, seg.query(1, 1, n, pos[b] + 1, pos[a])) ; //se o lca e o kra tao na msm chain
	// mas n sao iguais, tem q contar esse caminho de um ao outro tb 

}

int query(int a, int b){

	int l = lca(a, b) ; 
	
	return max(query_path(a, l), query_path(b, l)) ; 

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> t ;

	while(t--){

		cin >> n ; 

		for(int i = 1 ; i < n ; i++){
			int a, b, c ; 
			cin >> a >> b >> c ; 
			edge_ind[i] = {a, b} ; // no upd ele muda a ith aresta
			grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ;  
		}

		dfs(1, 0) ; //pegar sz...

		hld(1) ; //montar o hld 

		while(true){

			string s ; 
			int a, b ; 

			cin >> s ; 

			if(s == "DONE") break ; 

			cin >> a >> b ; 

			if(s == "CHANGE") update(a, b) ; 
			else cout << query(a, b) << "\n" ; 

		}

		c = 0, qtd = 0 ; 

		for(int i = 1 ; i <= n ; i++) grafo[i].clear() ; 
		memset(tree, 0, sizeof tree), memset(head, 0, sizeof head) ; 

	} 
  
}
