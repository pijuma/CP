#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5 + 5 ;

int n, q, t, p, k, v[maxn], bit[maxn] ;

struct BIT{
    
    void upd(int pos, int val){
        for( ; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
    }
    
    int query(int pos){
        int tot = 0 ; 
        for( ; pos > 0 ; pos -= pos&-pos) tot += bit[pos] ;
        return tot ; 
    }
    
} Bit ;

int main(){
    
    cin >> n >> q ; 
    
    for(int i = 1 ; i <= n ; i++){
        cin >> v[i] ;
        Bit.upd(i, v[i]) ;
    }
    
    while(q--){
        cin >> t ; 
        if(t == 1){
            cin >> k ; 
            cout << Bit.query(k) << "\n" ;
        }
        else{
            cin >> k >> p ; 
            Bit.upd(k, p - v[k]) ;
            v[k] = p ; 
        }
    }
    
}
