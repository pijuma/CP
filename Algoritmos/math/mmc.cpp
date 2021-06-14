#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 ; 

int n, m ; 

int mdc(int a, int b){
	if(b > a) swap(a, b) ; 
	return (b == 0 ? a : mdc(a%b, b)) ; 
}

int main(){

	cin >> n >> m ; 
	cout << n*m/mdc(n, m) ; 
	cout << "\n" ; 
}