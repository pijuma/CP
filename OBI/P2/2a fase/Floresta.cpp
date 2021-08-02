#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 4e4 + 5 ; 

int n, ans ; 
https://github.com/pijuma/CP/tree/main/OBI/P2/2a%20fase
int qtd(int l, int c){ return (l*c) + ((l-1)*(c-1)) ; }

int32_t main(){

	cin >> n ; 

	for(int i = 2 ; i < maxn ; i++){ // dado um certo n° linhas qts colunas preciso ? 
		// a x b e b x a eh o msm ent a vai até raiz e b até o final assim testamos tds  

		int ini = 2, fim = n - 1, meio ; 

		while(ini <= fim){

			meio = (ini + fim)>>1 ;

			if(qtd(i, meio) == n && meio >= i){
				ans++ ; break ; 
			}

			if(qtd(i, meio) > n) fim = meio - 1 ; 
			else ini = meio + 1 ; 

		}

	}

	cout << ans << "\n" ; 

}
