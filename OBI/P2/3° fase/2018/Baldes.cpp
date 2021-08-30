#include<bits/stdc++.h>

#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

struct Tree{
	int ind_mx, ind_mn ; 
} ; 

int n, m, mx[maxn], mn[maxn] ; 
Tree tree[4*maxn] ; 

struct SEG{

	Tree join(Tree a, Tree b){
		Tree c ; 
		if(mn[a.ind_mn] <= mn[b.ind_mn]) c.ind_mn = a.ind_mn ; 
		else c.ind_mn = b.ind_mn ;  
		if(mx[a.ind_mx] >= mx[b.ind_mx]) c.ind_mx = a.ind_mx ; 
		else c.ind_mx = b.ind_mx ; 
		return c ; 
	}

	void build(int no, int i, int j){
		if(i == j){
			tree[no].ind_mn = tree[no].ind_mx = i ; 
			return ; 
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = join(tree[esq], tree[dir]) ; 
	}

	void upd(int no, int i, int j, int a){
		
		if(i == j){
			tree[no].ind_mn = tree[no].ind_mx = a ; 
			return ; 
		}

		if(a <= meio) upd(esq, i, meio, a) ; 
		else upd(dir, meio + 1, j, a) ; 

		tree[no] = join(tree[esq], tree[dir]) ; 

	}

	Tree query(int no, int i, int j, int a, int b){
		Tree null ; 
		null.ind_mx = null.ind_mn = 0 ; 
		if(i > b || j < a) return null ;
		if(a <= i && b >= j) return tree[no] ; 
		return join(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;  
	}

} seg ; 

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> mn[i] ; 
		mx[i] = mn[i] ; 
	}

	mn[0] = inf ;

	seg.build(1, 1, n) ; 

	for(int i = 1 ; i <= m ; i++){
		
		int t, a, b ; 
		cin >> t >> a >> b ; 
		
		if(t == 1){
			mn[b] = min(mn[b], a) ; mx[b] = max(mx[b], a) ; 
			seg.upd(1, 1, n, b) ;
		}
		
		else{
			
			int menor = seg.query(1, 1, n, a, b).ind_mn, maior = seg.query(1, 1, n, a, b).ind_mx ; 
			
			if(maior != menor){
				cout << mx[maior] - mn[menor] << "\n" ; 
			}
			
			else{
				int menor2 = min(mn[seg.query(1, 1, n, a, maior - 1).ind_mn], mn[seg.query(1, 1, n, maior + 1, b).ind_mn]) ; 
				int maior2 = max(mx[seg.query(1, 1, n, a, menor - 1).ind_mx], mx[seg.query(1, 1, n, menor + 1, b).ind_mx]) ;
				cout << max(mx[maior] - menor2, maior2 - mn[menor]) << "\n" ; 
			}

		}

	}

}
