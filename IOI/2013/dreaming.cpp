#include<bits/stdc++.h>
#include <dreaming.h>
#define f first
#define s second 
#define pii pair<int,int>

using namespace std ; 

const int maxn = 1e5 + 5 ; 

int new_edge, ind, check[maxn], comp[maxn], l, n, vis[maxn], maior, pai[maxn], m ;
int d1[maxn] ; 
vector<pii> grafo[maxn] ;

void dfs(int v, int p, int c){
    
    comp[c] = v, vis[v] = 1 ; 

    for(pii a : grafo[v]){
        if(a.first == p) continue ; 
        dfs(a.first, v, c) ; 
    }

}

void dfs2(int v, int p, int d){

    for(pii a : grafo[v]){
        
        if(a.f == p) continue ; 
        
        d1[a.f] = d + a.s ;  

        pai[a.f] = v ; 
        
        dfs2(a.f, v, d1[a.f]) ; 

    }

    if(d1[v] > maior) maior = d1[v], ind = v ;

}

int solve(){

    int c = 0 ; 

    for(int i = 0 ; i < n ; i++){
        if(vis[i]) continue ; 
        dfs(i, -1, ++c) ;  
    }   

    int mxdiam = 0, v1 = 0, v2 = 0, v3 = 0 ; 

    for(int i = 1 ; i <= c ; i++){
        maior = 0, ind = comp[i] ; 

        int v = comp[i] ; 

        dfs2(v, -1, 0) ; 

        v = ind ; 
        maior = 0, ind = comp[i], d1[v] = 0, pai[v] = -1 ; 

        dfs2(v, -1, 0) ; 

        mxdiam = max(mxdiam, maior) ; 

        int u = ind, ans = maior, diam = maior ; 

        while(u != -1){
            if(ans > max(d1[u], diam - d1[u])) ans = max(d1[u], diam - d1[u]) ; 
            u = pai[u] ; 
        }  

        if(ans >= v1) v3 = v2, v2 = v1, v1 = ans ; 
        else if(ans >= v2) v3 = v2, v2 = ans ; 
        else if(ans >= v3) v3 = ans ; 

    }

    if(c == 2) return max(mxdiam, v1 + v2 + new_edge) ; 
    else if(c == 1) return mxdiam ; 
    else if(abs(v3-v1) < new_edge) return max({mxdiam, v2 + v3 + (2*new_edge), v1 + v2 + new_edge}) ;
    else return max({mxdiam, v1 + v2 + new_edge}) ; 

}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    // n - n° caras, m - arestas, l - peso das novas arestas, a--t--b 
    
    for(int i = 0 ; i < M ; i++){
        grafo[A[i]].push_back(make_pair(B[i], T[i])) ;
        grafo[B[i]].push_back(make_pair(A[i], T[i])) ;
    }
    
    new_edge = L, n = N, m = M ; 

    // cout << solve() << "\n" ;

    return solve() ; 

}

/*int main(){

    int mat[8]= {0, 8, 2, 6, 11, 5, 1, 1} ;
    int mat2[8] = {8, 2, 7, 10, 5, 1, 9, 3};
    int peso[8] = {4, 2, 4, 3, 3, 7, 5, 1} ; 
    cout << travelTime(12, 8, 2, mat, mat2, peso) << endl;

    return 0;
}*/
