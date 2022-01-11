#include<bits/stdc++.h>
using namespace std ;

// 1 - dir
// 2 - esq
// 3 - baixo

const int maxn = 3e3 + 5 ;

int n, m, g[maxn][maxn], dp[maxn][maxn][4] ;
// dp[i][j][last mov.]

int solve(int i, int j, int dir){

    // casos base:
    if(i > n || j > m || i <= 0 || j <= 0) return -(0x3f3f3f3f) ;
    if(i == n && j == m) return g[i][j] ;
    // n recalc:
    if(dp[i][j][dir] != -1) return dp[i][j][dir] ;
    //ultimo direita - n pode esq
    if(dir == 1) return dp[i][j][dir] = max(solve(i+1, j, 3), solve(i, j+1, dir)) + g[i][j] ;
    // ultimo esq - n pode dir (1)
    else if(dir == 2) return dp[i][j][dir] = max(solve(i+1, j, 3), solve(i, j-1, dir)) + g[i][j] ;
    else return dp[i][j][dir] = max({solve(i+1, j, dir), solve(i, j-1, 2), solve(i, j+1, 1)}) + g[i][j] ;

}

int main(){

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> g[i][j] ;
        }
    }

    memset(dp, -1, sizeof dp) ;

    cout << max(solve(1, 1, 1), solve(1, 1, 3)) << "\n" ; // mlr começar na 1,1 indo p baixo ou p lado ?
}
