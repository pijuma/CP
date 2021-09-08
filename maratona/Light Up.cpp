#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 14 ; 

int dx[4] = {0, 0, 1, -1} ; 
int dy[4] = {1, -1, 0, 0} ; 

int n, m, b, g[maxn][maxn], light[maxn][maxn], resp, ct, redor[maxn][maxn], x[55] ;

int ok(int i, int j) {

  int k = g[i-1][j-1] ;

  if (k > 0) {
    if (x[k] == -1) return 1 ;
    return redor[i-1][j-1] == x[k] ;
  }
  
  return 1 ;

}

void reset() {
  resp = 0x3f3f3f3f ;
  memset(g, 0, sizeof(g));
  memset(light, 0, sizeof(light)) ;
  for (int i = 0; i <= n+1; i++) g[i][0] = g[i][m+1] = -1;
  for (int j = 0; j <= m+1; j++) g[0][j] = g[n+1][j] = -1;
}

void change(int i, int j, int t){
	    for(int k = j-1 ; k >= 1 && !g[i][k] ; k--) light[i][k] += t ; 
		for(int k = j + 1 ; k <= m  && !g[i][k] ; k++)  light[i][k] += t ; 
		for(int k = i - 1 ; k > 0 && !g[k][j] ; k--) light[k][j] += t ; 
		for(int k = i + 1 ; k <= n && !g[k][j] ; k++)  light[k][j] += t ; 
		for(int k = 0 ; k < 4 ; k++)  redor[i+dx[k]][j+dy[k]] += t ;
}

void fill(int i, int j){

	if(j > m + 1){
		fill(i+1, 0) ; // faz prox linha da coluna inicial  
		return ; 
	}

	if(i > n+1){ // terminei td preciso checar 
		for(int k = 1 ; k <= n ; k++){
			for(int l = 1 ; l <= m ; l++){
				if(!light[k][l] && !g[k][l]) return ; // tem algm n ligado 
			}
		}
		resp = min(resp, ct) ;
		return ;
	}

	// colocar na pos i, j 
	if(!ok(i, j)) return ; 

	if(g[i][j] || !(!light[i][j] && g[i][j+1]) || !(!light[i][j] && g[i+1][j])) fill(i, j+1) ; // n colocar 

	if(!g[i][j] && !light[i][j]){
		ct++ ; 
		change(i, j, 1) ; 
		light[i][j]++ ;
		fill(i, j+1) ; 
	    change(i, j, -1) ;
		ct-- ;  
		light[i][j]-- ;
	}

}

int main() {
  
  while (~scanf("%d%d", &n, &m) and n and m) {
    
    reset() ;

    scanf("%d", &b) ;

    for (int i = 1; i <= b; i++){
      int r, c ;  
      scanf("%d%d%d", &r, &c, &x[i]) ;
      g[r][c] = i ;
    }

    fill(0, 0) ;

    if (resp == 0x3f3f3f3f) printf("No solution\n") ;
    else printf("%d\n", resp) ;
    
  }
  
}
