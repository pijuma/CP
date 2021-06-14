#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 ; 

int n, ehprimo[maxn] ; 

bool  prim(){
	for(int i = 2 ; i*i <= n ; i++){
		if(n%i == 0) return 1 ; 
	}
	return 0 ; 
}

int main(){

	cin >> n ; 
	cout << (prim() ? "n\n" : "s\n") ; 
	cout << "\n" ; 
}