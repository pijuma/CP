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
		tree.push_back(neww) ; 
		return tree.size() - 1 ;   
	}

	int upd(int pos, int i, int j, int x, int val){
		
		int neww = create(pos) ; 
		
		if(i == j){ // folha 
			tree[neww].soma = val ; 
			return neww ; 
		}

		if(x <= meio){
			int aux ; 
			aux = upd(tree[neww].esq, i, meio, x, val) ;
			tree[neww].esq = aux ;
		}  
		else{
			int aux ; 
			aux = upd(tree[neww].dir, meio + 1, j, x, val) ;
			tree[neww].dir = aux ;  
		}

		tree[neww].soma = tree[tree[neww].esq].soma + tree[tree[neww].dir].soma ; 
		return neww ; 

	}

	int query(int pos, int i, int j, int l, int r){

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
	tree.push_back(ini) ; root.push_back(0), root.push_back(0) ; 

	for(int i = 1 ; i <= n ; i++){
		int x ; 
		cin >> x ; 
		root.back() = seg.upd(root.back(), 1, n, i, x) ; 
	}

	for(int i = 1 ; i <= q ; i++){

		int t, k, a, b ; 
		cin >> t >> k ; 

		if(t == 3){
			root.push_back(seg.create(root[k])) ;
			continue ;  
		}

		cin >> a >> b ; 

		if(t == 2) cout << seg.query(root[k], 1, n, a, b) << "\n" ; 

		else root[k] = seg.upd(root[k], 1, n, a, b) ; 

	}

}
