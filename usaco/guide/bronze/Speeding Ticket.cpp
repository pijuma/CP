#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 1e5 + 5 ;

int n, m, c[maxn], s[maxn], v[maxn] ;

int32_t main(){


	ifstream cin("speeding.in");
    ofstream cout("speeding.out");

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++) cin >> c[i] >> s[i] ;

    int f = 1 ;

    for(int i = 1 ; i <= m ; i++){
        int cc, vv ;
        cin >> cc >> vv ;
        for(int j = f ; j < f + cc ; j++) v[j] = vv ;
        f = f + cc ;
    }

    f = 1 ;

    int mx = 0 ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = f ; j < f + c[i] ; j++){
            if(v[j] <= s[i]) continue ;
            mx = max(mx, v[j] - s[i]) ;
        }
        f = f + c[i] ;
    }

    cout << mx << "\n" ;

}
