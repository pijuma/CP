    #include<bits/stdc++.h>
     
    #define esq (2*no)
    #define dir ((2*no)+1)
    #define meio ((i+j)>>1)
    #define f first 
    #define s second 
    #define ll long long 
     
    using namespace std ; 
     
    const int maxn = 3e5 + 1 ; 
     
    struct Q{
        char tipo ;
        int a, b ; 
    } ; 
     
    struct intervalo{
        int a, b, l, r ; 
    } ; 
     
    int n, k ;
    char type ; 
    Q query[maxn] ; 
    int sz[maxn], pai[maxn], qtd, ans[maxn] ;
    map<pair<int,int>,int> abre ;  
    vector<intervalo> inter ; 
    vector<pair<int,int>> last ;
    vector<int> comp ; 
    vector<pair<int,int>> tree[(1<<20)] ; 
     
    struct DSU{
     
        int find(int u){ return u == pai[u] ? u : find(pai[u]) ; }
     
        void join(int a, int b){
     
            a = find(a), b = find(b) ; 
     
            if(a == b){
                last.push_back({-1,-1}), comp.push_back(-1) ; 
                return ; 
            } 
     
            if(sz[a] > sz[b]) swap(a, b) ; // b smp vira pai 
     
            last.push_back({b, a}), comp.push_back(qtd) ; //add a no b 
            pai[a] = b ; 
            sz[b] += sz[a] ; 
            qtd-- ; 
     
        }
     
        void rollback(){
            
            int u = last.back().first, v = last.back().second, qtd_comp = comp.back() ; 
            
            if(u == -1 && v == -1 && qtd_comp == -1){
                last.pop_back(), comp.pop_back() ; 
                return ; 
            }
     
            qtd = qtd_comp ;
            pai[v] = v ; 
            sz[u] -= sz[v] ; 
            last.pop_back(), comp.pop_back() ; 
     
        }
     
        int qtd_comp(){ return qtd ; }
     
    }dsu ; 
     
    struct SEG{
     
        void att(int no, int i, int j, int a, int b, pair<int,int> ar){
            
            if(a > j || b < i) return ; 
            
            if(a <= i && b >= j){
                tree[no].push_back(ar) ; 
                return ; 
            }
     
            att(esq, i, meio, a, b, ar), att(dir, meio + 1, j, a, b, ar) ; 
     
        }
     
        /*void see(){
            for(int i = 1 ; i < 4*k ; i++){
                for(int j = 0 ; j < tree[i].size() ; j++){
                    cout << i << " " << tree[i][j].first << " " << tree[i][j].second << "\n" ; 
                }
            }
        }*/
     
    } seg ; 
     
    void dfs(int no, int i, int j){
     
        for(int k = 0 ; k < tree[no].size() ; k++) dsu.join(tree[no][k].first, tree[no][k].second) ; 
     
        if(i == j) ans[i] = dsu.qtd_comp() ; 
        
        else{
     
            dfs(esq, i, meio) ; dfs(dir, meio + 1, j) ; 
        
        }
     
        for(int k = 0 ; k < tree[no].size() ; k++) dsu.rollback() ; 
     
    }
     
    int main(){
     
        ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
        freopen("connect.in", "r", stdin);
        freopen("connect.out", "w", stdout);
     
        cin >> n >> k ; 
     
        if(!k) return 0 ; 
     
        for(int i = 1 ; i <= k ; i++){
            
            cin >> type ; 
            
            if(type == '?') query[i].a = query[i].b = 0, query[i].tipo = type ; 
            
            else{
                int u, v ; 
                cin >> u >> v ; 
                if(u > v) swap(u, v) ; 
                query[i].a = u, query[i].b = v, query[i].tipo = type ; 
                abre[{query[i].a, query[i].b}] = 0 ; 
            }
     
        }
     
        for(int i = 1 ; i <= k ; i++){
     
            if(query[i].tipo == '?') continue ; 
     
            else if(query[i].tipo == '+' && abre[{query[i].a, query[i].b}] == 0) abre[{query[i].a, query[i].b}] = i ; 
            //else if(query[i].tipo == '+' && abre[{query[i].a, query[i].b}] != 0) continue ; 
            else if(query[i].tipo == '-' && abre[{query[i].a, query[i].b}] != 0){
                intervalo atual ; 
                atual.a = query[i].a, atual.b = query[i].b, atual.l = abre[{query[i].a, query[i].b}], atual.r = i - 1 ; 
                inter.push_back(atual) ;
                abre[{query[i].a, query[i].b}] = 0 ; 
            } 
        
        }
     
        for(int i = 1 ; i <= k ; i++){
            
            if(query[i].tipo == '?') continue ; 
            if(abre[{query[i].a, query[i].b}] == 0) continue ; 
            intervalo atual ; 
            atual.a = query[i].a, atual.b = query[i].b, atual.l = abre[{query[i].a, query[i].b}], atual.r = k ; 
            inter.push_back(atual), abre[{query[i].a, query[i].b}] = 0 ;    
        
        }
     
        for(int i = 1 ; i <= n ; i++) pai[i] = i, sz[i] = 1 ; 
     
        qtd = n ; 
        
        //for(int i = 0 ; i < inter.size() ; i++) cout << inter[i].s.f << " " << inter[i].s.s << " " << inter[i].f.f << " " << inter[i].f.s << "\n" ; 
        
        for(int i = 0 ; i < inter.size() ; i++){
     
            int ini = inter[i].l, fim = inter[i].r ;
            int a = inter[i].a, b = inter[i].b ;  
     
            seg.att(1, 1, k, ini, fim, make_pair(a, b)) ; 
     
        }
        
        //seg.see() ; 
     
        dfs(1, 1, k) ; 
     
        for(int i = 1 ; i <= k ; i++){
            
            if(query[i].tipo == '?') cout << ans[i] << "\n" ; 
     
        }
     
    }
