#include<bits/stdc++.h>

#define esq (2*nox)
#define dir ((2*nox)+1)
#define meio ((ix+jx)>>1)

#define ESQ (2*noy) 
#define DIR ((2*noy)+1)
#define MEIO ((iy + jy)>>1)

using namespace std ; 

const int maxm = 252 ; 
const int maxn = 1e3 + 3 ; 

bitset<maxm> bs[maxn][maxn], mark[maxn][maxn], tree[3*maxn][3*maxn] ; 

int li, lj, ri, rj ; 
int n, k, m, g[maxn][maxn], pi, pj, q ; 

int dx[4] = {0, 0, -1, 1} ; 
int dy[4] = {1, -1, 0, 0} ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

void bfs(int i, int j, int id){

	bs[i][j][id] = 1 ;
	mark[i][j][id] = 1 ;  

	queue<pair<int,int>> fila ;
	fila.push({i, j}) ; 

	while(!fila.empty()){
		
		int ti = fila.front().first, tj = fila.front().second ; 
		fila.pop() ;

		for(int i = 0 ; i < 4 ; i++){

			int ki = ti + dx[i], kj = tj + dy[i] ; 
			
			if(g[ki][kj] < g[ti][tj] || !valid(ki, kj) || mark[ki][kj][id]) continue ; // ja q agua desce p coletor faz subindo
			
			mark[ki][kj][id] = 1 ; 
			bs[ki][kj][id] = 1 ; 
			
			fila.push({ki, kj}) ; 

		}

	} 

}

struct SEG{

	void build_y(int nox, int ix, int jx, int noy, int iy, int jy){

		if(iy == jy){
			
			if(ix == jx) tree[nox][noy] = bs[ix][iy] ; 
			else tree[nox][noy] = tree[esq][noy] | tree[dir][noy] ; // ja ta feito p x ent da combine 
			
			return ; 

		}

		build_y(nox, ix, jx, ESQ, iy, MEIO), build_y(nox, ix, jx, DIR, MEIO + 1, jy) ; 

		tree[nox][noy] = tree[nox][ESQ]|tree[nox][DIR] ; 

	}

	void build_x(int nox, int ix, int jx){
		
		if(ix != jx){
			build_x(esq, ix, meio), build_x(dir, meio + 1, jx) ; 
		}

		build_y(nox, ix, jx, 1, 1, m) ; // passa p buildar com nosso nó e intervalo de x 
		// e o nó e intervalo de y 

	} 

	bitset<maxm> query_y(int nox, int noy, int iy, int jy, int a, int b){

		if(a > jy || b < iy) return 0 ; 
		if(a <= iy && b >= jy) return tree[nox][noy] ; 

		return query_y(nox, ESQ, iy, MEIO, a, b)|query_y(nox, DIR, MEIO + 1, jy, a, b) ; 
	
	}

	bitset<maxm> query_x(int nox, int ix, int jx, int ax, int bx, int ay, int by){

		if(bx < ix || ax > jx) return 0 ; 
		if(ax <= ix && bx >= jx) return query_y(nox, 1, 1, m, ay, by) ; 

		return query_x(esq, ix, meio, ax, bx, ay, by)|query_x(dir, meio + 1, jx, ax, bx, ay, by) ; 

	}

} seg ;

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> n >> m >> k ; 

    for(int i = 1 ; i <= n ; i++){
    	for(int j = 1 ; j <= m ; j++){
    		cin >> g[i][j] ; //lê grid das alts
    	}
    }  

    for(int i = 1 ; i <= k ; i++){
    	
    	cin >> pi >> pj ; 
    	
    	// fazemos uma bfs p cada coletor p marcar em quais pos ele chega
    	// fazemos 0 index p usar bitset
    	
    	bfs(pi, pj, i-1) ; 

    }

    seg.build_x(1, 1, n) ; // fzr a seg 2d 

    cin >> q ; 

    for(int i = 1 ; i <= q ; i++){
    	
    	cin >> li >> lj >> ri >> rj ; 

    	cout << (seg.query_x(1, 1, n, li, ri, lj, rj)).count() << "\n" ; 
    }

}
