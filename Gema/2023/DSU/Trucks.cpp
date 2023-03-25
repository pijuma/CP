// https://codeforces.com/gym/101473/attachments
// ideia de guardar o "tempo" em que a união foi feita 
#include<bits/stdc++.h>
using namespace std ; 

const int inf = 1e9 + 2 ; 
const int maxn = 1e5 + 5 ; 

struct A{

    int a, b, c ; 

} ;

int n, q, m, tmp[maxn], sz[maxn], pai[maxn] ;
A ar[maxn] ;

bool cmp(A a, A b){ return a.c > b.c ; }

struct DSU{

    int find(int a, int t){
        if(pai[a] == a || tmp[a] < t) return a ; 
        return find(pai[a], t) ;
    }

    void join(int a, int b, int t){
        a = find(a, t), b = find(b, t) ; 
        if(a == b) return ; 
        if(sz[a] > sz[b]) swap(a, b) ;
        tmp[a] = t ;
        pai[a] = b ; sz[b] += sz[a] ;
    }

} dsu ;

int ans(int a, int b){

    int ini = 0, fim = inf, mid, best = 0 ; 

    while(ini <= fim){
        mid = (fim + ini)>>1 ; 
        if(dsu.find(a, mid) == dsu.find(b, mid)) best = mid, ini = mid + 1 ; 
        else fim = mid - 1 ; 
    }

    return best ; 

}

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n >> m >> q ; 

    for(int i = 1 ; i <= n ; i++){
        pai[i] = i, sz[i] = 1, tmp[i] = maxn ; 
    }

    for(int i = 1 ; i <= m ; i++){
        int a, b, c ; cin >> a >> b >> c ;
        ar[i] = {a, b, c} ; 
    }

    sort(ar+1, ar+1+m, cmp) ;

    for(int i = 1 ; i <= m ; i++){
        int a = ar[i].a, b = ar[i].b, c = ar[i].c ;
        dsu.join(a, b, c) ;
    }

    for(int i = 1 ; i <= q ; i++){
        int a, b ; cin >> a >> b ; 
        cout << ans(a, b) << "\n" ;
    }

}
