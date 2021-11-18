#include<bits/stdc++.h>
#define int long long 
#define meio ((i+j)>>1)
using namespace std ; 

struct Node{
	int soma, esq, dir ; 
} ; 

vector<Node> tree ; 
vector<int> root ; 

struct SEG{

	int create(int pos){
		Node neww ;
		neww.esq = tree[pos].esq, neww.dir = tree[pos].dir ;
		neww.soma = tree[pos].soma ; 
		tree.push_back(neww) ; //criar um nó "repetido"
		return tree.size() - 1 ;   
	}

	int upd(int pos, int i, int j, int x, int val){
		
		int neww = create(pos) ; 
		
		if(i == j){ // folha 
			tree[neww].soma = val ; // alterar ele  
			return neww ; // retornar p meu pai que eu sou o filho da dir/esq dele 
		}

		if(x <= meio){ // se for do lado esq só mudo ele n mudo o resto 
			int aux ; 
			aux = upd(tree[neww].esq, i, meio, x, val) ; // qm é meu novo filho (criou outro)
			tree[neww].esq = aux ;
		}  
		else{
			int aux ; 
			aux = upd(tree[neww].dir, meio + 1, j, x, val) ;
			tree[neww].dir = aux ;  
		}

		tree[neww].soma = tree[tree[neww].esq].soma + tree[tree[neww].dir].soma ; 
		// muda o valor do meu novo vertice
		return neww ; // retorna o meu novo vertice (recursivo)

	}

	int query(int pos, int i, int j, int l, int r){ // query seg normal

		if(pos == 0 || i > r || j < l) return 0 ; 
		if(l <= i && r >= j) return tree[pos].soma ; 

		int lef = query(tree[pos].esq, i, meio, l, r) ;
		int rig = query(tree[pos].dir, meio + 1, j, l, r) ; 
		return lef + rig ; 

	}

} seg ;

int n, q ; 

int32_t main(){

	cin >> n >> q ; 

	Node ini ; 
	ini.soma = 0, ini.esq = 0, ini.dir = 0 ; 
	tree.push_back(ini) ; // para n ter que fazer build 
	root.push_back(0), root.push_back(0) ; // 0 - invalida  

	for(int i = 1 ; i <= n ; i++){
		int x ; 
		cin >> x ; 
		root.back() = seg.upd(root.back(), 1, n, i, x) ; 
		// cout << root.back() << "\n" ; 
	}

	for(int i = 1 ; i <= q ; i++){

		int t, k, a, b ; 
		cin >> t >> k ; 

		if(t == 3){ // criar uma copia 
			root.push_back(seg.create(root[k])) ; // crio um novo vertice que "puxa do meu antigo" 
			continue ;  
		}

		cin >> a >> b ; 

		if(t == 2) cout << seg.query(root[k], 1, n, a, b) << "\n" ; // qt vale a soma de a a b no vetor k 

		else root[k] = seg.upd(root[k], 1, n, a, b) ; //mudo valor do kra a p b no vetor k

	}

}
