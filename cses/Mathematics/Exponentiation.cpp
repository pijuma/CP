#include<bits/stdc++.h>
using namespace std ;
 
const long long mod = 1e9 + 7 ;
 
int n ;
long long res, a, b ;
 
long long expo(long long a, long long b){
 
    if(b == 0) return 1 ;
 
    res = expo(a,b/2)%mod ;
 
    if(b&1) return (((res*res)%mod)*a)%mod ;
    return (res*res)%mod ;
 
}
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> a >> b ;
 
        cout << expo(a,b) << endl ;
 
    }
 
}
