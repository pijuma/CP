// cnt come�a com n
// a cada uni�o reduz 1 numero
#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 3 ;
 
int n, m, ct, a, b, pai[maxn], sz[maxn], maior ;
 
struct Dsu{
 
    void init(){
        for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ;
        ct = n ;
        maior = 1 ;
    }
 
    int find(int a) { return pai[a] == a ? a : find(pai[a]) ; }
 
    void join(int a, int b){
        a = find(a), b = find(b) ;
        if(a==b) return ;
        if(sz[a] > sz[b]) swap(a,b) ;
        sz[b] += sz[a] ;
        pai[a] = b ;
        ct-- ;
        maior = max(maior, sz[b]) ;
    }
 
    void compcount(){
        cout << ct << " " ;
        return ;
    }
 
    void maxi(){
        cout << maior << "\n" ;
    }
}dsu;
int main(){
 
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
 
    cin >> n >> m ;
    dsu.init() ;
    for(int i = 1 ; i <= m ; i++){
        cin >> a >> b ;
        dsu.join(a,b) ;
        dsu.compcount() ;
        dsu.maxi() ;
    }
}
