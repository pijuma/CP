#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 110 ; 

bool valid(int i, int j){ return i > 0 && j > 0 && i <= 10 && j <= 10 ; }

int n, board[maxn][maxn] ; 

int32_t main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		int d, l, r, c ; 
		cin >> d >> l >> r >> c ; 
		if(d == 0){
			for(int j = c ; j <= c + l - 1 ; j++){
				if(!valid(r, j)){
					cout << "N\n" ; exit(0) ; 
				}
				board[r][j]++ ; 
			} 
		}
		else{
			for(int j = r ; j <= r + l - 1 ; j++){
				if(!valid(j, c)){
					cout << "N\n" ; exit(0) ; 
				}
				board[j][c]++ ; 
			}
		}
	}

	for(int i = 1 ; i <= 10 ; i++){
		for(int j = 1 ; j <= 10 ; j++){
			if(board[i][j] > 1){
				cout << "N\n" ; exit(0) ; 
			}
		}
	}

	cout << "Y\n" ; 

}
