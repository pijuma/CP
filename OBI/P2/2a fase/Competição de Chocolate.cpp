#include<bits/stdc++.h>
using namespace std ; 

// n total, m - por vez

const int maxn = 1e6 + 5 ; 

int n, m ;
int form[maxn], proib[maxn] ;

// paula começa

int solve(int n, int m){
    
    for(int i = 1 ; i <= n ; i++) form[i] = proib[i] = 0 ;
    
    for(int i = 0 ; i <= n ; i++){
        
        if(!form[i]){ 
            for(int j = 1 ; j <= m ; j++) form[i + j]++, proib[i + j] = j ; // minha pos é perdedora 
            // ent as outraas q chegam em mim ganham
        }
        
        else if(form[i] == 1){
            form[i + proib[i]]++ ; // minha pos ganha ent preciso dxr ruim p ele ir p minha
            // somando um valor proibido p prox n conseguir ir p minha 
            // tornando a minha boa 
            proib[i + proib[i]] = proib[i] ;
        }
        
    }
    //cout << form[n] << "\n" ;
    return form[n] ; // de qts formas eu consigo ganhar
    
}

int main(){
    
    cin >> n >> m ; 
    
    cout << (solve(n, m) ? "Paula\n" : "Carlos\n") ;
    
}
