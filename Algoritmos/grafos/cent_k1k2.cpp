struct BIT{
 
    void upd(int pos, int val){
        for(; pos < maxn ; pos += pos&-pos) bit[pos] += val ; 
    }
 
    int query(int l, int r){
 
        int tot = 0 ; l-- ; 
 
        for(; r > 0 ; r -= r&-r) tot += bit[r] ;
        if(l) for( ; l > 0 ; l -= l&-l) tot -= bit[l] ; 
        
        return tot ; 
       
    }
 
} Bit ; 
 
void dfs(int v, int p){
    sz[v] = 1 ; 
    for(auto a : grafo[v]){
        if(a == p || vis[a]) continue ; 
        dfs(a, v) ; 
        sz[v] += sz[a] ; 
    }
}
 
int find_cent(int v, int p, int szz){
    for(auto a : grafo[v]){
        if(vis[a] || a == p || 2*sz[a] <= szz) continue ;
        return find_cent(a, v, szz) ; 
    }
    return v ; 
}
 
void add(bool t, int v, int p, int lvl){
 
    if(lvl > k2) return ; 
 
    mx_lvl = max(mx_lvl, lvl) ; 
 
    if(t) ans += Bit.query(max(1LL, k1 - lvl + 1), k2 - lvl + 1); 
    else Bit.upd(lvl + 1, 1LL) ; 
 
    for(auto a : grafo[v]){
        if(vis[a] || a == p) continue ; 
        add(t, a, v, lvl + 1) ; 
    }
 
}
 
void make_graph(int v, int p){
 
    dfs(v, p) ; 
    int cent = find_cent(v, p, sz[v]) ; 
    vis[cent] = 1 ; 
 
    mx_lvl = 0 ;
    Bit.upd(1LL, -Bit.query(1, 1) + 1LL) ;  
 
    for(auto a : grafo[cent]){
        if(vis[a] || a == cent) continue ; 
        add(1, a, cent, 1LL) ;
        add(0, a, cent, 1LL) ;  
    }
 
    for(int i = 1 ; i <= mx_lvl ; i++) Bit.upd(i+1, -Bit.query(i+1, i+1)) ; 
 
    for(auto a : grafo[cent]){
        if(vis[a] || a == cent) continue ; 
        make_graph(a, cent) ; 
    }
 
}
 
int main(){
 
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
 
    cin >> n >> k1 >> k2 ; 
 
    for(int i = 1 ; i < n ; i++){
        int a, b ; cin >> a >> b ; 
        grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
    }
 
    make_graph(1, 0) ; 
 
    cout << ans << "\n" ; 
 
}
