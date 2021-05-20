#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 1e3 + 1 ;
const int inf = 1e7 ;
 
int t, r, c ;
int d[maxn][maxn] ;
bool check[maxn][maxn] ;
char g[maxn][maxn] ;
string s ;
 
int dx[4] = {0,0,1,-1} ;
int dy[4] = {1,-1,0,0} ;
 
bool valid(int i, int j){ return i >= 0 && j >= 0 && i < r && j < c;}
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> t ;
 
    while(t--){
 
        cin >> r >> c ;
 
        for(int i = 0 ; i < r ; i++){
 
            cin >> s ;
 
            for(int j = 0 ; j < c ; j++){
 
                g[i][j] = s[j] ;
                d[i][j] = inf ;
                check[i][j] = 0 ;
 
            }
 
        }
 
        deque< pair<int,int> > fila ;
        d[0][0] = 0 ;
        fila.push_back(make_pair(0,0)) ;
 
        while(!fila.empty()){
 
            int vx = fila.front().first ;
            int vy = fila.front().second ;
 
            fila.pop_front() ;
 
            if(check[vx][vy]) continue ;
            check[vx][vy] = 1 ;
 
            for(int i = 0 ; i < 4 ; i++){
 
                int cx = vx + dx[i] ;
                int cy = vy + dy[i] ;
 
                if(!valid(cx,cy)) continue ;
 
                if(g[cx][cy] == g[vx][vy]){
 
                    if(d[cx][cy] <= d[vx][vy]) continue ;
 
                    d[cx][cy] = d[vx][vy] ;
                    fila.push_front(make_pair(cx,cy)) ;
 
                }
 
                if(g[cx][cy] != g[vx][vy]){
 
                    if(d[cx][cy] <= d[vx][vy] + 1) continue ;
 
                    d[cx][cy] = d[vx][vy] + 1 ;
                    fila.push_back(make_pair(cx,cy)) ;
 
                }
 
            }
 
        }
 
        cout << d[r-1][c-1] << endl ;
    }
 
}
