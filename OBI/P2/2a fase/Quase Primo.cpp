#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 45 ; 

int n, k, v[maxn], soma ; 

void prim(int i, long long num, int qtd){ //inclusao-exclusao

	if(num > n) return ; 

	if(i == k + 1){

		if(num == 1 || qtd == 0) return ; 
		if(qtd%2) soma += (n/num) ; // qtd de n°'s 
		else soma -= (n/num) ; 

		return ; 

	}

	prim(i+1, num*v[i], qtd+1), prim(i+1, num, qtd) ; //pss usar o atual ou n

}

int main(){

	cin >> n >> k ; 

	for(int i = 1 ; i <= k ; i++) cin >> v[i] ; // são os primos q ele vai considerar 

	prim(1, 1, 0) ; 

    cout << n - soma << "\n" ; 

}
