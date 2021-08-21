#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, ps[maxn], v[maxn], newv[maxn], st ; 

int bb(int i, int val){

	if(i > n) return -1 ; 

	int ini = i, fim = n, mid, best = -1 ; 

	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		if(ps[mid] - ps[i-1] == val) return mid ; 
		else if(ps[mid] - ps[i-1] > val) fim = mid-1 ; 
		else ini = mid + 1 ; 
	}
	
	return -1 ;

}

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
	for(int i = 1 ; i <= n ; i++) st += v[i] ; 

	for(int i = 1 ; i <= n ; i++){ // fixa onde corta  
	    int qtd = 1 ; 
		for(int j = i ; j <= n ; qtd++, j++) newv[qtd] = v[j] ; 
		for(int j = 1 ; j < i ; qtd++, j++) newv[qtd] = v[j] ; 
		for(int j = 1 ; j <= n ; j++) ps[j] = ps[j-1] + newv[j] ; 
		// fixo até onde vou e faço bb p saber qual o espaço necessario 
		int sum = 0 ; 
		for(int j = 1 ; j <= n ; j++){
			sum = ps[j] ;
			// cout << i << " " << j << " " << sum << "\n" ; 
			int gap = (st - sum - sum)/2 ; 
			int pr = bb(j+1, gap) ;  
			if(pr == -1) continue ; 
			pr++ ; 
			if(pr > n) continue ; 
			int kr = bb(pr, sum) ; 
			if(kr != -1){
				cout << "S\n" ; 
				return 0 ; 
			}
		}

	}

	cout << "N\n" ; 

}
