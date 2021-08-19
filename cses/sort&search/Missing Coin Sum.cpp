#include<bits/stdc++.h>
using namespace std ; 
#define int long long 
const int maxn = 2e5 + 5 ; 
 
int sum, v[maxn], n ; 
 
int32_t main(){
 
	//tds as menores : 1, 2, 3, ..., n
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
 
	sort(v+1, v+1+n) ;  
    
    for(int i = 1 ; i <= n ; i++){
    	if(sum + 1 < v[i]) break ; 
    	sum += v[i] ; 
    }
 
    cout << sum + 1 << "\n" ; 
}
