#include<bits/stdc++.h>
using namespace std ; 

int n, d, fat[10], f[10][10] ; 

int main(){

	cin >> n ; 

	fat[0] = 1 ; 

	for(int i = 1 ; i <= n ; i++) fat[i] = fat[i-1]*i ; 

	for(int i = 1 ; i <= fat[n] - 1 ; i++){ // da uma seq a menos 

		for(int j = 1 ; j <= n ; j++){

			cin >> d ; 

			f[j][d]++ ; 

		}

	}

	// cada n° tem q aparecer fat[n-1] vzs em cada coluna -> qtd de forma de permutar o resto 

	for(int i = 1 ; i <= n ; i++){

		for(int j = 1 ; j <= n ; j++){

			if(f[i][j] != fat[n-1]) cout << j << " " ; 

		}

	}

	cout << "\n" ; 

}
