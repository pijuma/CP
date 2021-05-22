#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

int n, k, v[110] ; 
bool dp[maxn] ; 

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	// faz p tds as qts de pedras as posições vencedores e perdedoras
  // sempre q retirando uma certa qtd eu consegui colocar pra uma posição perdedora, eu coloco
  // assim eu irei ganhar

	sort(v + 1, v + 1 + n) ; 

	for(int i = 1 ; i <= k ; i++){ // tem como ganhar tendo k pedras ? 
		for(int j = 1 ; j <= n ; j++){
			if(v[j] > i) break ; 
			if(!dp[i-v[j]]) dp[i] = 1 ; // se retirar v[j] eu vou p uma perdedora? sim? ent a atual é vencedora  
		}
	}

	cout << (dp[k] ? "First\n" : "Second\n") ; 

}
