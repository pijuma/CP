// pega o maior valor a dir e a esq para cada i (parecida com histograma)
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5 + 2 ;

int n, v[maxn], l[maxn], r[maxn], res ;

int main(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin >> v[i] ;
    l[0] = v[0] ;
    r[n-1] = v[n-1] ;
    for(int i = 1 ; i < n ; i++){
        l[i] = max(l[i-1], v[i]) ;
    }
    for(int i = n - 2 ; i >= 0 ; i--){
        r[i] = max(v[i], r[i+1]) ;
    }
    for(int i = 0 ; i < n ; i++){
        if(v[i] < r[i] && v[i] < l[i]) res++ ;
    }
    cout << res ;
}
