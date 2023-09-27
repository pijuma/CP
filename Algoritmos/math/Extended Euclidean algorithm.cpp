// Extended Euclidean algorithm
#include<bits/stdc++.h>
using namespace std ; 

int gcd_ext(int a, int b, int *i, int *j){
    
    if(a < b) swap(a, b) ;

    if(!b){ // caso base 1 = i*a + b*j -> i = 1, j = 0 
        *i = 1, *j = 0 ; 
        return a ; 
    }
    
    int d = gcd_ext(b, a%b, i, j) ; // gcd normal 

    int lsti = *i, lstj = *j ; 

    /*
    gcd(a, b) = gcd(b, c) -> c = a-qb q = a/b
    ia + bj = bI + cJ -> bI + (a-qb)*J
    ia + bj = b(I-Jq) + Ja -> i = J e j = (I - Jq) 
    portanto sendo I e J os que temos do anterior (recursivo) queremos achar i e j 
    o caso base eh quando mdc = 1 
    *estamos basicamente resolvendo a eq diofantina e para essa temos um teorema 
    que quando ia+bj = 1 quer dizer que i é inverso modular de a e j é inverso modular de b 
    dai a utilidade do estendido  
    */
    
    *i = *j ; 
    *j = lsti - lstj*(a/b);
    
    return d ; 
    
}

int main(){
    
    int a, b ; cin >> a >> b ; 
    int i, j ; 
    gcd_ext(a, b, &i, &j) ; 
    
    cout << i << " " << j << "\n" ;
    
}
