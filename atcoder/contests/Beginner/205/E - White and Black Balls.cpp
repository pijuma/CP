#include<bits/stdc++.h>
#define int long long
using namespace std ; 
     
const int mod = 1e9 + 7 ; 
const int maxn = 1e6 + 5 ; 
     
int n, k, m ; 
     
int exp(int a, int b){
    int ans = 1 ; 
    while(b){
    	if(b%2) ans = (ans*a)%mod ; 
    	a = (a*a)%mod ; 
    	b >>= 1 ;  
    }
    return ans ; 
}
     
int solve(int x, int y){
    if(x < 0 || y < 0) return 0 ;
    int ans = 1 ;  
    for(int i = 1 ; i <= x + y ; i++) ans = (ans*i)%mod ;
    for(int i = 1 ; i <= x ; i++) ans = (ans*exp(i, mod-2))%mod ; 
    for(int i = 1 ; i <= y ; i++) ans = (ans*exp(i, mod-2))%mod ; 
    return ans%mod ;
}
     
int32_t main(){
     
    cin >> n >> m >> k ; 
     
    if(n > m + k) cout << "0\n" ; 
    else cout << (solve(n, m) - solve(n-k-1, m+k+1) + mod)%mod<< "\n" ; 
}
