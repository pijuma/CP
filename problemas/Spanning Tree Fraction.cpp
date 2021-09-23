#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 5 ; 

struct edg{
    int a, b, c, d, id ; 
} ; 

struct O{
    int a, b ; 
    double w ; 
    int id ; 
} ; 

int n, m, A, B, pai[maxn], sz[maxn] ; 
edg edge[maxn] ; 
O e[maxn] ; 

bool cmp(O a, O b){ return a.w > b.w ; }

struct DSU{

    int find(int a){return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

    void join(int a, int b){
        a = find(a), b = find(b) ; 
        if(sz[a] > sz[b]) swap(a, b) ; 
        sz[b] += sz[a] ; pai[a] = b ; 
    }

} dsu ; 

bool test(double s){

    for(int i = 0 ; i < n ; i++) pai[i] = i, sz[i] = 1 ; 

    for(int i = 0 ; i < m ; i++){
        e[i].a =  edge[i].a, e[i].b = edge[i].b ; 
        e[i].w = (double) edge[i].c - edge[i].d*s, e[i].id  = edge[i].id ; 
    }

    A = 0, B = 0 ; 

    sort(e, e + m, cmp) ;  

    for(int i = 0 ; i < m ; i++){
        if(dsu.find(e[i].a) == dsu.find(e[i].b)) continue ; 
        dsu.join(e[i].a, e[i].b) ; 
        A += edge[e[i].id].c, B += edge[e[i].id].d ; 
    }

    return A >= B*s ; 

}

int main(){

    cin >> n >> m ; 

    for(int i = 0 ; i < m ; i++){
        int a, b, c, d ; 
        cin >> a >> b >> c >> d ; 
        edge[i] = {a, b, c, d, i} ; 
    }

    double ini = 0.00, fim = (double)1e9, mid, best = 0.00 ;

    while(fim - ini > 0.0001){
        mid = (ini + fim)/2 ; 
        if(test(mid)) best = mid, ini = mid ; 
        else fim = mid ; 
    }

    cout << (A/__gcd(A, B)) << "/" << (B/__gcd(A, B)) << "\n" ; 

}
