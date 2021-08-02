#include<bits/stdc++.h>
using namespace std;

int px[4] = {1, -1, 0, 0};
int py[4] = {0, 0, 1, -1};
int n ;
bool valid(int a, int b){
       return (a>=0 && a<n && b>=0 && b<n) ;
}
    
int main(){
    int mina[110][110], visit[110][110], dist[110][110];
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mina[i][j];
            dist[i][j] = 0;
            visit[i][j] = 0;
        }
    }

    deque<pair<int,int>>fila ; 
    fila.push_back(make_pair(0, 0)) ; 
    while(!fila.empty()){
        int ox = fila.front().first;
        int oy = fila.front().second;
        fila.pop_front();
 
        for(int i = 0; i < 4; i++){
            int nx = ox + px[i];
            int ny = oy + py[i];
            if(valid(nx, ny) && visit[nx][ny] == 0){
                if(mina[nx][ny] == 1){
                    visit[nx][ny] = 1 ; 
                    dist[nx][ny] = dist[ox][oy] + 1;
                    fila.push_back(make_pair(nx, ny));
                } else{
                    visit[nx][ny] = 1 ; 
                    dist[nx][ny] = dist[ox][oy];
                    fila.push_front(make_pair(nx, ny));
                }
            }
        }
    }
    cout << dist[n-1][n-1];
}
