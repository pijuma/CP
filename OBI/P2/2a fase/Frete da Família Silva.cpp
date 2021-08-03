//min valor p custear
//a ida de tds os silvas
//como estão em vertices
//dieferentes queremos apenas que
//o menor custo para de um vertice chegar
//a qualquer outro == árvore geradora minima
//ordenamos os arestas pelo peso
//p olhar para as arestas de menor peso antes
//já q queremos o min
//sempre q um vertice estiver em componente
//diferente do outro une
//e acrescenta na arvore
//ja q em componentes iguais é claro q já há
//um caminho para esse ent n precisamos de outro
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e3 + 10 ;
const int maxm = 1e4 + 10 ;

struct aresta{

    int peso ;
    int u, v ;

};

bool cmp(aresta x, aresta y){ return x.peso < y.peso ;}

aresta grafo[maxm] ;
aresta mst[maxm] ;
int pai[maxn], peso[maxn], n, m, pes ;

int find(int x){

    if(pai[x] == x) return x ;
    return pai[x] = find(pai[x]) ;

}

void join(int a, int b){

    a = find(a) ;
    b = find(b) ;

    if(peso[a] > peso[b]) pai[b] = a ;
    else if(peso[a] < peso[b]) pai[a] = b ;
    else{
        pai[a] = b ;
        peso[b]++ ;
    }
}

int main(){

    cin >> n >> m ;

    for(int i = 1 ; i <= m ; i++){
        cin >> grafo[i].u >> grafo[i].v >> grafo[i].peso ;
     }

     for(int i = 0 ; i < n ; i++) pai[i] = i ;
     sort(grafo + 1, grafo + 1 + m, cmp) ;

     int size = 0 ;

     for(int i = 1 ; i <= m ; i++){

            int l = grafo[i].u, r = grafo[i].v ;

            if(find(l) != find(r)){
                join(l,r) ;
                mst[++size] = grafo[i] ;
            }
     }

     for(int i = 1 ; i < n ; i++) pes += mst[i].peso ;

     cout << pes << endl ;
}
