#include<bits/stdc++.h>
 
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)
 
#define int long long
using namespace std ;
 
const int maxn = 2e5 + 5 ;
 
int n, k ;
int q, tin[maxn], tout[maxn], bit[maxn], x[maxn] ;
vector<int>grafo[maxn] ;
int timer ;
int t, s, val ;
 
void att(int pos, int v){
    for( ; pos <= maxn ; pos += pos&-pos) bit[pos] += v ;
}
 
int query(int pos){
    int r = 0 ;
    for( ; pos ; pos -= pos&-pos) r += bit[pos] ;
    return r ;
}
 
void dfs(int v, int p){
    tin[v] = ++timer ;
    att(tin[v], x[v]) ;
    for(int a : grafo[v]){
        if(a == p) continue ;
        dfs(a, v) ;
    }
    tout[v] = timer ;
}
 
int32_t main(){
 
    cin >> n >> q ;
 
    for(int i = 1 ; i <= n ; i++) cin >> x[i] ;
 
    for(int i = 1 ; i < n ; i++){
        int a, b ;
        cin >> a >> b ;
        grafo[a].push_back(b), grafo[b].push_back(a) ;
    }
 
    dfs(1, -1) ;
 
    while(q--){
        cin >> t ;
        if(t == 1){
            cin >> s >> val ;
            att(tin[s], val - x[s]) ;
            x[s] = val ;
        }
        else{
            cin >> s ;
            cout << query(tout[s]) - query(tin[s]-1) << "\n" ;
        }
 
    }
 
}
