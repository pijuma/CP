#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e6 + 5 ; 

char a ; 
int n, d[maxn], e[maxn], qtd ; 

int main(){

	cin >> n ; 

	for(int i = 1, v ; i <= n ; i++){
		cin >> v >> a ; 
		if(a == 'D') d[v]++ ; 
		else e[v]++ ;  
	}

	for(int i = 30 ; i <= 60 ; i++){
		if(d[i] >= e[i]) qtd += e[i] ; 
		else qtd += d[i] ; 
	}

	cout << qtd << "\n" ; 
	
}
