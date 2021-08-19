#include<bits/stdc++.h>
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, v[maxn], lef[maxn], rig[maxn] ; 
 
int main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	lef[0] = -1, rig[n+1] = -1 ;
 
	for(int i = 1 ; i <= n ; i++){
		lef[i] = i-1 ; 
		while(v[lef[i]] >= v[i]) lef[i] = lef[lef[i]] ; 
	} 
 
	for(int i = 1 ; i <= n ; i++) cout << lef[i] << " " ; 
	cout << "\n" ; 
 
}
