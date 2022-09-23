#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 1e3 + 5 ;

int n, v[maxn], x[maxn] ;

int32_t main(){


    ifstream cin("outofplace.in");
    ofstream cout("outofplace.out");

    cin >> n ;

    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

    for(int i = 1 ; i <= n ; i++) x[i] = v[i] ;

    sort(x + 1, x + 1 + n) ;

    int ctr = 0 ;

    for(int i = 1 ; i <= n ; i++) ctr += (x[i] != v[i]) ;

    ctr = max(0LL, ctr-1) ;

    cout << ctr << "\n" ;

}
