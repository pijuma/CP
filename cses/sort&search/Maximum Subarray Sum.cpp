#include<bits/stdc++.h>
using namespace std ;
 
int n, a ;
 
int main(){
 
    cin >> n ;
 
    long long maior = -1e18, ans = -1e18 ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> a ;
 
        maior = max(0LL + a, maior + a) ;
        ans = max(ans, maior) ;
 
    }
 
    cout << ans ;
 
}
