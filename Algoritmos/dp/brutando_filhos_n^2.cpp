//truque 7 cf 
// O(N^2)
//qts maneiras de distribuir k macacos na arvore 
// de tal forma que eles sempre formem uma unica componente
const int inf = 1e18 + 2 ; 
 
const int maxn = 1e3 + 5 ; 
const int mod = 1e9 + 7 ; 
 
int n ; 
int dp[maxn][maxn], sz[maxn] ; 
vector<int> grafo[maxn] ; 
 
void solve_dp(int v, int p){
 
 
    dp[v][1] = dp[v][0] = 1 ;
    sz[v] = 1 ; 
 
    for(auto a : grafo[v]){
        if(a == p) continue ; 
        solve_dp(a, v) ;
        vector<int> aux(sz[v]+sz[a]+1, 0) ; 
        //cout << v << " " << a << " " << sz[a] << " " << sz[v] << "\n" ; 
        for(int x = 1 ; x <= sz[v] ; x++){
            for(int y = 0 ; y <= sz[a] ; y++){
                //cout << "fazer " << x + y << " " << x << " " << y << " " << dp[v][x] << " " << dp[a][y] << "\n" ; 
                aux[x+y] = (aux[x+y] + (dp[v][x]*dp[a][y])%mod)%mod ;
            }
        }
        //cout << a << " " << v << "\n" ; 
        for(int i = 1 ; i <= sz[v] + sz[a] ; i++) dp[v][i] = aux[i] ; 
        //for(int i = 1 ; i <= sz[v] + sz[a] ; i++) cout << dp[v][i] << " "  ;
        //cout << "\n" ; 
        sz[v] += sz[a] ; 
    }
 
}
 
void solve(){
 
    cin >> n ; 
 
    for(int i = 2 ; i <= n ; i++){
        int p ; cin >> p ; p++ ; 
        grafo[p].pb(i) ; grafo[i].pb(p) ; 
    }
 
    solve_dp(1, 1) ;
 
    for(int i = 1 ; i <= n ; i++){
        int ans = 0 ; 
        for(int j = 1 ; j <= n ; j++){
            ans = (ans + dp[j][i])%mod ; 
        }
        cout << ans << "\n" ; 
    }
 
}
