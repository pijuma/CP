#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 1e5 + 5 ; 

int v[maxn], n, k ; 
int mx ; 

int32_t main(){
    
    cin >> n >> k ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;
    
    sort(v+1, v+1+n) ; reverse(v+1, v+1+n) ;
    
    int i = 1 ; 
    
    while(n){
        mx += v[i++]*min(k, n) ; 
        n -= min(k, n) ;
    }
    
    cout << mx << "\n" ; 
    
}
