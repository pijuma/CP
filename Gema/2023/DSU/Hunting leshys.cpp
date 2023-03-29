#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 5e5 + 5 ; 

int n, m, pai[maxn], mn[maxn], poww[maxn] ; 

struct DSU{

    int find(int a){
        
        if(pai[a] == a){
            return a ; 
        }

        int y = find(pai[a]) ; // faz o "caminho" p att ja

        mn[a] = min(mn[pai[a]], mn[a]) ; // mn[i] = menor valor dele p pai geral da comp 
       // mn[a] é o min entre oq a guarda e que o pai dele guarda (ja fizemos o caminho até a raiz) 

        return pai[a] = y ; 

    }
    
    void join(int a, int b){
      // n pode otimizar, ordem importa
        pai[b] = a ; mn[b] = min(mn[a], mn[b]) ; 
    }

} dsu ; 

int main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n >> m ; 

    for(int i = 1 ; i <= n ; i++) cin >> poww[i] ; 
    for(int i = 1 ; i <= n ; i++) pai[i] = i, mn[i] = poww[i] ; 

    for(int i = 1 ; i <= m ; i++){
        char op ; int a, b ;
        cin >> op ; 
        if(op == '+'){
            cin >> a >> b ; 
            dsu.join(a, b) ; 
        }
        else{
            cin >> a ; 
            dsu.find(a) ;
            cout << mn[a] << "\n" ; 
        }
    }

}
