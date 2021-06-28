#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, m, le[maxn], ld[maxn], mx, h[maxn] ; 
char g[maxn][maxn] ; 

int main(){

	cin >> n >> m ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> g[i][j] ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){ //histograma p cada linha - semana 2

		for(int j = 1 ; j <= m ; j++){
			if(g[i][j] == '*') h[j] = 0 ; 
			else h[j]++ ;  
		}

		h[0] = -1 ; h[m+1] = -1 ; 
		
		for(int j = 1 ; j <= m ; j++){
			le[j] = j-1 ; 
			while(h[le[j]] >= h[j]) le[j] = le[le[j]] ;  
		} 

		for(int j = m ; j > 0 ; j--){
			ld[j] = j+1 ; 
			while(h[ld[j]] >= h[j]) ld[j] = ld[ld[j]] ;  
		}

		for(int j = 1 ; j <= m ; j++){
			mx = max(mx, (ld[j] - le[j] - 1)*h[j]) ; 
		}

	}

	cout << mx << "\n" ; 

}
