#include<bits/stdc++.h>
using namespace std ;
const int maxn = 1e2 + 10 ;

char grid[maxn][maxn] ;
int dx[4] = {0,0,1,-1} ;
int dy[4] = {1,-1,0,0} ;
int ti,tj,fi,fj,l,c,visitados[maxn][maxn],ini ;

vector < pair<int,int> > fila ;

bool valid( int x, int y ){

    if(x >= 1 && y >= 1 && x <= l && x <= c) return true ;
    else return false ;

}

void bfs( int i , int j ){

    visitados[i][j] = 1 ;

    fila.push_back({i, j}) ;

    int ini = 0 ;
    while(ini < fila.size()){

        int pi = fila[ini].first ;
        int pj = fila[ini].second ;
        ini++ ;

        for(int i = 0 ; i < 4 ; i++){

            int xi = pi + dx[i] ;
            int xj = pj + dy[i] ;

            if(!valid(xi, xj) || visitados[xi][xj] || grid[xi][xj] != 'H') continue ;

            fila.push_back({xi, xj}) ;
            visitados[xi][xj] = 1 ;

        }

    }

    fi = fila[fila.size() - 1].first, fj = fila[fila.size() - 1].second ;

}

int main(){

    cin >> l >> c ;

    for(int i = 1 ; i <= l ; i++){

        for(int j = 1 ; j <= c ; j++){

            cin >> grid[i][j] ;

            if(grid[i][j] == 'o') ti = i, tj = j ;

        }

    }

    bfs(ti, tj) ;

    cout << fi << " " << fj ;

}
