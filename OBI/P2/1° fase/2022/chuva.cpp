#include<bits/stdc++.h>
#define int long long 
using namespace std ; 

const int maxn = 1e6 + 5 ; 

vector<int> v ; 
int pref[maxn] ;

int32_t main(){
    
    // qts intervalos a soma eh menor ou igual a um certo valor 
    // pref[r] - pref[l-1] == x 
    // pref[l-1] == pref[r] - x // qual 1o cara q isso eh valido pra cada r e o ultimo - soma esse intervalo 
    
    int n, x ; cin >> n >> x ;
    
    int resp = 0 ;
    
    v.push_back(0) ;
    
    for(int i = 1 ; i <= n ; i++){
        int a ; cin >> a ;
        pref[i] = pref[i-1] + a ;
        auto b = lower_bound(v.begin(), v.end(), pref[i]-x) ;
        int p1 = -1, p2 = -1 ; 
        if(b != v.end()){ 
            p1 = (b - v.begin()+1) ;
            p2 = upper_bound(v.begin(), v.end(), pref[i]-x) - v.begin() ;
        }
        if(p1 != -1 && p2 != -1) resp += (p2-p1+1) ;
        v.push_back(pref[i]) ;
    }
    
    cout << resp << "\n" ;
    
}
