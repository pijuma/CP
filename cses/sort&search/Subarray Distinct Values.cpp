#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, k, dif, qtd, v[maxn] ;
map<int,int> f ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
	 
	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int l = 1, r = 1 ; r <= n ; r++){
		f[v[r]]++ ; 
		if(f[v[r]] == 1) dif++ ; 
		while(dif > k){
			f[v[l]]-- ; 
			if(!f[v[l]]) dif-- ;
			l++ ;  
		}
		qtd += (r-l+1) ; 
	}

	cout << qtd << "\n" ; 

}
