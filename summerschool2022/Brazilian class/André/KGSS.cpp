#include<bits/stdc++.h>
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 
const int inf = 1e9 ; 

int n, v[maxn], q ; 

struct Node{
    int mx1, mx2 ; 	
};

Node tree[4*maxn] ; 

struct SEG{

	Node merge(Node a, Node b){
		Node ans ; 
		vector<int> maxs ; 
		maxs.push_back(a.mx1), maxs.push_back(a.mx2) ;
		maxs.push_back(b.mx1), maxs.push_back(b.mx2) ;
		sort(maxs.begin(), maxs.end()) ; reverse(maxs.begin(), maxs.end()) ;
		ans.mx1 = maxs[0] ;
		ans.mx2 = maxs[1] ;
		return ans ; 
	}

	void build(int no, int i, int j){
		if(i == j){
			tree[no].mx1 = v[i], tree[no].mx2 = -1 ;  
			return ;
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = merge(tree[esq], tree[dir]) ; 
	}

	void upd(int no, int i, int j, int a, int b){
		if(i == j){
			tree[no].mx1 = b, tree[no].mx2 = -1 ;
			return ;
		}
		if(a <= meio) upd(esq, i, meio, a, b) ; 
		else upd(dir, meio + 1, j, a, b) ; 
		tree[no] = merge(tree[esq], tree[dir]) ; 
	}

	Node query(int no, int i, int j, int a, int b){
		Node inv ; 
		inv.mx1 = inv.mx2 = -1 ; 
		if(a > j || b < i) return inv ; 
		if(a <= i && b >= j){
			return tree[no] ; 
		}
		
		return merge(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;

	}

} seg ; 

int query(int l, int r){
	Node x = seg.query(1, 1, n, l, r) ;
	return x.mx1 + x.mx2 ;  
}

int main(){

	cin >> n ; 
	
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	seg.build(1, 1, n) ; 

	cin >> q ; 
    
    while(q--){
    	
    	char t ; int a, b ; 
    	cin >> t >> a >> b ; 

    	if(t == 'Q') cout << query(a, b) << "\n" ; 
    	else seg.upd(1, 1, n, a, b) ; 

    }

}
