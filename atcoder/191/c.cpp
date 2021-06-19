#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 12 ; 

int h, w, cnt, ans ; 
char grid[maxn][maxn] ; 

int main(){

	cin >> h >> w ; 

	for(int i = 1 ; i <= h ; i++){
		for(int j = 1 ; j <= w ; j++){
			cin >> grid[i][j] ; 
		}
	}

	for(int i = 1 ; i <= h ; i++){
		for(int j = 1 ; j <= w ; j++){
			cnt = 0 ; 
			// if(grid[i][j] == '.') continue ; 
			if(grid[i][j] == '#') cnt++ ; 
			if(grid[i+1][j+1] == '#') cnt++ ; 
			if(grid[i+1][j] == '#') cnt++ ; 
			if(grid[i][j+1] == '#') cnt++ ; 
			if(cnt%2) ans++ ; 
		}
	}

	cout << ans << "\n" ; 

}