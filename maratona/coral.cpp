#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

int n, v[maxn], s ; 

int solve(){

	if(s%n) return -1 ; 

	int val = 0 ; 
	s /= n ; // valor de cada

	for(int i = 1 ; i <= n ; i++) if(v[i] > s) val += abs(v[i] - s) ; 

	return val + 1 ; 

}

int main(){

	while(cin >> n){

		s = 0 ; 

		for(int i = 1 ; i <= n ; i++) cin >> v[i], s += v[i] ;

		cout << solve() << "\n" ; 

	}

}
