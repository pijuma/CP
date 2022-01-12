#include<bits/stdc++.h>
#define int long long
using namespace std ;


const int maxn = 255 ;

int n, x, v[maxn], ans[maxn][maxn*maxn] ;
bool dp[maxn][maxn*maxn] ;

// dp[i][j] - consigo soma j com os n-i ultimos ?
// qro a mlr resp ent tento formar com os do final se eu conseguir
// nao tem pq pegar da frente

int32_t main(){

    cin >> n >> x ;
    for(int i = 1 ; i <= n ; i++) cin >> v[i] ;

    for(int j = 0 ; j <= x ; j++){
        int used = 0 ;
        for(int i = n ; i >= 0 ; i--){ // vai até 0 p caso pegue o 1

            if(!j || used) dp[i][j] = 1, ans[i][j] = used ; // ja achei resp ou caso base
            else dp[i][j] = 0 ;

            if(dp[i][j-v[i]] && !used && j >= v[i]) used = i ; // achei uma carta boa
            // consigo terminar a soma, n tinha achado nenhuma antes
        }
    }

    int sum = x, id = ans[0][x] ;

    if(dp[0][x]) cout << "S\n" ;
    else { cout << "N\n" ; exit(0) ; }

    while(sum){
        sum -= v[id] ;
        cout << id - 1 << " " ;
        id = ans[id][sum] ;
    }

    cout << "\n" ;

}
