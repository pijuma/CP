#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, t, f[maxn], v[maxn] ; 

int main(){

	cin >> t ; 

	while(t--){

		cin >> n ; 

		memset(f, 0, sizeof f) ; 

		for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

		for(int i = 1 ; i <= n ; i++) f[v[i]]++ ; 

		int mx = 0, id = 1 ; 

	    sort(v + 1, v + 1 + n) ; 

	    for(int i = 1 ; i <= n ; i++){
	    	if(mx < f[v[i]]){
	    		mx = f[v[i]] ; id = v[i] ; 
	    	}
	    }

	    cout << id << "\n" ; 

	}

}
