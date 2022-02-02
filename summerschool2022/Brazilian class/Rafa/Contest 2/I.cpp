#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, v[maxn], b[maxn] ; 

int solve(int x){
	for(int i = 0 ; i < n ; i++){
		if(x + v[i] > b[i]) return 1 ; 
		if(x + v[i] < b[i]) return 0 ; 
	}
	return 1 ; 
}

int main(){

	cin >> n ; 

	for(int i = 0 ; i < n ; i++) cin >> v[i] ; 
	for(int i = 0 ; i < n ; i++) cin >> b[i] ; 
	for(int i = 0 ; i < maxn ; i++){
		if(solve(i)){
			cout << i << "\n" ; return 0 ; 
		}
	}

}
