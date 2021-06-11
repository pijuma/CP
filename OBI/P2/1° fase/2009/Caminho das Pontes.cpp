#include<bits/stdc++.h>
using namespace std;
const int inf = 1e6 + 10;

int dist[inf],n,m,s,t,b,mark[inf] ;
vector< pair<int,int> > grafo[inf] ;

void dijkstra ( int f ){

    //marca tudo como inf
    //marca dist[s]=0
    //priority queue em ordem crescente
    //push({0,s});
    //enquanto fila n for vazia
    //guarda o id do q está olhando e da pop
    //se já foi marcado pula se nn olha
    //olha todos os grafos[u] e se
    //a dist[u] for maior q dist[v]+grafos[u][i].first
    //da push em dist[v],v
    // imprime a dist[n+1]

    for( int i = 0 ; i <= n+1 ; i++) dist[i] = inf ;
    dist[f] = 0 ;

    priority_queue< pair <int,int> , vector< pair <int,int> >, greater<pair <int,int> > > fila ;
    fila.push({0,f}) ;
    while(!fila.empty()){

        int u = fila.top().second ;
        fila.pop() ;

        if ( mark[u] ) continue ;

        mark[u] = 1 ;

        for( int i = 0 ; i < grafo[u].size() ; i++){
            int w = grafo[u][i].first ;
            int v = grafo[u][i].second ;
            if ( dist[v] > dist[u] + w ){
                dist[v] = dist[u] + w ;
                fila.push({dist[v],v}) ;
            }
        }
    }
}
int main(){
    cin >> n >> m ;
    //n° cidades e o n° estradas
    //0 onde ele está e n+1 onde quer ir
    for ( int i = 0 ; i < m ; i++){
        cin >> s >> t >> b ;
        grafo[t].push_back({b,s}) ;
        grafo[s].push_back({b,t}) ;
    }
    dijkstra(0) ;
    cout<<dist[n+1] << endl ;
}
