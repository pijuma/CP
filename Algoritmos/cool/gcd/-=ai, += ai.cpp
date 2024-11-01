https://codeforces.com/contest/2008/problem/G
#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define pii pair<int,int> 
#define ff first 
#define ss second 
using namespace std ; 

const int maxn = 2e5 + 5 ; 
const int mod = 1e9 + 7 ; 

/*
gcd(ai, aj) -> fica subtraindo um ao outro ate n ter mais como 
se pegarmos multiplos do gcd necessariamente n 
tem ng entre eles e eu consigo sempre jogar todos os 
numeros pra cada multiplo (euclides)
ai -= aj 
u %= v 
termina os 2 numeros como gcd muda um pra 0 e o outro mantem 
como pode somar terminamos com 0, gcd, 2gcd,.. 
gcd(a1, a2), 0, a3, a4 
gcd(a1, a2, a3), 0, 0, a4 
gcd(a1, a2, a3, a4), 0, 0, 0
n-1 0 e gcd
pode usar ai += aj 
0, g, 2g, 3g, 4g, ... 
conseguimos gerar todos os multiplos 
achar o kesimo faltando no set 
*/

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    int t ; cin >> t ; 

    while(t--){
        int n ; cin >> n ; int k ; cin >> k ; 
        int gcd = -1 ; 
        for(int i = 1 ; i <= n ; i++){
            int a ; cin >> a ; 
            if(gcd == -1) gcd = a; 
            else gcd = __gcd(gcd, a) ; 
        }
        int ans = -1 ; 
        if(n == 1){
            ans = k-1 ; 
            if(gcd < k) ans++ ; 
        }
        int ctr = 0 ; 
       // cout << gcd << "\n" ; 
        int ct = n ; int i = 0 ;  
        for( ; gcd > 1 && n > 1; i += gcd){
            ct-- ; 
            if(k < 0){
                ans = i+gcd ; break ; 
            }
            if(ct == 0) break ;
            k -= (gcd-1) ; 
        }
        //cout << ans <<" " << i << " " << k << "\n" ; 
        if(gcd == 1 && ans == -1){
            ans = n+k-1 ;
        }
        if(ans == -1){
            ans = i + k ; 
        }
        cout << ans << "\n" ; 
    }

} 
