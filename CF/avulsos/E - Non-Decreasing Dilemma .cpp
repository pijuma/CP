#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

// mantem seg 
// flag se eh td crescente 
// maior crescente no pref no suf e no geral 


const int maxn = 2e5 + 5 ; 

int n, q, ans, v[maxn] ;

struct T{
	int mx_pref, mx_suf, first, last, num ; // maior pref, "", 1o el., ultimo el., subseqs fora do pref/suf
	bool flag ;  // é td n decr.? 
} ; 

T tree[4*maxn] ; 

struct SEG{

	int calc(int a){ return (a*(a+1))/2 ; }

	T join(T a, T b){

		T c ; 

		if(a.first == -1) return b ; 
		if(b.first == -1) return a ; 

		c.first = a.first, c.last = b.last ; 

		if(a.last <= b.first){ // pode mesclar 
			c.flag = (a.flag&b.flag) ; 
			c.mx_suf = b.mx_suf ; 
			if(b.flag) c.mx_suf += a.mx_suf ; 
			c.mx_pref = a.mx_pref ; 
			if(a.flag) c.mx_pref += b.mx_pref ;
			if(a.flag && b.flag) c.num = 0 ; 
			else if(!a.flag && !b.flag) c.num = a.num + b.num + calc(a.mx_suf + b.mx_pref) ; // pego oq tinha em cada + mesclando
			else if(!a.flag && b.flag) c.num = a.num ; 
			else c.num = b.num ;   
		}

		else{
			c.flag = 0 ; 
			c.mx_suf = b.mx_suf, c.mx_pref = a.mx_pref ;
			if(a.flag && b.flag) c.num = 0 ; 
			else if(!a.flag && !b.flag) c.num = a.num + b.num + calc(a.mx_suf) + calc(b.mx_pref) ; // pego oq tinha em cada + mesclando
			else if(!a.flag && b.flag) c.num = a.num + calc(a.mx_suf); 
			else c.num = b.num + calc(b.mx_pref) ;   
		}

		return c ; 

	}

	void build(int no, int i, int j){
		if(i == j){
			tree[no].last = tree[no].first = v[i] ; 
			tree[no].mx_pref = tree[no].mx_suf = 1 ; 
			tree[no].flag = 1 ; 
			return ;
		}
		build(esq, i, meio), build(dir, meio + 1, j) ; 
		tree[no] = join(tree[esq], tree[dir]) ; 
	}

	void upd(int no, int i, int j, int pos, int val){

		if(i == j){
			v[pos] = val ; 
			tree[no].last = tree[no].first = v[i] ; 
			tree[no].mx_pref = tree[no].mx_suf = 1 ; 
			return ; 
		}
		
		if(pos <= meio) upd(esq, i, meio, pos, val) ; 
		else upd(dir, meio + 1, j, pos, val) ; 

		tree[no] = join(tree[esq], tree[dir]) ; 
	}

	T query(int no, int i, int j, int a, int b){

	    T null ; 
	    null.first = -1 ; 	
		if(i > b || j < a) return null ; 
		if(a <= i && b >= j) return tree[no] ;

		return join(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ; 

	}

} seg ; 

int32_t main(){

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

	seg.build(1, 1, n) ;

	for(int i = 1 ; i <= q ; i++){
		int tipo, x, y ; 
		cin >> tipo >> x >> y ;
		T c = seg.query(1, 1, n, x, y) ; 
		if(tipo == 1) seg.upd(1, 1, n, x, y) ; 
		else if(c.flag) cout << seg.calc(y - x + 1) << "\n" ; 
		else{
			cout << seg.calc(c.mx_pref) + seg.calc(c.mx_suf) + c.num << "\n" ;
		}
	}

}
