#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e3 + 5 ; 
const int inf = 1e9 ; 

int n, m, u[maxn], v[maxn], w[maxn], d[maxn] ; 

bool bel(int s){

	for(int i = 0 ; i <= n ; i++) d[i] = inf ; 
	d[s] = 0 ; 

    for(int i = 0 ; i < n ; i++){
    	for(int j = 0 ; j < m ; j++){
    		if(d[u[j]] + w[j] < d[v[j]]) d[v[j]] = d[u[j]] + w[j] ; 
    	}
    }

    for(int i = 0 ; i < m ; i++){
    	if(d[u[i]] + w[i] < d[v[i]]) return true ; 
    }

    return false ; 

}

int main(){

	cin >> n >> m ; 

	for(int i = 0 ; i < m ; i++) cin >> u[i] >> v[i] >> w[i] ; 

	if(bel(u[0])) cout << "S\n" ; 
	else cout << "N\n" ; 

}
