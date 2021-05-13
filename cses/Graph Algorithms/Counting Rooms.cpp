#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 1e3 + 2 ;
 
int n, m, ans ;
char ma[maxn][maxn] ;
 
bool e(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m && ma[i][j] == '.' ; }
 
void dfs(int i, int j){
 
    ma[i][j] = '#' ;
 
    if(e(i-1, j)) dfs(i-1, j) ;
    if(e(i, j-1)) dfs(i, j-1) ;
    if(e(i+1, j)) dfs(i+1, j) ;
    if(e(i, j+1)) dfs(i, j+1) ;
 
}
 
int main(){
 
    cin >> n >> m ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= m ; j++){
 
            cin >> ma[i][j] ;
 
        }
 
    }
 
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = 1 ; j <= m ; j++){
 
            if(e(i,j)) dfs(i,j), ++ans ;
 
        }
 
    }
 
    cout << ans ;
 
}
