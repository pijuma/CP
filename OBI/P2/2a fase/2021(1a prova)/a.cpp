#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// n ingredientes 
// m pares n podem ser usados ao msm tempo -> n combinam 
// qual o max de sanduiches bons q podem ser feitos 

const int maxn = 25 ; 

int n, m, v[maxn], resp, comp, pes ; 

int32_t main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> n >> m ; 

	for(int i = 0 ; i < m ; i++){
		int x, y ;
		cin >> x >> y ; 
		x--, y-- ; 
		v[x] |= (1<<y) ; v[y] |= (1<<x) ; 
	}

	for(int mask = 0 ; mask < (1<<n) ; mask++){
		
		pes = comp = 0 ; 

		for(int i = 0 ; i < n ; i++){
			if(!(mask&(1<<i))) continue ; // tenho q ver se tem algum q n pode em comum 
			pes |= (1<<i), comp |= v[i] ; 
		}

		int res = __builtin_popcount(pes&comp) ; 

		if(res == 0 && mask != 0) resp++ ; 

	}

	cout << resp << "\n" ; 

}
