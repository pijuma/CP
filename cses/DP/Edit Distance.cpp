#include<bits/stdc++.h>
using namespace std ;
 
//dp[p][f] numero de altera��es a serem feitas
//para dxr as seqs iguais indo at� p e f
// 3ops
//adicionar - dp[i][j-1] + 1
//remover
//mudar dp[i-1][j-1] + 1
 
const int maxn = 5e3 + 1 ;
 
string s, t ;
int dp[maxn][maxn] ;
int main(){
 
    cin >> s >> t ;
 
    for(int i = 1 ; i <= (int) s.size() ; i++) dp[i][0] = i ;
    for(int j = 1 ; j <= (int) t.size() ; j++) dp[0][j] = j ;
 
    for(int i = 1 ; i <= (int) s.size() ; i++){
 
        for(int j = 1 ; j <= (int) t.size() ; j++){
 
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] ;
            else{
 
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) ;
 
            }
 
        }
 
    }
 
    cout << dp[s.size()][t.size()] ;
}
