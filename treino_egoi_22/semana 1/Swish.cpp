// https://www.hackerrank.com/contests/oifem-2021-final-dia1/challenges/swish/problem
// cria grafo com as cores 
// faz maior ciclo com essas cores
#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e3 + 5 ; 

int n, t, vis[maxn], ans, dp[40], ck[40][40] ; 
string pec[maxn] ; 
vector<int> grafo[maxn] ; 

void dfs(int r, int v, int p){

    vis[v] = 1 ; 

    for(auto a : grafo[v]){
        if(vis[a]){
            if(r == a) dp[v] = max(dp[v], 1) ; 
        }
        else {
            dfs(r, a, v) ; 
            if(dp[a] != -1) dp[v] = max(dp[v], dp[a] + 1) ;
        } 
    }

}


int main(){

    cin >> t ; 

    while(t--){
        
        cin >> n ; 

        int mx = 0 ; 

        for(int i = 1 ; i <= n ; i++){
            cin >> pec[i] ; 
            if(ck[pec[i][0]-'A'+1][pec[i][1]-'A'+1]) continue ; 
            ck[pec[i][0]-'A'+1][pec[i][1]-'A'+1] = 1 ; 
            grafo[pec[i][0]-'A'+1].push_back(pec[i][1]-'A'+1) ; 
            mx = max({pec[i][1]-'A'+1, pec[i][0]-'A'+1, mx}) ; 
        }

        // for(int i = 1 ; i <= mx ; i++){
        //     for(auto a : grafo[i]) cout << i << " " << a << "\n" ; 
        // }

        ans = -1 ; 

        for(int i = 1 ; i <= mx ; i++){ // i como raiz 
            for(int j = 1 ; j <= mx ; j++) dp[j] = -1, vis[j] = 0 ; 
            dfs(i, i, i) ; 
            // cout << dp[i] << "\n" ; 
            ans = max(ans, dp[i]) ; 
        }

        cout << ans << "\n" ; 

        for(int i = 0 ; i <= mx ; i++) grafo[i].clear() ;
        for(int i = 0 ; i <= mx ; i++){
            for(int j = 0 ; j <= mx ; j++) ck[i][j] = 0 ; 
        } 

    }

}
