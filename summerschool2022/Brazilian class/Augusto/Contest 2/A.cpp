#include<bits/stdc++.h>
#define int long long 
#define ll long long
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, a, prime[maxn], b, c ; 

int32_t main(){

	cin >> n ;

	for(int i = 1 ; i <= n ; i++){
		int x ; 
		cin >> x ; 
		if(x - 2 <= 2 && x%2 == 0)  cout << "-1\n" ; 
		else if(x-3 <= 3 && x&1) cout << "-1\n" ; 
		else{
			if(x&1) cout << 3 << " " << x-3 << "\n" ; 
			else cout << 2 << " " << x-2 << "\n" ; 
		}  
	}


}
