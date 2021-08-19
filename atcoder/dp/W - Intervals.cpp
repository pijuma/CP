#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

// dpi maior pontuação c o bit i aceso 
// dpi = max(dpj + c(i, j))

// seg de max 
// chega num l upd de 1 a l p +v 
// passa por tds os r's <= l e 
// seta -v de 1 ao l - 1 do intervalo do r 

const int maxn = 2e5 + 5 ; 
const int inf = 1e18 ;

int n, m, add[maxn], lazy[4*maxn], tree[4*maxn] ; 
vector<pair<int,int>> fim[maxn] ; 

struct SEG{

	void flush(int no, int i, int j){
		if(!lazy[no]) return ; 
		tree[no] += lazy[no] ; 

		if(i != j){
			lazy[esq] += lazy[no] ; lazy[dir] += lazy[no] ; 
		}

		lazy[no] = 0 ; 

	}

	void update(int no, int i, int j, int a, int b, int v){
		
		flush(no, i, j) ; 
		
		if(i > b || j < a) return ; 
		if(a <= i && b >= j){
			lazy[no] += v ; 
			flush(no, i, j) ; 
			return ; 
		}

		update(esq, i, meio, a, b, v), update(dir, meio + 1, j, a, b, v) ; 

		tree[no] = max(tree[esq], tree[dir]) ; 

	}

	int query(int no, int i, int j, int a, int b){

		flush(no, i, j) ; 

		if(i > b || j < a) return -inf ; 

		if(a <= i && b >= j) return tree[no] ; 

		return max(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ; 

	}

} seg ; 

int32_t main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= m ; i++){
		int l, r, v ; 
		cin >> l >> r >> v ; 
		add[l] += v ; 
		fim[r + 1].push_back({l, v}) ; 
	}

	for(int i = 1 ; i <= n + 1 ; i++){
		
		seg.update(1, 0, n, 0, i - 1, add[i]) ; 

		for(auto a : fim[i]){ // retirar tds q terminam em i -> n são mais contados 
			seg.update(1, 0, n, 0, a.first - 1, -a.second) ; 
		}

		seg.update(1, 0, n, i, i, seg.query(1, 0, n, 0, i-1)) ; // atualizo a dp com o maior valor 

	}

	cout << seg.query(1, 0, n, 0, n) << "\n" ; 

}
