#include<bits/stdc++.h>
#define ll long long
using namespace std ; 

// n blocos cada um com um peso, um valor e qto aguenta 
// qual a maior soma de valores q podemos empilhar ? 
// supondo ij como ordem boa achamos q a ordem boa é sortar ai + pi > aj + pj
// montando a torre de cima pra baixo 
// definindo dp[i] sendo o maior valor com peso i 
// temos que tentando colocar o atual embaixo podemos olhar apenas para valores em cima que sejam 
// menores ou iguais ao qto eu aguento 
// ent temos a transição dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]) 

const int maxm = 2e4 + 5 ;
const int maxn = 1e3 + 5 ; 

ll dp[maxm], mx ; 
int n, s[maxn], p[maxn], v[maxn], tot, pe[maxn] ; 

bool cmp(int i, int j){ return p[i] + s[i] < p[j] + s[j] ; }

int main(){

	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 

	cin >> n ; 

	for(int i = 1 ; i <= n ; i++) cin >> p[i] >> s[i] >> v[i] ; //peso, suporto, valor

	for(int i = 1 ; i <= n ; i++)  pe[i] = i ; 

	sort(pe + 1, pe + 1 + n, cmp) ; 

    for(int i = 1 ; i <= n ; i++){

    	int x = pe[i] ; 

    	for(int j = s[x] ; j >= 0 ; j--){
    		dp[j + p[x]] = max(dp[j + p[x]], dp[j] + v[x]) ; 
    	}

    }

    for(int i = 0 ; i < maxm ; i++) mx = max(mx, dp[i]) ; 

    cout << mx << "\n" ; 

}
