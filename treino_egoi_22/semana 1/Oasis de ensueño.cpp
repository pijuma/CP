// https://www.hackerrank.com/contests/oifem-2021-final-dia-2/challenges/oasis/problem
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e4 + 5 ; 

// dp[i][0/1] -> to em i e n peguei i ou peguei 

int t, n, v[maxn], dp[maxn][3], pai[maxn] ; 
vector<int> grafo[maxn] ; 

int solve(int i, int p, int bb){

    if(dp[i][bb] != -1) return dp[i][bb] ; 

    int ans = 0 ; 

    if(bb){
        ans += v[i] ; 
        for(auto a : grafo[i]){
            if(a == p) continue ; 
            ans += solve(a, i, 0) ; 
        }
    }

    else{
        for(auto a : grafo[i]){
            if(a == p) continue ; 
            ans += max(solve(a, i, 1), solve(a, i, 0)) ; 
        }
    }

    return dp[i][bb] = ans ; 

}

int main(){

    cin >> t ; 

    while(t--){
        
        cin >> n ;

        for(int i = 1 ; i <= n ; i++) cin >> v[i] ; 

        for(int i = 1 ; i < n ; i++){
            int a, b ; cin >> a >> b ;
            a++, b++ ;  
            grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
        }

        memset(dp, -1, sizeof dp) ; 

        int ans = solve(1, 1, 0) ; 

        memset(dp, -1, sizeof dp) ;

        ans = max(ans, solve(1, 1, 1)) ; 

        cout << ans << "\n" ; 

        for(int i = 1 ; i <= n ; i++) grafo[i].clear() ; 
            
    }

}
