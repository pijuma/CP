// fatora cada n°
// guarda um map de vector de pair
// add cada fatoração no map 
// faz o complementar p cada numero 
// soma na resp a qtd de valores salvos no map 
// retira 1 se for igual 
// o expoente guarda modulo k 
// pq ai tira o caso de x n ser primo 

#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int k, n, resp, v[maxn] ; 
vector<pair<int,int>> v2[maxn] ; 
map<vector<pair<int,int>>, int> mp ; 

void add(int ind){

	vector<pair<int,int>> fac ; 
	int val = v[ind] ; 

	for(int i = 2 ; i * i <= val ; i++){
		
		int ct = 0 ; 

		while(val%i == 0){
			ct++ ; val /= i ; 
		}

		ct %= k ; 
		if(ct) fac.push_back({i, k - ct}) ; 

	}

	if(val > 1) fac.push_back({val, k - 1}) ; 
	
	mp[fac]++ ; 
	v2[ind] = fac ; 

}

void att(int ind){

	vector<pair<int,int>> fac, neww ; 
	int val = v[ind] ; 

	for(int i = 2 ; i * i <= val ; i++){
		
		int ct = 0 ; 

		while(val%i == 0){
			ct++ ; val /= i ; 
		}

		ct %= k ; 
		if(ct) fac.push_back({i, ct}); 

	}

	if(val > 1){
		fac.push_back({val, 1}) ; 
	}
	
	resp += mp[fac] - (fac == v2[ind]) ; 

}

int32_t main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++) add(i) ; // add a fat de vi no map -> meu precisa de 

	for(int i = 1 ; i <= n ; i++) att(i) ; //att resp -> tenho .. qts precisam de mim?

	cout << resp/2 << "\n" ; // xy = yx

}
