#include<bits/stdc++.h>
#define int long long
#define esq (2*no)
#define dir ((2*no)+1)
#define meio ((i+j)>>1)

using namespace std ;

const int maxn = 1e5 + 5 ;

int n, nivel_tec[maxn], vis[maxn], tin[maxn], tout[maxn], timer, tree[4*maxn] ;
vector<int> nivel[maxn], grafo[maxn] ;

// preenche de baixo p cima e começa pelos que tem menor nivel_tec 
// assim um cara x tem q ganhar o max q os filhos dele ganham + 1 ou qto o kra anterior 
// ganha +1 (como estamos processando pelo menor nivel_tec, o anterior tem menos) 

void dfs(int v, int p, int lvl){

    tin[v] = ++timer ;
    nivel[lvl].push_back(v) ;
    vis[v] = 1 ;

    for(auto a : grafo[v]){
        if(vis[a] || a == p) continue ;
        dfs(a, v, lvl + 1) ;
    }

    tout[v] = timer ;

}

bool cmp(int a, int b){return nivel_tec[a] < nivel_tec[b] ; }

struct SEG{

    void upd(int no, int i, int j, int pos, int val){
        if(i == j){
            tree[no] = val ;
            return ;
        }
        if(pos <= meio) upd(esq, i, meio, pos, val) ;
        else upd(dir, meio + 1, j, pos, val) ;
        tree[no] = max(tree[esq], tree[dir]) ;
    }

    int query(int no, int i, int j, int a, int b){
        if(i > b || j < a) return 0 ;
        if(i >= a && b >= j) return tree[no] ;
        return max(query(esq, i, meio, a, b), query(dir, meio + 1, j, a, b)) ;
    }

} seg ;

int32_t main(){

    cin >> n ;

    for(int i = 2 ; i <= n ; i++){
        int x ;
        cin >> x ;
        grafo[i].push_back(x), grafo[x].push_back(i) ;
    }

    for(int i = 1 ; i <= n ; i++) cin >> nivel_tec[i] ;

    dfs(1, 1, 1) ;

    for(int i = 1 ; i <= n ; i++) sort(nivel[i].begin(), nivel[i].end(), cmp) ;

    int resp = 0 ;

    for(int i = n ; i > 0 ; i--){

        int prev = 0LL ;

        for(auto a : nivel[i]){
            int att = seg.query(1, 1, n, tin[a], tout[a]) ;
            att = max(att, prev) + 1 ;
            resp += att ;
            prev = att ;
            seg.upd(1, 1, n, tin[a], att) ;
        }

    }

    cout << resp << "\n" ;

}
