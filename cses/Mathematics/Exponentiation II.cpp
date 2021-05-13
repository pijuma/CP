#include<bits/stdc++.h>
using namespace std ;
 
const long long mod = 1e9 + 7 ;
 
int n ;
long long a, b, c ;
 
long long expo(long long d, long long e, long long m){
 
    long long res = 1 ;
 
    while(e){
 
        if(e&1) res = (res*d)%m ;
 
        d = (d*d)%m ;
        e /= 2 ;
 
    }
 
    return res ;
}
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> a >> b >> c ;
 
        cout << expo(a,expo(b,c, mod-1), mod) << endl ;
 
    }
 
}
