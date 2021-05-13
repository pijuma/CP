#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 10 ;
 
// se for 1 : soma bit[k] = u ;
// atualiza o vetor e faz o upd na bit
// se for 2 : cout << query[b] - query[a - 1] ;
 
long long BIT[maxn], v[maxn];
long long n, u, k, t, q ;
 
struct Bit{
 
    void upd(long long val, int pos){
 
        for(; pos < maxn ; pos += pos&-pos){
 
            BIT[pos] += val ;
 
        }
 
    }
 
    long long query(int pos){
 
        long long t = 0 ;
 
        for(; pos > 0 ; pos -= pos&-pos){
 
            t += BIT[pos] ;
        }
 
        return t ;
 
    }
 
}bit;
int main(){
 
    cin >> n >> q ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> v[i] ;
        bit.upd(v[i], i) ;
 
    }
 
    for(int i = 1 ; i <= q ; i++){
 
        cin >> t >> k >> u ;
 
        if(t == 1){
 
            bit.upd(-v[k] + u, k) ;
            v[k] = u ;
 
        }
 
        else cout << bit.query(u) - bit.query(k - 1) << endl;
 
    }
 
}
