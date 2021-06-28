#include<bits/stdc++.h>

#define ll long long 
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ; 

const int maxn = 1e5 + 3 ; 
const int maxval = 1e6 + 1 ; 
const int maxx = 3e6 + 2 ; 

struct evento{
	int xi, xf, y, tipo ; 
} ; 

struct node{
	int mn, qtd ; 
} ; 

int n, X, x2, Y, y2 ;  
vector<int> val ; 
vector<evento> ev ;
int lazy[4*maxx] ; 
node tree[4*maxx] ; 

evento make(int ini, int fim, int h, int t){
	evento a ; 
	a.xi = ini, a.xf = fim, a.y = h, a.tipo = t ; 
	return a ;  
}

bool cmp(evento a, evento b){
	if(a.y != b.y) return a.y < b.y ; 
	return a.tipo > b.tipo ; 
}

struct SEG{

	node combine(node a, node b){
	
	   node resp ; 

	   if(a.mn < b.mn) resp.mn = a.mn, resp.qtd = a.qtd ;
	   else if(a.mn == b.mn) resp.mn = a.mn, resp.qtd = a.qtd + b.qtd ; 
	   else resp.mn = b.mn, resp.qtd = b.qtd ; 

	   return resp ; 

    }


	void flush(int no, int i, int j){
	
		if(!lazy[no]) return ; 
		tree[no].mn += lazy[no] ; 
	
		if(i != j){
			lazy[esq] += lazy[no] ; 
			lazy[dir] += lazy[no] ; 
		} 

		lazy[no] = 0 ; 
	
	}

	void build(int no, int i, int j){
		
		lazy[no] = 0 ; 

		if(i == j){
			tree[no].qtd = 1, tree[no].mn = 0 ; 
			return ; 
		}

		build(esq, i, meio), build(dir, meio + 1, j) ; 

		tree[no] = combine(tree[esq], tree[dir]) ; 

	}

	int query(int no, int i, int j){
		flush(no, i, j) ; 
		int qtd = tree[1].qtd, mnn = tree[1].mn ; 
		if(mnn == 0) return  (j-i+1) - qtd ; 
		else return (j-i+1) ;
	}

	void att(int no, int i, int j, int a, int b, int x){
		
		flush(no, i, j) ; 

		if(a > j || b < i) return ; 
		
		if(a <= i && b >= j){
			lazy[no] += x ; 
			flush(no, i, j) ; 
			return ;  
		}

		att(esq, i, meio, a, b, x), att(dir, meio + 1, j, a, b, x) ; 

		tree[no] = combine(tree[esq], tree[dir]) ; 

	}

	void see(){

		for(int i = 1 ; i <= maxx ; i++){
			if(tree[i].mn < 0) cout << i << " " << tree[i].qtd << " " << tree[i].mn << "\n" ;   
		}

	}

} seg ;

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> X >> Y >> x2 >> y2 ; 
		int xi = min(X, x2) + maxval, xf = max(X, x2) + maxval ; 
		int yi = min(Y, y2) + maxval, yf = max(Y, y2) + maxval ; 
		ev.push_back(make(xi, xf, yi, 1)), ev.push_back(make(xi, xf, yf, -1)) ;
	} 

	sort(ev.begin(), ev.end(), cmp) ; 

	seg.build(1, 1, maxx) ; 

	ll ans = 0, yi = 0 ; 

	for(int i = 0 ; i < (int) ev.size() ; i++){ 
		int s = seg.query(1, 1, maxx) ; 
		int aux = 1LL*s*(ev[i].y - yi) ;
		// cout << tree[1].mn << "\n" ; 
		seg.att(1, 1, maxx, ev[i].xi, ev[i].xf - 1, ev[i].tipo) ;
		ans += aux ; 
		yi = ev[i].y ; 
	}

	cout << ans << "\n" ; 

}
