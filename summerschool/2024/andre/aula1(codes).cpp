#include<bits/stdc++.h>
using namespace std ; 

// low link padrao p achar ponte 
// pode ter multiple edges 
int tin[maxn], tout[maxn], vis[maxn], timer, low[maxn] ; 
vector<int> grafo[maxn], ar[maxn] ; 

void find_b(int v, int p){

    tin[v] = low[v] = ++timer ; 

    for(int i = 0 ; i < grafo[v].size() ; i++){
        int kra = grafo[v][i], id = ar[v][i] ; 
        if(vis[id]) continue ; 
        vis[id] = 1 ; 
        if(tin[kra]){// vou usar bk edge (uma vez apenas)
            low[v] = min(low[v], tin[kra]) ; continue ; 
        }
        find_b(kra, v) ; 
        low[v] = min(low[v], low[kra]) ;
    }

    if(v != 1 && low[v] == tin[v]) resp.push_back({v, p}) ; // de v pra p eh uma ponte 

}

//grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
//ar[a].push_back(i) ; ar[b].push_back(i) ; 

// tarjan pra achar bridge tree
// toda vez que acha uma ponte limpa a pilha até chegar no cara ou ficar vazia
// esses caras tao na msm componente 
// cada componente eh 2 edge connected = quaisquer 2 vertices tem 2 caminhos 
// disjuntos em arestas
int pilha[maxn], c, comp[maxn];
int p = -1 ; 

void find_b(int v, int p){

    tin[v] = low[v] = ++timer ; 
    pilha[++p] = v ; 

    for(int i = 0 ; i < grafo[v].size() ; i++){
        int kra = grafo[v][i], id = ar[v][i] ; 
        if(vis[id]) continue ; 
        vis[id] = 1 ; 
        if(tin[kra]){// vou usar bk edge (uma vez apenas)
            low[v] = min(low[v], tin[kra]) ; continue ; 
        }
        find_b(kra, v) ; 
        low[v] = min(low[v], low[kra]) ;
    }

    if(low[v] == tin[v]){// achou uma ponte = limpa pilha 
        c++ ; int vrt ; 
        while(1){
            if(p == -1) break ; 
            vrt = pilha[p] ; 
            comp[vrt] = c ; 
            p-- ;
            if(vrt == v) break ; 
        }
    }
}

// ponto de articulacao - se tirar aumenta a qtd
// de componentes conexas - qd tem um cara que o low dele 
// é >= ao tin do meu atual (n consegue subir=se eu tirar v desconecta)
// logo v eh ponto de articulacao 
// raiz só eh se tiver +1 filho

void find_art(int v, int p){
    
    tin[v] = low[v] = ++timer ; 
    
    int child = 0 ; bool pto = 0 ; 

    for(int i = 0 ; i < grafo[v].size() ; i++){
        int id = ar[v][i], kra = grafo[v][i] ;
        if(vis[id]) continue ; 
        vis[id] = 1 ; 
        if(tin[kra]){
            low[v] = min(low[v], tin[kra]) ; continue ; 
        }
        find_art(kra, v) ; 
        if(low[kra] >= tin[v]) pto = 1 ; 
        low[v] = min(low[v], low[kra]); child++ ; 
    }

    if(v == 1 && child > 1) art.pb(v) ; 
    if(v != 1 && pto) art.pb(v) ; 

}

//biconnected component - 2 vertex connected -> n tem pto 
// de articulacao 
// seleciona um conjunto maximal de arestas tal que o grafo 
// induzido n tem nenhum pto de articulacao 
// 2 componentes podem ter o mesmo vertice (pois eh nas arestas)
// pontes sao biconnected components isoladas
// dados 2 vertices existem smp 2 caminhos disjuntos de vertice no min 
// quaisquer 2 arestas existem um ciclo simples q contem elas
// p achar faz pilha de arestas, qd chega num pto de art remove tudo 
// e guarda a componente 
// ao final desempilha TUDO 
// na pilha salva o id das arestas 

void nova_comp(int id){
    c++ ; 
    while(1){
        int vrt = pilha[p] ; p-- ; 
        comp[a] = c ; 
        if(p==-1 || vrt == id) break ; 
    }
}

void dfs(int v, int p){

    tin[v] = low[v] = ++timer ; 
    int child = 0 ; 

    for(int i = 0 ; i < grafo[v].size() ; i++){
        int id = ar[v][i], kra = grafo[v][i] ;
        if(vis[id]) continue ; 
        vis[id] = 1 ; 
        p++ ; pilha[p] = v ; 
        if(tin[kra]){
            child++ ; 
            dfs(kra, v) ; 
            low[v] = min(low[v], low[kra]) ;
            bool new_comp = 0 ; 
            if(v==1 && child > 1) new_comp = 1 ; 
            if(v != 1 && low[kra] >= tin[v]) new_comp = 1 ; 
            if(new_comp){
                pto_art[v] = 1 ; 
                nova_comp(id) ;
            }
            continue ; 
        } 
        low[v] = min(low[v], tin[kra]) ; 
    }   
}
// p = -1 c = 0 dfs(1, 0) nova_comp(-1) - no final p limpar a pilha

// blocked-cut tree 
// resume as arestas da biconnected e liga sempre a um ponto de articulacao 

for(int i = 1 ; i <= n ; i++){

    if(pto_art[i] != 1) continue ; 

    c++ ; 
    pto_art[i] = c ; 

    for(int j = 0 ; j < ar[i].size())
}
