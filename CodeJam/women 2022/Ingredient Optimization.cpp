#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 105 ; 

int ans, t, d, n, u, ctr, ent[maxn], qtd[maxn], F[maxn], o[maxn] ; 

void solve(){

	ans = n ; 

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila ; 

	int last_timer = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		// add os novos
		for(int j = 1 ; j <= d ; j++){
			if(ent[j] > last_timer && ent[j] <= o[i]) fila.push({F[j], qtd[j]}) ; 
		}
		last_timer = o[i] ; 
		//retira os ruins 
		while(true){
			if(fila.empty()) break ; 
			int val = fila.top().first ;
			if(val > o[i]) break ; 
			fila.pop() ;  
		}
		// consigo resp 
		int qtd = 0 ; 
		while(true){
			if(fila.empty()) break ; 
			if(qtd >= u) break ; 
			int val = fila.top().second, excc = fila.top().first ; 
			int need = u - qtd ; 
			fila.pop() ;
			if(val > need){
				qtd = u ; 
				fila.push({excc, val - need}) ; 
			}
			else qtd += val ; 
		}
		if(qtd < u){
			cout << "Case #" << ++ ctr << ": " << i-1 << "\n" ; 
			return ; 
		}
	}

	cout << "Case #" << ++ ctr << ": " << n << "\n" ; 

}

int main(){

	cin >> t ; 

	while(t--){

		cin >> d >> n >> u ; 

		for(int i = 1 ; i <= d ; i++){
			cin >> ent[i] >> qtd[i] >> F[i] ; 
			F[i] += ent[i] ; 
		}   

		for(int i = 1 ; i <= n ; i++) cin >> o[i] ; 

		solve() ; 

	}

}
