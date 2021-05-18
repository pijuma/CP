#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 5e3 + 10 ;
 
long long dp[maxn][maxn], n, x[maxn], sp[maxn], s ;
 
// para cada jogada temos duas op��es pegar
// o 1o ou o �ltimo e queremos maximizar a pontua��o
// dp[i][j] = maxima pontua��o no intervalo [i,j]
// base: dp[i][j] = i, para i = j
// sendo s[i][j] a soma de [i,j]
// a soma maxima que podemos obter retirando o 1o �
// s[i][j] - dp[i+1][j]
// retirando o ultimo s[i][j] - dp[i][j-1]
// e queremos maximizar portando fazemos o maximo entre
// as duas op��es para cada i e j
 
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> x[i] ;
 
        sp[i] = sp[i-1] + x[i] ;
 
    }
 
    for(int i = n; i > 0 ; i--){
 
        for(int j = i ; j <= n ; j++){
 
            if(i == j) dp[i][j] = x[i] ;
 
            else {
 
                dp[i][j] = max(sp[j] - sp[i-1] - dp[i+1][j], sp[j] - sp[i-1] - dp[i][j-1]) ;
 
            }
 
        }
 
    }
 
    cout << dp[1][n] ;
 
}
