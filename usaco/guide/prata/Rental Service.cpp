#include<bits/stdc++.h>
#define int long long
using namespace std ;

const int maxn = 1e5 + 5 ;

struct st{

    int q, p ;

} ;

bool cmp(st a, st b){ return a.p > b.p ; }

int n, m, r, rent[maxn], milk[maxn], v[maxn], bx[maxn] ;
st l[maxn] ;

int32_t main(){

    ifstream cin("rental.in");
    ofstream cout("rental.out");

    cin >> n >> m >> r ;

    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

    sort(v + 1, v + 1 + n) ; reverse(v + 1, v + 1 + n) ;

    for(int i = 1 ; i <= m ; i++){
        cin >> l[i].q >> l[i].p ;
    }

    sort(l + 1, l + 1 + m, cmp) ;

    for(int i = 1 ; i <= r ; i++) cin >> rent[i] ;

    sort(rent + 1, rent + 1 + r) ; reverse(rent + 1, rent + 1 + r) ;

    int ans = 0 ;

    for(int i = 1 ; i <= r ; i++) bx[i] = bx[i-1] + rent[i] ;

    int mon = 0 ;
    int lj = 1 ;

    for(int i = 1 ; i <= n ; i++){ // i vacas eu pego leite
        while(v[i] > 0 && lj <= m){
            int used = min(v[i], l[lj].q) ;
            mon += (used*l[lj].p) ;
            l[lj].q -= used ;
            v[i] -= used ;
            if(!l[lj].q) lj++ ;
        }
        milk[i] = mon ;
    }

    int rent = 0 ; int mlk = n ;

    while(rent <= r && mlk > 0){
        ans = max(ans, bx[rent] + milk[mlk]) ;
        rent++, mlk-- ;
    }

    cout << ans << "\n" ;

}
