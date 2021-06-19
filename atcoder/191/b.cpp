#include<bits/stdc++.h>
using namespace std ; 

int n, x, a ; 

int main(){

	cin >> n >> x ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> a ; 
		if(a == x) continue ; 
		cout << a << " " ; 
	}

	cout << "\n" ; 
	
}