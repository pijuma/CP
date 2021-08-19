#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 1 ;
 
int n, x, p[maxn] ;
 
int main(){
 
    cin >> n >> x ;
 
    for(int i = 1 ; i <= n ; i++) cin >> p[i] ;
 
    sort(p + 1, p + 1 + n) ;
 
    int ans = 0 ;
 
    for(int i = 1, j = n; i < j; ){
 
        while(p[i] + p[j] > x && i < j) j-- ;
 
        if(i >= j) break ;
 
        ans++ ;
        i++, j-- ;
 
    }
 
    cout << n - ans ;
}
