/*
Configuração valida para que a proposicao logica no formato 
(p1Up2)^(p3Up2)^.... seja verdade 
*/

#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 2e5 + 5 ; 

int n, m, ct ;
int vis[maxn], comp[maxn] ;
bool ans[maxn] ;   
vector<int> grafo[maxn], grafo_i[maxn] ; 
stack<int> fila ; 

int nega(int x){
    if(x <= m) return x + m ; 
    return x - m ; 
}

/*
p1->p2 
contrapositiva: !p2->!p1
p1->p2 = !p1Up2 
*/

void add_imp(int a, int b){
    grafo[a].push_back(b) ; grafo_i[b].push_back(a) ;
}

void add_or(int p1, int p2){
    add_imp(nega(p1), p2) ;
    add_imp(nega(p2), p1) ;
}

void add_xor(int a, int b){
    add_or(a, b) ; add_or(nega(a), nega(b)) ;    
}

/*
pra forçar algum valor ser verdade adiciona !p -> p 
pra forçar ser falo p->!p
*/

void dfs(int v, int p){

    vis[v] = 1 ; 

    for(auto a : grafo[v]){
        if(vis[a] || a == p) continue ; 
        dfs(a, v) ;  
    }

    fila.push(v) ; 

}

void dfs2(int v, int p){

    comp[v] = ct ; 

    //cout << v << " " << ct << "\n" ; 

    for(auto a : grafo_i[v]){
        if(a == p || comp[a]) continue ; 
        dfs2(a, v) ; 
    }

}

int main(){

    cin >> n >> m ; 

    for(int i = 1 ; i <= n ; i++){
        int p1, p2 ;
        char op, op2 ; cin >> op >> p1 ; 
        cin >> op2 >> p2 ; 
        if(op == '-') p1 = nega(p1) ; 
        if(op2 == '-') p2 = nega(p2) ; 
        add_or(p1, p2) ; 
    }

    for(int i = 1 ; i <= 2*m ; i++){
        if(!vis[i]) dfs(i, i) ;
    }

    while(fila.size()){
        int at = fila.top() ; fila.pop() ; 
        if(comp[at]) continue ; 
        ct++ ; dfs2(at, at) ;
    }

    for(int i = 1 ; i <= m ; i++){
        if(comp[i] == comp[nega(i)]){
            cout << "IMPOSSIBLE\n"; return 0 ; 
        }
        ans[i] = (comp[i] > comp[nega(i)]) ; 
    }

    for(int i = 1 ; i <= m ; i++){
        cout << (ans[i] ? "+ " : "- ") ; 
    }
    
    cout << "\n" ;

} 
