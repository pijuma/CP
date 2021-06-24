#include<bits/stdc++.h>
#define int long long
#define ll long long 

#define esq (2*no)
#define meio ((i+j)>>1)
#define dir ((2*no)+1)

using namespace std ; 

const int maxn = 1e5 + 5 ; 
const ll inf = (1LL<<31) ; 

// xor -> se der zero o xor geral pega o max no segmento 
// and -> retorna o menor se and total for igual a ele 
// or -> se existir eh o maior qd o maior eh igual ao or  

struct Tree{
	ll mx, mn, andd, xr, orr, indmin, indmx ; 
} ;

ll n, q, v[maxn], l, r, pos, val ;  
char type ;   
Tree tree[(1<<18)] ; 

struct SEG{

	Tree join(Tree a, Tree b){
		Tree ans ; 
		if(a.mx >= b.mx) ans.mx = a.mx, ans.indmx = a.indmx ; 
		else ans.mx = b.mx, ans.indmx = b.indmx ; 
		if(a.mn <= b.mn) ans.mn = a.mn, ans.indmin = a.indmin ;
		else ans.mn = b.mn, ans.indmin = b.indmin ;
		ans.andd = (a.andd&b.andd), ans.xr = (a.xr^b.xr), ans.orr = (a.orr|b.orr) ; 
		return ans ;  
	}

	void build(int no, int i, int j){
		
		if(i == j){
			tree[no] = {v[i], v[i], v[i], v[i], v[i], i, i} ;
			return ;  
		}

		build(esq, i, meio), build(dir, meio + 1, j) ; 

		tree[no] = join(tree[esq], tree[dir]) ; 

	}

	void att(int no, int i, int j, int pos, ll va){
		
		if(i == j){
			tree[no] = {va, va, va, va, va, i, i} ; 
			return ; 
		}

		if(pos <= meio) att(esq, i, meio, pos, va) ; 
		else att(dir, meio + 1, j, pos, va) ; 

		tree[no] = join(tree[esq], tree[dir]) ; 

	}

	Tree query(int no, int i, int j, int a, int b){
		
		Tree null ; 
		null.mx = -1, null.mn = inf, null.andd = inf-1, null.xr = 0LL, null.orr = 0LL, null.indmin = 0, null.indmx = 0 ; 
		
		if(a > j || b < i || a > b) return null ; 
		
		if(a <= i && b >= j) return tree[no] ; 

		Tree p, l ; 
		p = query(esq, i, meio, a, b), l = query(dir, meio + 1, j, a, b) ; 
		
		return join(l, p) ; 

	}

} seg ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	cin >> n >> q ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	seg.build(1, 1, n) ;
    
    while(q--){
    	
    	cin >> type >> l >> r ; 
    	
    	if(type == 'a') {
    		Tree f, e, d ; 
    		f = seg.query(1, 1, n, l, r) ; 
    		e = seg.query(1, 1, n, l, f.indmin-1), d = seg.query(1, 1, n, f.indmin+1, r) ; 
    		// cout << e.andd << " " << d.andd << "\n" ; 
    		if(f.mn == (d.andd&e.andd)) cout << f.mn << "\n" ; 
    		else cout << "-1\n" ; 
    	} 
    	
    	else if(type == 'x') {
    		Tree f, e, d ;
    		seg.query(1, 1, n, l, r) ;
    		f = seg.query(1, 1, n, l, r) ; 
    		e = seg.query(1, 1, n, l, f.indmx-1), d = seg.query(1, 1, n, f.indmx+1, r) ; 
    		// cout << f.indmx << " " << e.orr << " " << d.orr  << " " << (e.orr|d.orr) << "\n" ; 
    		if(f.mx == (d.xr^e.xr)) cout << f.mx << "\n" ; 
    		else cout << "-1\n"  ; 
    	}

    	else if(type == 'o'){
    		Tree f, e, d ;
    		seg.query(1, 1, n, l, r) ;
    		f = seg.query(1, 1, n, l, r) ; 
    		e = seg.query(1, 1, n, l, f.indmx-1), d = seg.query(1, 1, n, f.indmx+1, r) ; 
    		// cout << f.indmx << " " << e.orr << " " << d.orr  << " " << (e.orr|d.orr) << "\n" ; 
    		if(f.mx == (d.orr|e.orr)) cout << f.mx << "\n" ; 
    		else cout << "-1\n"  ; 
    	}
    
    	else seg.att(1, 1, n, l, r) ; 

    }
}
