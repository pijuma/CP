#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 505 ; 

int n, m, al[maxn] ;

void solve(){

	for(int i = 1 ; i <= n ; i++) al[i] = 1 ; 

	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			int x ; 
			cin >> x ; 
			al[j] &= x ; 
		}
	}

	for(int i = 1 ; i <= n ; i++){
		if(al[i]){
			cout << "yes\n" ; 
			return ; 
		}
	}

	cout << "no\n" ;

}

int main(){

	while(true){
		cin >> n >> m ; 
		if(!n && !m) return 0 ; 
		solve() ;
	}

}
