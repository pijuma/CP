#include<bits/stdc++.h>
using namespace std ; 
 
int ans ; 
char m[10][10] ;
int mark[20], mark2[20], l[20] ; 
 
void solve(int q){
	if(q == 8){
		ans++ ; 
		return ; 
	}
	for(int i = 0 ; i < 8 ; i++){
		if(m[i][q] == '.' && mark[i+q] == 0 && mark2[i-q+7] == 0 && l[i] == 0){
			mark[i+q] = 1, mark2[i-q+7] = 1, l[i] = 1 ; 
			solve(q+1) ; 
			mark[i+q] = 0, mark2[i-q+7] = 0, l[i] = 0 ; 
		}
	}
}
 
int main(){
 
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			cin >> m[i][j] ; 
		}
	}
 
	solve(0) ; 
 
	cout << ans << "\n" ;
 
}
