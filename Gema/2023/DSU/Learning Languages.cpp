//https://codeforces.com/contest/277/problem/A
// ligo 2 caras se eles sabem uma ling em comum 
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 110 ; 

int pai[maxn], sz[maxn], comp, n, m ; 
bool lng[maxn][maxn] ; 
vector<int> kn[maxn] ; 

struct DSU{

    int find(int a){ return (pai[a] == a ? a : pai[a] = find(pai[a])) ; }

    void join(int a, int b){
        a = find(a), b = find(b) ; 
        if(a == b) return ; 
        if(sz[a] > sz[b]) swap(a, b) ; 
        sz[b] += sz[a] ; pai[a] = b ; 
        comp-- ; 
    }

} dsu ; 

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    bool notnull = 0 ; 

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 

    comp = n ; 

    for(int i = 1 ; i <= n ; i++){
        int k ; cin >> k ; 
        for(int j = 0 ; j < k ; j++){
            int lg ; cin >> lg ; 
            lng[i][lg] = 1 ; kn[i].push_back(lg) ; 
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(!kn[i].size()) continue ; 
        notnull = 1 ; 
        for(int j = 1 ; j <= n ; j++){
            for(auto a : kn[i]){
                if(lng[j][a]){
                    dsu.join(i, j) ; 
                    break ; 
                }
            }
        }
    }

    if(notnull) cout << comp - 1 << "\n" ;
    else cout << n << "\n" ;

}
