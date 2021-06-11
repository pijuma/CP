#include<bits/stdc++.h>
using namespace std ; 

int n, c, s, e ; 

int main(){
	
	//sai antes de entrar

	cin >> n >> c ; 
	
	int sum = 0 ; 
	bool ok = 1 ; 
	for(int i = 1 ; i <= n ; i++){
		cin >> s >> e ; 
		sum -= s ; 
		sum += e ; 
		if(sum > c){
			ok = 0 ;  
		}
	}

	cout << (ok ? "N\n" : "S\n") ; 

}
