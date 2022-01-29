#include<bits/stdc++.h>

#define int long long 
#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)

using namespace std ; 

const int maxn = 3e4 + 5 ; 

int n, v[maxn], q, ant_ans ; 
vector<int> tree[4*maxn] ; 

struct SEG{

	vector<int> merge(vector<int> &e, vector<int> &d){
		
		int ptd = 0, pte = 0, tmd = d.size(), tme = e.size() ; 
		vector<int> v(tmd + tme) ; 
		
		for(int i = 0 ; i < tmd + tme ; i++){
			if(pte >= tme){
				v[i] = d[ptd] ; 
				ptd++ ; 
			}
			else if(ptd >= tmd){
				v[i] = e[pte] ; 
				pte++ ; 
			}
			else{
				if(e[pte] <= d[ptd]){
					v[i] = e[pte] ; pte++ ; 
				}
				else{
					v[i] = d[ptd] ; ptd++ ;
				}
			}
		}

		return v ; 

	}

	void build(int no, int i, int j){
		
		if(i == j){
			tree[no].push_back(0) ; 
			tree[no].push_back(v[i]) ; 
			return ; 
		}
		
		build(esq, i, meio), build(dir, meio + 1, j) ; 

		tree[no] = merge(tree[esq], tree[dir]) ; 

	}

	int bb(vector<int> &v, int x){
		
		int ini = 0, fim = v.size() - 1, mid, best = v.size() ; 

		while(ini <= fim){
			mid = (ini + fim)>>1 ;
			if(v[mid] > x){
				best = mid, fim = mid - 1 ; 
			} 
			else ini = mid + 1 ; 
		}

		return v.size() - best ; 

	}

	int query(int no, int i, int j, int a, int b, int v){

		if(i > b || j < a) return 0 ; 
		if(tree[no][tree[no].size()-1] < v) return 0 ;
		if(tree[no].size() > 1 && tree[no][1] >= v) return tree[no].size() - 1 ; 
		if(a <= i && b >= j) return bb(tree[no], v) ;  

		return query(esq, i, meio, a, b, v) + query(dir, meio + 1, j, a, b, v) ; 
	}

	void see(){
		for(int i = 1 ; i <= 2*n ; i++){
			// cout << tree[i].size() << "\n" ; 
			for(auto a : tree[i]) cout << a << " " ; 
			if(tree[i].size()) cout << "\n" ; 
		}
	}

} Seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	Seg.build(1, 1, n) ; 

    cin >> q ; 

    while(q--){
    	
    	int a, b, c ; 
    	cin >> a >> b >> c ; 

    	int i = a^ant_ans ; 
    	int j = b^ant_ans ; 
	    int k = c^ant_ans ;

	    ant_ans = Seg.query(1, 1, n, i, j, k) ; 

	    cout << ant_ans << "\n" ; 

    }

}
