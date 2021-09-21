#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n ; 
char m[maxn][maxn] ; 

// dentro fora dentro 

int main(){

	cin >> n ; 

	bool ans = 1 ; 

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> m[i][j] ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){ // linha 
		int p = 0 ; 
		for(int j = 1 ; j <= n ; j++){
			if(m[i][j] == '*' && (p == 0 || p == 2)) p++ ; 
			if(m[i][j] == '.' && p == 1) p++ ;
			if(p == 3){
				cout << "N\n" ; 
				return 0 ; 
			} 
		}
	}

	for(int j = 1 ; j <= n ; j++){
		int p = 0 ; 
		for(int i = 1 ; i <= n ; i++){
			if(m[i][j] == '*' && (p == 0 || p == 2)) p++ ;
			if(m[i][j] == '.' && p == 1) p++ ; 
			if(p == 3){
				cout << "N\n" ; 
				return 0 ; 
			}
		}
	}

	cout << "S\n" ; 

}
