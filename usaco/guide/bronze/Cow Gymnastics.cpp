#include<bits/stdc++.h>
using namespace std ;

const int maxn = 30 ;
int n, k, v[maxn][maxn], x ;

int main(){

    ifstream cin("gymnastics.in");
    ofstream cout("gymnastics.out");

    cin >> k >> n ;

    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= n ; j++) cin >> v[i][j] ;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue ; // i mlr q j
            bool ok = 1 ;
            for(int t = 1 ; t <= k ; t++){
                int api = 0 ;
                for(int c = 1 ; c <= n ; c++){
                    if(v[t][c] == j && !api) ok = 0 ;
                    if(v[t][c] == i) api = 1 ;
                }
            }
            x += ok ;
        }
    }

    cout << x << "\n" ;

}
