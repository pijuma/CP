#include<bits/stdc++.h>
#define int long long
using namespace std ; 

// queremos m^k 
// S de tds as posições 

const int maxn = 53 ; 
const int mod = 1e9 + 7 ; 

int n, k, ans  ; 

struct mat{

	int v[maxn][maxn] ; 

	void id(){
		for(int i = 0 ; i < n ; i++) v[i][i] = 1 ; 
	}

} ; 

mat mult(mat a, mat b){
	
	mat c ; 

	for(int i = 0 ; i < n ; i++){
		
		for(int j = 0 ; j < n ; j++){

			c.v[i][j] = 0 ; 

			for(int f = 0 ; f < n ; f++){
				c.v[i][j] = (c.v[i][j] + ((a.v[i][f]*b.v[f][j])%mod))%mod ; 
			}

		}

	}

	return c ; 

}

mat exp(mat a, int b){

	mat ans ; 
	ans.id() ; 

	while(b){

		if(b&1) ans = mult(ans, a) ; 
		a = mult(a, a) ; 
		b >>= 1 ; 

	}

	return ans ; 

}

int32_t main(){

	cin >> n >> k ; 

	mat m ; 

	for(int i = 0 ; i < n ; i++){
		
		for(int j = 0 ; j < n ; j++){
			cin >> m.v[i][j] ;  
		}

	}

	m = exp(m, k) ; 

	for(int i = 0 ; i < n ; i++){
		
		for(int j = 0 ; j < n ; j++){
			ans = (ans + m.v[i][j])%mod ;  
		}

	}

	cout << ans << "\n" ; 

}
