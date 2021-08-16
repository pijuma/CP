#include<bits/stdc++.h>
using namespace std ; 
#define int long long 
// consegue subir no max 1, atual <= atual + 1 
// a cada segundo a altura de cada uma aumenta em 1 

const int maxn = 55 ; 
const int inf = 1e9 ;

int dx[5] = {0, 0, 1, -1, 0} ;
int dy[5] = {1, -1, 0, 0, 0} ;

int n, m, dist[maxn][maxn][10], g[maxn][maxn] ;

bool valid(int i, int j){ return i > 0 && j > 0 && i <= n && j <= m ; }

int32_t main(){
    
    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
    
    cin >> n >> m ; 
    
    for(int i = 1 ; i <= n ; i++){
        
        for(int j = 1 ; j <= m ; j++){
            cin >> g[i][j] ;
            for(int k = 0 ; k < 10 ; k++) dist[i][j][k] = inf ; 
        }
        
    }
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> fila ; 
    
    fila.push({0, {1, 1}}) ;
    dist[1][1][0] = 0 ;
    
    while(!fila.empty()){
        
        int ati = fila.top().second.first, atj = fila.top().second.second ;
        int turno = fila.top().first ; 
        fila.pop() ;
        
        for(int i = 0 ; i < 5 ; i++){
            
            int pti = ati + dx[i], ptj = atj + dy[i] ;
            if(!valid(pti, ptj)) continue ;
            if(dist[pti][ptj][(turno+1)%10] <= turno + 1) continue ;
            if((g[ati][atj] + turno)%10 + 1 >= (g[pti][ptj] + turno + 10)%10){
                dist[pti][ptj][(turno+1)%10] = turno + 1 ;
                fila.push({turno + 1, {pti, ptj}}) ; 
            }
            
        }
        
    }
    
    int mn = dist[n][m][0] ;
    
    for(int i = 1 ; i < 10 ; i++) mn = min(mn, dist[n][m][i]) ;
    
    cout << mn << "\n" ;
    
}
