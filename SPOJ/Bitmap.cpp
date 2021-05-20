    #include<bits/stdc++.h>
    using namespace std ; 
     
    const int maxn = 184 ; 
     
    int dx[4] = {0,0,1,-1} ; 
    int dy[4] = {1,-1,0,0} ;
     
    string s ; 
    int t, m, n ;
    int ma[maxn][maxn], d[maxn][maxn] ; 
     
    queue< pair<int,int> > fila ; 
     
    bool valid(int i, int j){ return i >= 0 && j < m && i < n && j >= 0 ; }
     
    int main(){
        
        cin >> t ; 
        
        while(t--){
            
            cin >> n >> m ; 
            
            for(int i = 0 ; i < n ; i++){
                
                for(int j = 0 ; j < m ; j++){
                    
                    d[i][j] = -1 ; 
                    
                }
                
            }
            
            for(int i = 0 ; i < n ; i++){
                
                cin >> s ; 
                
                for(int j = 0 ; j < (int)s.size() ; j++){
                    
                    ma[i][j] = s[j] - '0' ; 
                    
                    if(ma[i][j] == 1) fila.push({i,j}), d[i][j] = 0 ; 
                    
                }
                
                
            }
            
            while(!fila.empty()){
                
                int vx = fila.front().first ; 
                int vy = fila.front().second ; 
                
                fila.pop() ;
                
                for(int i = 0 ; i < 4 ; i++){
                    
                    int atx = vx + dx[i] ;
                    int aty = vy + dy[i] ;
                    
                    if(!valid(atx,aty) || ma[atx][aty] == 1 || d[atx][aty] != -1) continue ; 
                    
                    fila.push({atx,aty}) ; 
                    d[atx][aty] = d[vx][vy] + 1 ;
                    
                }
                
            }
            
            for(int i = 0 ; i < n ; i++){
                
                for(int j = 0 ; j < m ; j++){
                    
                    cout << d[i][j] << " ";
                    
                }
                
                cout << endl ;
                
            }
            
            cout << endl ;
            
            
        }
        
    } 
