#include<bits/stdc++.h>
#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)
#define int long long 
using namespace std ; 


const int maxn = 3e4 + 5 ; 
const int MAX = 1e6 + 5 ; 

int n, mx, v[maxn], q, a, b, last_my[MAX] ; 
vector<int> root, e, d, sum ; 

struct SEG{

	int create(){
		sum.push_back(0) ; e.push_back(0) ; d.push_back(0) ; 
		return max(0LL, (long long)sum.size() - 1) ; 
	}

	int upd(int no, int i, int j, int pos, int v){

		int neww = create() ; 
		e[neww] = e[no] ; d[neww] = d[no] ; sum[neww] = sum[no] ; 

		if(i == j){
			sum[neww] += v ; 
			return neww ; 
		}

		if(pos <= meio){
			int aux = upd(e[neww], i, meio, pos, v) ; 
			e[neww] = aux ; 
		}

		else{
			int aux = upd(d[neww], meio + 1, j, pos, v) ; 
			d[neww] = aux ; 
		}

		sum[neww] = sum[e[neww]] + sum[d[neww]] ; 

		return neww ; 

	}

	int query(int no, int i, int j, int a, int b){
		// cout << i << " " << j << "\n" ; 
		if(i > j || b < i || a > j) return 0 ; 
		if(a <= i && b >= j) return sum[no] ; 
		int esqq = 0, dirr = 0 ; 
		if(e[no]) esqq = query(e[no], i, meio, a, b) ; 
		if(d[no]) dirr = query(d[no], meio + 1, j, a, b) ;
		return esqq + dirr ;
	}

} Seg ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	root.push_back(Seg.create()) ; 

	for(int i = 1 ; i <= n ; i++){
		int ant = root.back() ; 
		root.push_back(Seg.create()) ; 
		root.back() = Seg.upd(ant, 1, n, i, 1) ;
		if(last_my[v[i]]){
			int last = root.back() ; 
			root.back() = Seg.upd(last, 1, n, last_my[v[i]], -1) ; 
		}
		// cout << sum[root.back()] << "\n" ; 
		last_my[v[i]] = i ; 
	}

	cin >> q ; 

	while(q--){

		cin >> a >> b ; 

		cout << Seg.query(root[b], 1, n, a, b) << "\n" ; 

	}

}
