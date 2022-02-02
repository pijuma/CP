#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int maxn = 1e6 + 2 ; 

int n, m, X[maxn] ; 
map<int,int> pairr, pos1, pos2 ; 
map<int,int> exists ; 

int32_t main(){

	int x = 1, y = 1 ; 
	bool turn = 1 ; 

	while(x < maxn && y < maxn){
		pairr[min(y, x)] = max(x, y) ; 
		if(turn) x += y ; 
		else y += x ; 
		turn ^= 1 ; 
	}

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> X[i] ; 
		if(pos1.find(X[i]) == pos1.end()) pos1[X[i]] = i ; 
		else pos2[X[i]] = i ; 
		exists[X[i]]++ ; 
	}

	int pi = 0, pj = 0 ; 

	bool ans = 0 ; 

	for(int i = 1 ; i <= n ; i++){
		if(exists[1] >= 2){
			cout << pos1[1] << " " << pos2[1] << "\n" ; 
			exit(0) ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){

		int par = pairr[X[i]] ; 
		// cout << par << "\n" ; 

		if(par == X[i]){
			// cout << i << "\n" ; 
			if(exists[par] >= 2){
				ans = 1 ; 
				pi = i ; 
				if(pos1[X[i]] == i) pj = pos2[X[i]] ; 
				else pj = pos1[X[i]] ; 
				break ; 
			}
		}

		else if(exists[par]) {
			pi = i, pj = pos1[par] ; 
			ans = 1 ; 
			break ; 
		}

	}

	if(ans) cout << pi << " " << pj << "\n" ; 
	else cout << "impossible\n" ; 

}
