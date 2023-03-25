//https://codeforces.com/problemset/problem/766/D
#include<bits/stdc++.h>
using namespace std ; 

// são amgs -> liga os normais p eles 
// e os opostos de cada um entre si
// sao inimigos -> amg dos opostos 

const int maxn = 3e5 + 5 ; 

int n, m, q, id ;
int sz[maxn], pai[maxn] ;

map<string, int> mp ; 

struct DSU{

    int find(int a){ return (a == pai[a] ? a : pai[a] = find(pai[a])) ; }

    bool joine(int a, int b){
        if(find(a) == find(b)) return 0 ; 
        int opa = find(a+n+1), opb = find(b+n+1) ; 
        a = find(a), b = find(b) ; 
        if(sz[a] > sz[opb]) swap(a, opb) ; 
        if(sz[opa] > sz[b]) swap(b, opa) ;
        pai[a] = opb ; pai[opa] = b ; 
        sz[opb] += sz[a], sz[b] += sz[opa] ;
        return 1 ; 
    }

    bool joinf(int a, int b){//conecto bonitin
        if(find(a) == find(b+n+1)) return 0 ; 
        int opa = find(a+n+1), opb = find(b+n+1) ;
        a = find(a), b = find(b) ; 
        if(sz[a] > sz[b]) swap(a, b) ;
        if(sz[opa] > sz[opb]) swap(opa, opb) ;
        pai[a] = b ; pai[opa] = opb ; 
        sz[b] += sz[a], sz[opb] += sz[opa] ;
        return 1 ; 
    }

} dsu ; 

bool f(int a, int b){ return (dsu.find(a) == dsu.find(b)) ; }
bool e(int a, int b){ return (dsu.find(a+n+1) == dsu.find(b)) ; }


int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n >> m >> q ; 

    for(int i = 1 ; i <= n ; i++){
        string a ; cin >> a ; 
        mp[a] = i ; 
    }

    for(int i = 1 ; i <= n ; i++){
        sz[i] = 1 ; sz[i+1+n] = 1 ;  
        pai[i] = i ; pai[i+1+n] = i+1+n ; 
    }

    for(int i = 1 ; i <= m ; i++){
        string a, b ; int t ; 
        cin >> t >> a >> b ; 
        int aa = mp[a], bb = mp[b] ;
        if(t == 1){//amg
           if(dsu.joinf(aa, bb)) cout << "YES\n" ; 
           else cout << "NO\n" ;
        }
        else{
            if(dsu.joine(aa, bb)) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }

    for(int i = 1 ; i <= q ; i++){
        string a, b ; cin >> a >> b ; 
        int aa = mp[a], bb = mp[b] ; 
        if(f(aa, bb)) cout << "1\n" ;
        else if(e(aa, bb)) cout << "2\n" ; 
        else cout << "3\n" ;
    }

}
