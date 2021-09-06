#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int n ; 

int32_t main(){

	while(true){
		cin >> n ; 
		if(!n) return 0 ; 
		int qtdp = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			int v, qtd ; 
			cin >> v >> qtd ; 
			qtdp += (qtd/2) ; 
		}
		cout << qtdp/2 << "\n" ; 
	}

}
