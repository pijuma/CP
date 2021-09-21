#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 505 ; 

int n, m, g[maxn][maxn] ;

int bb1(int x, int j){

	int ini = 1, fim = n, mid, best = -1 ; 

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(g[mid][j] >= x) best = mid, fim = mid - 1 ; 
		else ini = mid + 1 ; 
	}

	return best ; 

}

int bb2(int x, int j){

	int ini = 1, fim = n, mid, best = -1 ; 

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(g[mid][j] <= x) best = mid, ini = mid + 1 ; 
		else fim = mid - 1 ; 
	}

	return best ; 

}

int bb3(int x, int i, int in, int j){

	int ini = in, fim = j, mid, best = -1 ; 

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(g[i][mid] <= x) best = mid, ini = mid + 1 ; 
		else fim = mid - 1 ; 
	}

	return best ; 

}

int solve(int i, int ifi, int j, int x){

	int lado = (ifi - i + 1) ; 

	int ini = 0, fim = lado, mid, best = 0 ; 

	while(ini <= fim){
		mid = (ini + fim)>>1 ; 
		if(g[i+mid-1][j+mid-1] <= x && i + mid - 1 <= n && j + mid - 1 <= m) best = mid, ini = mid + 1 ; 
		else fim = mid - 1 ; 
	}

	return min(best, lado) ; 

}

int main(){

	while(true){

		cin >> n >> m ; 

		if(!n && !m) return 0 ; 

		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				cin >> g[i][j] ; 
			}
		}

		int q ; 

		cin >> q ; 

		for(int i = 1 ; i <= q ; i++){
			int l, r ; 
			cin >> l >> r ;
			int ans = 0 ; 
			for(int j = 1 ; j <= m ; j++){
				int fi1 = bb1(l, j) ; // 1o valor q >= l
				int fi2 = bb2(r, j) ; // ultimo valor <= r  
				if(fi1 == -1 || fi2 == -1) continue ; 
				int lado = (fi2 - fi1 + 1) ; 
				// cout << lado << " " << fi1 << " " << fi2 << "\n" ; 
				// usando a ultima linha ate q coluna eu pss ir 
				ans = max(ans, solve(fi1, fi2, j, r)) ; 
				// cout << solve(fi1, fi2, j, r) << "\n" ;
			}
			cout << ans << "\n" ;  
		}	
		cout << "-\n" ; 
	}

}
