#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 220 ; 

int n, v[maxn], freq[maxn] ; 

int main(){

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

	for(int i = 1 ; i <= n ; i++) freq[v[i]]++ ; 

	int mx = 0, vmx = 0 ;
    
    sort(v + 1, v + 1 + n) ; 

	for(int i = 1 ; i <= n ; i++){
		if(freq[v[i]] >= mx) mx = freq[v[i]], vmx = v[i] ; 
	} 

	cout << vmx << "\n" ; 

}
