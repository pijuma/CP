#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, v[maxn], ps[maxn] ; 

int bb(int i, int val){

	int ini = i, fim = n, mid, best = -1 ; 

	while(ini <= fim){
		mid = (ini + fim)/2 ; 
		if(ps[mid] == val) return mid ; 
		else if(ps[mid] > val) fim = mid - 1 ; 
		else ini = mid + 1 ; 
	}

	return -1 ; 

}

int main(){

	cin >> n ; 

	int ans = 0 ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i], ps[i] = ps[i-1] + v[i] ; 

	if(ps[n]%2) cout << "N\n", exit(0) ; 

	for(int i = 1 ; i <= n ; i++){
		int p = bb(i, (ps[n]/2) + ps[i]) ; 
		if(p != -1) ans++ ; 
		// if(p == n) ans-- ; 
	}

	if(ans >= 2) cout << "Y\n" ; 
	else cout << "N\n" ; 

}
