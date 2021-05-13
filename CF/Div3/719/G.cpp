    #include<bits/stdc++.h>
     
    #define ll long long 
    #define pb push_back
    #define mk make_pair
    #define ff first 
    #define ss second 
    #define pii pair<int,int> 
    #define pil pair<ll, ll>
    #define myheap priority_queue<pii, vector<pii>, greater<pii>>
     
    using namespace std ; 
     
    const int mod = 1e9 + 7 ;
    const int maxn = 2e3 + 5 ; 
    const int inf = 1e9 ; 
    const ll INF = 1e16 ; 
     
    long long n, m, w, grid[maxn][maxn] ; 
    long long dist[maxn][maxn][2] ; 
     
    // pega 1x o portal 
    // pode usar 1x ou n usar 
     
    int dx[4] = {0, 0, 1, -1} ; 
    int dy[4] = {1, -1, 0, 0} ; 
     
    bool valid(int x, int y, int k){ return x > 0 && y > 0 && x <= n && y <= m && grid[x][y] != -1 && dist[x][y][k] == INF ; }
     
    void bfs(int x, int y, int k){
     
    	queue<pair<int,int>> fila ;
    	dist[x][y][k] = 0 ;  
    	fila.push({x, y}) ; 
     
    	while(!fila.empty()){
    		int tx = fila.front().first, ty = fila.front().second ;
    		fila.pop() ; 
    		for(int i = 0 ; i < 4 ; i++){
    			int vx = tx + dx[i], vy = ty + dy[i] ; 
    			if(!valid(vx, vy, k)) continue ; 
    			dist[vx][vy][k] = dist[tx][ty][k] + 1 ; 
    			fila.push({vx, vy}) ; 
    		} 
     
    	}
     
    }
     
    void solve(){
     
    	cin >> n >> m >> w ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= m ; j++){
    			cin >> grid[i][j] ; 
    			dist[i][j][1] = dist[i][j][0] = INF ; 
    		}
    	}
     
    	bfs(1, 1, 0) ; // qto o 1, 1 alcança?
    	bfs(n, m, 1) ; // qto o n, m alcança?
     
    	long long ans = dist[n][m][0] ; 
     
    	if(ans < INF) ans = ans*w ; 
     
    	vector<long long> d1, d2 ; 
     
    	for(int i = 1 ; i <= n ; i++){
    		for(int j = 1 ; j <= n ; j++){
    			if(grid[i][j] == -1 || grid[i][j] == 0) continue ; 
    			if(dist[i][j][0] < INF){ // alcança 
    				d1.push_back(dist[i][j][0]*w + grid[i][j]) ; 
    			}
    			if(dist[i][j][1] < INF){
    				d2.push_back(dist[i][j][1]*w + grid[i][j]) ; 
    			}
    		}
    	} 
     
    	sort(d1.begin(), d1.end()), sort(d2.begin(), d2.end()) ; 
     
    	if(d2.empty() || d1.empty()){
    		if(ans == INF) cout << "-1\n" ; 
    		else cout << ans << "\n" ; 
    		return ; 
     	}
     
    	ans = min(ans, d1[0]+d2[0]) ; 
    	cout << ans << "\n" ; 
     
    	return ; 
     
    }
     
    int main(){
     
    	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
     
    	int t ; 
     
    	// cin >> t ; 
    	t = 1 ; 
     
    	while(t--) solve() ; 
     
    }
