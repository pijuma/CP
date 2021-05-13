#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 5 ;
const int maxl = 30 ;
 
int n, q, tab[maxl][maxn] ;
int k, x ;
 
int main(){
 
    cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++) cin >> tab[0][i] ;
 
    for(int i = 1 ; i < maxl ; i++){
        for(int j = 1 ; j <= n ; j++){
            tab[i][j] = tab[i-1][tab[i-1][j]] ;
        }
    }
 
    while(q--){
        cin >> x >> k ;
        for(int i = maxl-1 ; i >= 0 ; i--){
            if(k >= (1<<i)){
                k -= (1<<i) ;
                x = tab[i][x] ;
            }
        }
        cout << x << "\n" ;
    }
}
