#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e3 + 5 ; 

int n, m, dp[23][23], ind ;
string dic[maxn], s ;

int solve(int i, int j){
    
    if(i < 0) return j + 1 ;
    if(j < 0) return i + 1 ; // preciso arrumar tds da outra 
    
    if(dp[i][j] != -1) return dp[i][j] ;
    
    if(dic[ind][j] == s[i]) return dp[i][j] = solve(i-1, j-1) ;
    
    return dp[i][j] = min(solve(i-1, j-1), min(solve(i-1, j), solve(i, j-1))) + 1 ;
    
}

int main(){

    cin >> n >> m ; 
    
    for(int i = 1 ; i <= n ; i++) cin >> dic[i] ;
    for(int i = 1 ; i <= m ; i++){
        
        cin >> s ;
        
        for(int j = 1 ; j <= n ; j++){ //sou parecido com dic[j] ?
            memset(dp, -1, sizeof dp) ;
            ind = j ;
            int ans = solve(s.size(), dic[j].size()) ;
            if(ans <= 2) cout << dic[j] << " " ; // a minha dif p outra é no max 2?
        }
        
        cout << "\n" ;
        
    }
    
}
