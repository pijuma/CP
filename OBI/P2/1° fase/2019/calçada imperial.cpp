#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 550 ; 

int n, v[maxn], ans, best ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			int n1 = v[i], n2 = v[j], last = 0, ans = 0 ; 
			for(int k = 1 ; k <= n ; k++){
				if(last == v[k]) continue ; 
				if(n1 == v[k] || n2 == v[k]){
					ans++ ; 
					last = v[k] ; 
				}
			}
			best = max(best, ans) ;
		}
	}

	cout << best << "\n" ; 
	
}
