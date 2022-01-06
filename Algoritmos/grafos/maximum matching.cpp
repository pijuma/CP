//North American Southeast Regional 2019 (Div 1) - swap free - CF - 06/01/2022 
//https://codeforces.com/gym/102423/problem/D

#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e3 + 5 ;

// max matching - berge n - qtd

int n, near[maxn], timer, vis[maxn], verm[maxn], verde[maxn], ans ;
string v[maxn] ;
vector<int> grafo[maxn], match_graph[maxn] ;

bool same_set(int a, int b){

    vector<int> dif ;

    for(int i = 0 ; i < v[a].size() ; i++){
        if(v[a][i] != v[b][i]) dif.push_back(i) ;
    }

    if(dif.size() != 2) return 1 ;

    string neww = v[a] ;
    swap(neww[dif[0]], neww[dif[1]]) ;

    return !(neww == v[b]) ;

}

void dfs_color(int v, int p, int c){

    if(c == 1) verm[v] = 1 ;
    else verm[v] = 0 ;

    for(auto a : grafo[v]){
        if(a == p || verm[a] != -1) continue ;
        dfs_color(a, v, !c) ;
    }

}

bool try_kuhn(int v){

    if(vis[v] == timer) return 0 ;
    vis[v] = timer ;

    for(auto a : match_graph[v]){

        if(near[a] == -1 || try_kuhn(near[a])){
            near[a] = v ;
            return 1 ;
        }

    }

    return 0 ;

}

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue ;
            if(!same_set(i, j)) grafo[i].push_back(j) ;
        }
    }

    //for(int i = 1 ; i <= n ; i++){
      //  for(auto a : grafo[i]){
        //    cout << i << " " << a << "\n" ;
        //}
    //}

    memset(verm, -1, sizeof verm) ;

    for(int i = 1 ; i <= n ; i++){
        if(verm[i] != -1) continue ;
        dfs_color(i, i, 1) ; // quais caras da esquerda e da direita
        // vermelho - esq - 1 / verde - dir
    }

    memset(near, -1, sizeof near) ;

    for(int i = 1 ; i <= n ; i++){
        for(auto j : grafo[i]){
            if(verm[i] && !verm[j]) match_graph[i].push_back(j) ;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(verm[i]){
            ++timer ;
            ans += try_kuhn(i) ;
        }
    }

    cout << n - ans << "\n" ;

}
