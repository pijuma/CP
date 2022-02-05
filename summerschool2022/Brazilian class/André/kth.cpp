// a versão representa o prefixo até i 
// a posicao na versao a freq do valor vi
// na query desce junto e faz bb nos valores enquanto desce p responder o otimo 

#include<bits/stdc++.h>
#define int long long 
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e6 + 5 ; 
const int inf = 1e9 + 1 ; 

int n, m, mx, v[maxn], ct ; 
vector<int> e, d, sum, root ;
map<int,int> mp ; 

struct SEG{

	int create(){
		sum.push_back(0) ; e.push_back(0) ; d.push_back(0) ; 
		return sum.size() - 1 ; 
	}

	int upd(int no, int i, int j, int pos, int v){

		int neww = create() ; 
		e[neww] = e[no] ; d[neww] = d[no] ; sum[neww] = sum[no] ; 

		if(i == j){
			sum[neww]++ ; 
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
		// cout << i << " " << j << " " << sum[neww] << "\n" ; 

		return neww ; 

	}

	int query(int no_fim, int no_ini, int i, int j, int k){

		// cout << i << " " << j << "\n" ; 
		// cout << sum[no_fim] << " " << sum[no_ini] << "\n" ; 

		if(i == j) return i ; 

		if(sum[e[no_fim]] - sum[e[no_ini]] >= k) return query(e[no_fim], e[no_ini], i, meio, k) ; 
		else return query(d[no_fim], d[no_ini], meio + 1, j, k - (sum[e[no_fim]] - sum[e[no_ini]])) ; 

	}

} Seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> m ; 

	root.push_back(Seg.create()) ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> v[i] ; 
		v[i] += inf ; 
		mx = max(mx, v[i]) ; 
	}

	for(int i = 1 ; i <= n ; i++){ 
		int ant = root.back() ; 
		root.push_back(Seg.create()) ; 
		root.back() = (Seg.upd(ant, 1, mx, v[i], 1)) ; // somo um na pos v na anterior
		// cout << root.back() << "\n" ;
		// cout << sum[root.back()] << "\n" ; 
	}

	for(int i = 1 ; i <= m ; i++){
		int a, b, k ; 
		cin >> a >> b >> k ; 
		// cout << root[v] << " " << root[u-1] << "\n" ; 
		cout << Seg.query(root[b], root[a-1], 1, mx, k) - inf << "\n" ; 
	}

}
