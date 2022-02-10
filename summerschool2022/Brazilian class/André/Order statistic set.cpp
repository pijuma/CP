#include<bits/stdc++.h>
#define meio ((i+j)>>1)
#define int long long 
using namespace std ; 

int q, v ; 
char c ; 

const int inf = 1e9 + 1 ; 
const int lim = inf + inf ; 

vector<int> e, d, sum, at ; 

struct SEG{

	int create(){
		e.push_back(0), d.push_back(0) ; sum.push_back(0) ; at.push_back(0) ;
		return max(0LL, (int)sum.size() - 1LL) ; 
	}

	void upd(int no, int i, int j, int pos, int v){
 
		if(i == j){
			sum[no] = v ; 
			return ; 
		}

		if(pos <= meio){
			if(!e[no]){
				int aux = create() ; 
				e[no] = aux ; 
			}
			upd(e[no], i, meio, pos, v) ; 
		}

		else{
			if(!d[no]){
				int aux = create() ; 
				d[no] = aux ; 
			}
			upd(d[no], meio + 1, j, pos, v) ; 
		} 

		sum[no] = sum[e[no]] + sum[d[no]] ; 

	}

	int query_k(int no, int i, int j, int k){
		
		if(i == j) return i ;

		if(sum[e[no]] >= k) return query_k(e[no], i, meio, k) ; 
		else return query_k(d[no], meio + 1, j, k - sum[e[no]]) ; 

	}

	int query(int no, int i, int j, int a, int b){

		if(i > j) return 0 ; 
		if(i > b || j < a) return 0 ; 

		if(a <= i && b >= j) return sum[no] ; 

		int val_esq = 0, val_dir = 0 ; 

		if(e[no]) val_esq =  query(e[no], i, meio, a, b) ;
		if(d[no]) val_dir = query(d[no], meio + 1, j, a, b) ;
		return val_dir + val_esq ; 

	}


} Seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> q ; 

	Seg.create() ; Seg.create() ; 

	while(q--){

		cin >> c >> v ; 

		if(c == 'I') Seg.upd(1, 1, lim, v+inf, 1) ; 
		else if(c == 'D') Seg.upd(1, 1, lim, v+inf, 0) ; 
		else if(c == 'K'){
			if(sum[1] < v) cout << "invalid\n" ; 
			else cout << Seg.query_k(1, 1, lim, v) - inf << "\n" ; 
		} 
		else cout << Seg.query(1, 1, lim, 1, v-1+inf) << "\n" ;  

		// cout << sum[1] << "\n" ; 

	}

}
