#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e3 + 5 ; 

int n, v[maxn] ; 

int main(){

	// só coloca se a dist p prox for > 4
	// qt coloca?  

	while(true){
		cin >> n ;
		if(!n) return 0 ; 
		for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
		int z = 0, soma = 0, p = 0, f = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			if(!v[i] && !f) z++, p++ ; 
			else if(!v[i]) p++ ; 
			else{
				f = 1 ; 
				soma += (p/2) ; // tem mais de 2 com 0's coloca neles 
				p = 0 ; 
			}
		}

		if(p){ // se terminar com p dif 0 o ultimo ta ruim ai pega com os primeiros
			soma -= (z/2) ; // tira as pontes q colocou no começo 
			p += z ; // add as pontes a qtd de 0 
			soma += (p/2) ;  // add essas pontes 
		}

		cout << soma << "\n" ; 

	} 

}
