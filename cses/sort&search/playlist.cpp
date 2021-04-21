#include<bits/stdc++.h>
using namespace std ; 

//2ptrs

const int maxn =  2e5 + 5 ; 

int ans, n, v[maxn] ; 
map<int,int> mp ; 

int main(){

	cin >> n ; 
	for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 
	for(int i = 1, j = 1 ; i <= n ; i++){
		while(j <= n && mp[v[j]] < 1){
			mp[v[j]]++, j++ ; 
		}
		ans = max(j-i, ans) ;
		mp[v[i]]-- ;  
	}

	cout << ans << "\n" ; 

}
