#include<bits/stdc++.h>
using namespace std ; 

const int maxn = 1e5 + 1 ; 
const int MAX = 5e4 + 1;

// a -> a + s 
// s -> n° morangos 
// n eh n° coelhos 
// cada vez q receber um morango colocamos um fosforo no lugar
// caso seja o bloco todo colocamos apenas um fosforo no copo 
// n° tot = n° f na caixa + n° f na xicara
// o morango eh dado de a até a+s-1 

int n, m, s, a ;
int qtdbloco[MAX], meubloco[maxn], ini[MAX], fim[MAX], v[maxn], x ; 

int upd(int bloco, int l, int r){
    
    int qtd = 0 ; 
    
    if(l <= ini[bloco] && r >= fim[bloco]){
        
        qtdbloco[bloco]++ ; 
        return qtdbloco[bloco] ; 
        
    } 
    
    for(int f = max(l, ini[bloco]) ; f <= min(r, fim[bloco]) ; f++) v[f]++, qtd += (v[f]) ; 
    
    return qtd ; 
    
}
int main(){
    
    
    cin >> n >> m ; 
    
    int sq = sqrt(n) ; 
    
    for(int i = 1, j = sq, k = 0 ; i <= n ; i++, j++){
        
        if(j == sq){
            
            k++ ; 
            ini[k] = i ;
            j = 0 ; 
            
        }
        
        fim[k] = i ;
        meubloco[i] = k ;
        
    }
    
    for(int i = 1 ; i <= m ; i++){
        
        cin >> s >> a ; 
        
        x = 0 ; 
        
        for(int j = 1 ; j <= meubloco[a+s-1] ; j++) x += upd(j, a, a+s-1) ;
        
        cout << x << endl ; 
        
    }
    
}
