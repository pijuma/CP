#include<bits/stdc++.h>
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
using namespace std ; 

const int maxn = 3e4 + 5 ; 

int n, q, v[maxn] ; 
vector<int> tree[4*maxn] ; 
// merge sort tree

struct SEG{

	vector<int> merge(vector<int> &e, vector<int> &d){
		
		int ptr = 0, ptl = 0, tame = e.size(), tamd = d.size() ; 
		vector<int> v(tame + tamd) ; 
		
		for(int i = 0 ; i < tame + tamd ; i++){
			if(ptr >= tamd){
				v[i] = e[ptl] ; ptl++ ; 
			}
			else if(ptl >= tame){
				v[i] = d[ptr], ptr++ ; 
			}
			else{
				if(e[ptl] <= d[ptr]){ v[i] = e[ptl] ; ptl++ ;} 
				else{ v[i] = d[ptr] ; ptr++ ; }
			}
		}
		
		return v ; 

	}

	void build(int no, int i, int j){
		if(i == j){
			tree[no].push_back(0) ; tree[no].push_back(v[i]) ; 
			return ; 
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = merge(tree[esq], tree[dir]) ; 
	} 

	int bb(vector<int> &v, int k){
		
		int ini = 0, fim = v.size() - 1, best = v.size(), mid ; 
		
		while(ini <= fim){
			mid = (ini+fim)>>1 ; 
			if(v[mid] > k) best = mid, fim = mid - 1 ; 
			else ini = mid + 1 ; 
		}

		return v.size() - best ; 

	}

	int query(int no, int i, int j, int a, int b, int k){
		if(i > b || j < a) return 0 ; 
		if(tree[no][tree[no].size()-1] < k) return 0 ;
		if(tree[no].size() > 1 && tree[no][1] > k) return tree[no].size() - 1 ; 
		if(a <= i && b >= j) return bb(tree[no], k) ; 
		return query(esq, i, meio, a, b, k) + query(dir, meio + 1, j, a, b, k) ; 
	}

} Seg ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	Seg.build(1, 1, n) ; 

	cin >> q ; 
    
    for(int i = 1 ; i <= q ; i++){
    	int a, b, k ; 
    	cin >> a >> b >> k ; 
    	cout << Seg.query(1, 1, n, a, b, k) << "\n" ; 
    }

}
