#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, c, ind[maxn], x ;

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> x, ind[x] = i ; 
	
	c = 1 ;
    int last = 0 ; 
	
	// se fosse td crescente -> 1 isso pq o ind do anterior smp eh menor q o prox 
	// precisamos saber o n° min de vzs q o ind do anterior eh maior q o prof 
    // pois nesses casos teriamos q pegar separado
	
	for(int i = 1 ; i <= n ; i++){
		if(last > ind[i]) c++ ; 
		last = ind[i] ; 
	}

	cout << c << "\n" ;

}
