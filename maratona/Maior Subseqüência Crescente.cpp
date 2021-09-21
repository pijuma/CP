#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 610 ; 

int n, m, g[maxn][maxn], preta[maxn][maxn], vermei[maxn][maxn] ; 
int matriz[maxn][maxn], esq[maxn][maxn], dir[maxn][maxn] ;
int e[maxn], d[maxn], h[maxn] ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

	while(true){
		
		cin >> n >> m ; 
		if(!n && !m) return 0 ; 
		for(int i = 0 ; i <= n + 1 ; i++){
			for(int j = 0 ; j <= m + 1 ; j++){
				preta[i][j] = vermei[i][j] = matriz[i][j] = 0 ; 
				h[i] = e[i] = d[i] = esq[i][j] = dir[i][j] = 0 ; 
				g[i][j] = matriz[i][j] = 0 ; 
			}
		}
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> g[i][j] ; 
			}
		}

		for(int i = 1 ; i <= n ; i++){
			for(int j = m ; j > 0 ; j--){ 
				if(g[i][j] < g[i][j+1]) preta[i][j] = preta[i][j+1] + 1 ; 
				else preta[i][j] = 1 ; 
			}
		}

		for(int j = 1 ; j <= m ; j++) vermei[n][j] = preta[n][j] ; 

		for(int i = 1 ; i < n ; i++){ 
			for(int j = 1 ; j <= m ; j++){
				int x = g[i+1][j] ; 
				int ini = j, fim = j + preta[i][j] - 1, mid, best = 0 ; 
				while(ini <= fim){
					mid = (ini + fim)>>1 ; 
					if(g[i][mid] < x) best = mid, ini = mid + 1 ; 
					else fim = mid - 1 ; 
				}
				if(best == 0) vermei[i][j] = 0 ; 
				else vermei[i][j] = best - j + 1 ;
			}
		}

		// tem q pegar fixando a ultima e 1a linha alone
		for(int i = 1 ; i < n ; i++){
			for(int j = 1 ; j <= m ; j++){
				matriz[i][j] = min(vermei[i][j], preta[i+1][j]) ; 
			}
		}

		int ans = 0 ; 

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++) ans = max(ans, preta[i][j]) ;
		}
		 
		for(int j = 1 ; j <= m ; j++) ans = max(ans, preta[n][j]) ; 

		for(int j = 1 ; j <= m ; j++){
			for(int i = 1 ; i <= n ; i++) h[i] = matriz[i][j] ; 
			h[0] = -1, h[n+1] = -1 ; 
		    for(int i = 1 ; i <= n ; i++){
		    	e[i] = i-1 ; 
		    	while(h[e[i]] >= h[i]) e[i] = e[e[i]] ; 
		    }
		    for(int i = n ; i > 0 ; i--){
		    	d[i] = i+1 ; 
		    	while(h[d[i]] >= h[i]) d[i] = d[d[i]] ; 
		    }
			for(int i = 1 ; i <= n ; i++) esq[i][j] = e[i], dir[i][j] = d[i] ; 
		}

	    for(int j = 1 ; j <= m ; j++){
	    	for(int i = 1 ; i < n ; i++){
	    		int base = (dir[i][j] - esq[i][j]) ; 
	    		ans = max(ans, base*matriz[i][j]) ; 
	    	}
	    }

	    cout << ans << "\n" ; 

	}

}
