#include<bits/stdc++.h>
#define meio ((i+j)>>1)
#define int long long 
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, q, l[maxn], r[maxn], a, mxx, b ; 
vector<int> mx, e, d, lazy ; 

struct SEG{

	int create(){
		mx.push_back(0) ; 
		e.push_back(0) ; 
		d.push_back(0) ; 
		lazy.push_back(0) ;
		return mx.size() - 1 ; 
	}

	void flush(int no, int i, int j){
		mx[no] += lazy[no] ; 
		if(i != j){
			if(e[no] == 0){
				int aux = create() ; 
				e[no] = aux ;
			}
			if(d[no] == 0){
				int aux = create() ; 
				d[no] = aux ;
			}
			// cout << e[no] << " " << d[no] << "\n" ; 
			lazy[e[no]] += lazy[no] ; lazy[d[no]] += lazy[no] ; 
		}
		lazy[no] = 0 ; 
	}

	void upd(int no, int i, int j, int a, int b, int v){
		if(i > j || !no) return ; 
		if(lazy[no]) flush(no, i, j) ; 
		if(i > b || j < a) return ; 

		if(a <= i && b >= j){
			lazy[no]++ ; 
			flush(no, i, j) ;
			return ; 
		}

		if(e[no] == 0){
		    int aux = create() ; e[no] = aux ;  
		}
		if(d[no] == 0){
			int aux = create() ; d[no] = aux ;  
		} 

		upd(e[no], i, meio, a, b, v), upd(d[no], meio + 1, j, a, b, v) ; 

		mx[no] = max(mx[e[no]], mx[d[no]]) ; 
	
	}

	int query(int no, int i, int j, int a, int b){
		if(i > j || !no) return 0 ; 
		if(lazy[no]) flush(no, i, j) ; 
		if(i > b || j < a) return 0 ; 
		if(a <= i && b >= j) return mx[no] ; 
		int aa = 0, bb = 0 ; 
		if(e[no]) aa = query(e[no], i, meio, a, b) ;
		if(d[no]) bb = query(d[no], meio + 1, j, a, b) ;
		return max(aa, bb) ; 
	}

} Seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
	cin >> n ; 

	Seg.create() ; Seg.create() ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> l[i] >> r[i] ; 
		if(l[i] > r[i]) swap(l[i], r[i]) ; 
		mxx = max(mxx, r[i]) ;
	} 

	for(int i = 1 ; i <= n ; i++) Seg.upd(1, 1, mxx, l[i], r[i], 1) ; 

	cin >> q ;  

	while(q--){
		cin >> a >> b ; 
		cout << Seg.query(1, 1, mxx, a, b) << "\n" ; 
	}

}
