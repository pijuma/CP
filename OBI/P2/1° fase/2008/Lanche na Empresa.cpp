#include<bits/stdc++.h>
using namespace std ;

const int inf = 2e4 + 10 ;
const int maxn = 300 ;
int s, c, dist[maxn], menor, ans, mark[maxn], a, b, d ;

vector<int> r ;
vector< pair<int,int> > grafo[maxn] ;

void dij(int x){

    for(int i = 1 ; i <= s ; i++) dist[i] = inf, mark[i] = -1 ;

    dist[x] = 0 ;

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > fila ;

    fila.push({0, x}) ;
    ans = 0 ;

    while(!fila.empty()){

        int u = fila.top(). second ;

        fila.pop() ;

        for(int i = 0 ; i < grafo[u].size() ; i++){

            int v = grafo[u][i]. second ;
            int p = grafo[u][i].first ;

            if(dist[v] > dist[u] + p){

                dist[v] = dist[u] + p ;
                fila.push({dist[v], v}) ;

            }

        }

    }



    for(int i = 1 ; i <= s ; i++){

        if(dist[i] == inf) continue ;

        if(dist[i] > ans) ans = dist[i] ;

    }

    if(menor >= ans) menor = ans ;
}

int main(){

    menor = inf ;

    cin >> s >> c ;

    for(int i = 1 ; i <= c ; i++){

        cin >> a >> b >> d;

        grafo[a].push_back({d, b}) ;
        grafo[b].push_back({d, a}) ;

    }

    for(int i = 1 ; i <= s ; i++) dij(i) ;

    cout << menor ;
}
