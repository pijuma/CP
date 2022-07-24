// https://www.hackerrank.com/contests/oifem-2021-final-dia1/challenges/batalla-en-el-bosque/problem
// dp[mask] - ver quais caras tem aresta p fora da mask 
// passar vendo p pegar cada cara
// p cada cara ve tds as arestas deles
// dp[{1, 2, 3}] = max(dp[{1, 2, 3}], dp[{1, 2}] + e[3])
#include<bits/stdc++.h>
#define ll long long
using namespace std ; 

const int maxn = 22 ; 

int t, n, ene[maxn], m ; 
ll dp[(1<<maxn)] ; 
vector<int> grafo[maxn] ; 

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> t ; 

    while(t--){
        
        cin >> n ; 

        for(int i = 0 ; i < n ; i++) cin >> ene[i] ;

        cin >> m ; 

        for(int i = 1 ; i <= m ; i++){
            int a, b ; cin >> a >> b ; 
            grafo[a].push_back(b) ; grafo[b].push_back(a) ; 
        } 

        memset(dp, 0, sizeof dp) ;  

        dp[0] = 0 ; dp[(1<<0)] = ene[0] ; 

        for(int mask = (1<<0) ; mask < (1<<n) ; mask++){
            for(int i = 0 ; i < n ; i++){
                if(!(mask&(1<<i))) continue ;
                for(auto a : grafo[i]){
                    if(mask&(1<<a)) continue ; 
                    if(dp[mask] > ene[a]){
                        dp[mask|(1<<a)] = max(dp[mask|(1<<a)], 2*dp[mask] + ene[a]) ; 
                    }
                }
            }
        }

        ll resp = dp[(1<<n)-1] ; 

        cout << (resp <= 0LL ? -1 : resp) << "\n" ; 

        for(int i = 0 ; i <= n ; i++) grafo[i].clear() ; 

    }

}
