#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, ct ; 
int vis[maxn], comp[maxn], ini[maxn] ; 
vector<int> grafo[maxn], grafo_i[maxn] ;
vector<int> tog[maxn] ;
stack<int> fila ; 

int nega(int x){
    if(x <= m) return x + m ; 
    return x - m ; 
}

void add_imp(int a, int b){
    grafo[a].push_back(b) ; 
    grafo_i[b].push_back(a) ;
}

void add_or(int a, int b){
    add_imp(nega(a), b) ; add_imp(nega(b), a) ; 
}

void add_xor(int a, int b){
    add_or(a, b) ; add_or(nega(a), nega(b)) ;
}

void dfs2(int v, int p){

    comp[v] = ct ; 

    for(auto a : grafo_i[v]){
        if(a == p || comp[a]) continue ; 
        dfs2(a, v) ; 
    }

}

void dfs(int v, int p){

    vis[v] = 1 ; 

    for(auto a : grafo[v]){
        if(a == p || vis[a]) continue ; 
        dfs(a, v) ; 
    }

    fila.push(v) ; 

}

int main(){

    cin >> n >> m ; 

    for(int i = 1 ; i <= n ; i++) cin >> ini[i] ; 

    for(int i = 1 ; i <= m ; i++){
        int a ; cin >> a ; 
        for(int j = 1 ; j <= a ; j++){ // porta j controla b
            int b ; cin >> b ; 
            tog[b].push_back(i) ;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int p1 = tog[i][0], p2 = tog[i][1] ; 
        //cout << p1 << " " << p2 << "\n"  ;
        if(ini[i]){// aberta
            add_imp(p1, p2) ; add_imp(nega(p2), nega(p1)) ; 
            add_imp(p2, p1) ; add_imp(nega(p1), nega(p2)) ; 
        }
        else{
            add_xor(p1, p2) ;
        }
    }

    for(int i = 1 ; i <= 2*m ; i++) if(!vis[i]) dfs(i, i) ; 

    while(!fila.empty()){
        int at = fila.top() ; fila.pop() ; 
        if(comp[at]) continue ; 
        ct++ ; dfs2(at, at) ; 
    }

    for(int i = 1 ; i <= m ; i++){
        if(comp[i] == comp[nega(i)]){
            cout << "NO\n" ; return 0 ; 
        }
    }

    cout << "YES\n" ;

}
