#include<bits/stdc++.h>
using namespace std ; 

int n, x ; 

int main(){

	cin >> n ; 
	int maior = 0, resp = 0 ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> x ; 
		maior = max(0, maior + x) ; 
		resp = max(resp, maior) ; 
	}

	cout << resp << "\n" ; 
	
}
