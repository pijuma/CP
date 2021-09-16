#include<bits/stdc++.h>
#define ll long long
using namespace std ; 

const int maxn = 3e5 + 10 ; 
const ll inf = 1e18 + 10 ; 

struct A{
    int a, b ; 
    ll w ; 
} ;

int n, m, k, q ; 
bool mark[maxn] ; 
ll dist[maxn], sz[maxn], subir[maxn] ; 
int pai[maxn], nivel[maxn] ; 
vector<pair<int,ll>> grafo[maxn] ; 
A aresta[maxn] ; 

void dij(){

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> fila ; 

    for(int i = 1 ; i <= n ; i++){
    	dist[i] = inf ; 
    	if(i <= k){
    		dist[i] = 0 ; 
    		fila.push({0ll, i}) ; 
    	}
    }

    while(!fila.empty()){
        
        int at = fila.top().second ; fila.pop() ; 
        
        if(mark[at]) continue ; 
        mark[at] = 1 ; 

        for(auto a : grafo[at]){
            if(dist[a.first] > dist[at] + a.second){
                dist[a.first] = dist[at] + a.second ; 
                fila.push({dist[a.first], a.first}) ;  
            }
        }

    }

    // for(int i = 1 ; i <= n ; i++) cout << dist[i] << " " ; 
    // cout << "\n" ; 

}

bool cmp(A a, A b){ return a.w < b.w ; }

struct DSU{

    int find(int a){ return (a == pai[a] ? a : find(pai[a])) ; }

    void join(int a, int b, ll x){

        a = find(a), b = find(b) ; 

        if(sz[a] > sz[b]) swap(a, b) ; 

        sz[b] += sz[a] ; 
        pai[a] = b ; 
        subir[a] = x ; 

    }

} dsu ; 

int dfs(int v){ 

    if(pai[v] == v) return nivel[v] = 0 ; 
    return nivel[v] = 1 + dfs(pai[v]) ; 

}

ll query(int a, int b){

    ll ans = 0ll ; 

    while(a != b){
        if(nivel[a] > nivel[b]) ans = max(ans, subir[a]), a = pai[a] ;
        else ans = max(ans, subir[b]), b = pai[b] ;  
    }

    return ans ;

}

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> n >> m >> k >> q ; 

    for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 
        
    for(int i = 1 ; i <= m ; i++){
        int a, b, c ; 
        cin >> a >> b >> c ;
        grafo[a].push_back({b, c}), grafo[b].push_back({a, c}) ; 
        aresta[i] = {a, b, c} ;  
    }

    dij() ;

    for(int i = 1 ; i <= m ; i++) aresta[i].w += 1LL*dist[aresta[i].a] + dist[aresta[i].b] ;  

    sort(aresta + 1, aresta + 1 + m, cmp) ; 

    for(int i = 1 ; i <= m ; i++){
        if(dsu.find(aresta[i].a) == dsu.find(aresta[i].b)) continue ; 
        dsu.join(aresta[i].a, aresta[i].b, aresta[i].w) ; 
    }

    for(int i = 1 ; i <= n ; i++) dfs(i) ; 

    // for(int i = 1 ; i <= n ; i++) cout << nivel[i] << " " ; 
    // cout << "\n" ;

    for(int i = 1 ; i <= q ; i++){
        int a, b ; 
        cin >> a >> b ; 
        cout << query(a, b) << "\n" ; 
    }

}
