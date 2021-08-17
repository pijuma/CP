#include<bits/stdc++.h>

#define ll long long 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 15 ;

// uma seq é candidata se o mdc dela é maior q 1 
// podemos alterar o valor de S 
// consultar o n° de seq candidatas num intervalo, qts seqs mdc > 1 
// seg padrão q o nó guarda
// um map<mdc, freq> um pro pref e outro p suf  
// qtd de seqs com mdc = 1 
// mdc geral 
// qtd de subseqs vai de 1 a (b - a + 1) com r = 1 
// fazendo sn temos que são (b - a + 2)*(b - a + 1)/2 

struct node{

	ll qtd1 ; 
	int mdc ; 
	map<int, ll> pref, suf ; 

	node(){ mdc = 0, qtd1 = 0 ; }

	node(int x){

		mdc = x ; 
		pref[x] = suf[x] = 1 ; 
		qtd1 = (x == 1) ;

	}

} ; 

int v[maxn] ;
node tree[4*maxn] ; 

int gdc(int a, int b){ return (!b ? a : gdc(b, a%b)) ; }

struct SEG{

	node join(node &a, node &b){
		
		node c ; 

		if(a.mdc == 0) return b ; 
		if(b.mdc == 0) return a ; 

		c.qtd1 = a.qtd1 + b.qtd1 ; 
		c.mdc = gdc(a.mdc, b.mdc) ; // combina direto 
		
		// pref é pref de a + pref de b e suf é suf de b + suf a 
		// preciso contar qts 1's são criados qd junto suf a com pref de b 

		c.pref = a.pref, c.suf = b.suf ; 
		
		for(auto k : a.suf){
			int newmdc = gdc(k.first, b.mdc) ; 
			c.suf[newmdc] += k.second ; 
		}

		for(auto k : b.pref){
			int newmdc = gdc(k.first, a.mdc) ; 
			c.pref[newmdc] += k.second ; 
		}

		for(auto k : a.suf){
			
			for(auto g : b.pref){

				int val = gdc(k.first, g.first) ; 
				if(val == 1) c.qtd1 += 1LL*k.second*g.second ; 
		
			}

		}

		return c ; 

	}

	void build(int no, int i, int j){

		if(i == j){
			tree[no] = node(v[i]) ; 
			return ; 
 		}

 		build(esq, i, meio), build(dir, meio + 1, j) ; 

 		tree[no] = join(tree[esq], tree[dir]) ; 

	}

	void upd(int no, int i, int j, int pos, int val){

		if(i == j){
			tree[no] = node(val) ; 
			return ; 
		}

		if(pos <= meio) upd(esq, i, meio, pos, val) ; 
		else upd(dir, meio + 1, j, pos, val) ; 

		tree[no] = join(tree[esq], tree[dir]) ; 

	}

	node query(int no, int i, int j, int a, int b){

		if(i > b or j < a) return node() ; 

		if(i >= a and j <= b) return tree[no] ; 
 
		node f = query(esq, i, meio, a, b), g = query(dir, meio + 1, j, a, b) ;
		return join(f, g) ; 

	}

} seg ; 

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;

	int n, m ; 

	scanf("%d%d", &n, &m) ; 

	for(int i = 1 ; i <= n ; i++) scanf("%d",&v[i]) ; 

	seg.build(1, 1, n) ; 

	for(int i = 1 ; i <= m ; i++){
		
		int t, a, b ; 
		scanf("%d%d%d", &t, &a, &b) ; 

		if(t == 1) seg.upd(1, 1, n, a, b) ; 
		else printf("%lld\n", ((b-a+1)*1LL*(b-a+2)>>1) - seg.query(1, 1, n, a, b).qtd1) ;

	}

}
