#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 ; 

int n, ehprimo[maxn] ; 

void crivo(){
	for(int i = 2 ; i <= n ; i++) ehprimo[i] = -1 ; 
	for(int i = 2 ; i <= n ; i++){
		if(ehprimo[i] == -1){
			for(int j = i + i ; j <= n ; j += i) ehprimo[j] = 0 ;
			ehprimo[i] = 1 ;  
		}
	}
}

int main(){

	cin >> n ; 
	crivo() ; 
	for(int i = 2 ; i <= n ; i++){
		if(!ehprimo[i]) continue ; 
		else cout << i << " " ; 
	}
	cout << "\n" ; 
}