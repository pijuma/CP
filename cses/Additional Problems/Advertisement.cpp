#include<bits/stdc++.h>
#define int long long 
 
using namespace std ; 
 
const int maxn = 2e5 + 5 ; 
 
int n, h[maxn], esq[maxn], dir[maxn] ; 
 
int32_t main(){
 
	cin >> n ; 
 
	for(int i = 1 ; i <= n ; i++) cin >> h[i] ; 
 
	int ans = 0 ; 
    
    h[0] = -1, h[n+1] = -1 ; 
 
    for(int i = 1 ; i <= n ; i++){
    	esq[i] = i-1 ; 
    	while(h[esq[i]] >= h[i]) esq[i] = esq[esq[i]] ; 
    }
 
    for(int i = n ; i > 0 ; i--){
    	dir[i] = i+1 ; 
    	while(h[dir[i]] >= h[i]) dir[i] = dir[dir[i]] ; 
    }
 
    for(int i = 1 ; i <= n ; i++){
    	ans = max(ans, (dir[i] - esq[i] - 1)*h[i]) ; 
    }
 
    cout << ans << "\n" ; 
 
}
