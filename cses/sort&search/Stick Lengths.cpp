#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,int> 
#define f first 
#define s second 
#define int long long 
using namespace std ; 
 
const int maxn = 2e5 ; 
const int inf = 1e5 ; 
 
int n, ans, v[maxn] ; 
 
int32_t main(){
 
	cin >> n ; 
 
	for(int i = 0 ; i < n ; i++) cin >> v[i] ; 
 
	sort(v, v+n) ;
    
    int mid = v[n/2] ; 
 
    for(int i = 0 ; i < n ; i++) ans += (abs(v[i] - mid)) ;
 
    cout << ans << "\n" ;  
 
}
