#include<bits/stdc++.h>
#define int long long
using namespace std ; 

const int inf = 1e18 ; 
const int maxn = 1e3 + 5 ; 

int v[maxn], n, sum, mn ; 

int32_t main(){

	// qm fizer soma impar ganha 

	mn = inf ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++){
		cin >> v[i] ; 
		sum += v[i] ; 
		mn = min(mn, v[i]) ; 
	}

	if(sum&1) cout << "lowie\n" ; 
	else{
		if(n&1) cout << "imitater\n" ; 
		else{
			if(mn&1) cout << "lowie\n" ; 
			else cout << "imitater\n" ; 
		}
	}

}
