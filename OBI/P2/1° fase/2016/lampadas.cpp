#include<bits/stdc++.h>
using namespace std ; 

int ia, ib, fa, fb ; 

int main(){

	cin >> ia >> ib >> fa >> fb ; 
	// se ia != fa, smp usa 1 
	// pode fzr separado ou com os dois 
	if(ia != fa) cout << 1 << "\n" ; 
	else if(ib == fb) cout << 0 << "\n" ; 
	else cout << 2 << "\n" ; 
	
}
