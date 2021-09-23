#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, v, resp ; 
 
int main(){
 
	cin >> n ; 
 
	for(int i = 0 ; i < n ; i++){
		cin >> v ; 
		if(((n-1)&i) == i) resp ^= v ; 
	}
 
	cout << resp << "\n" ; 
 
}
