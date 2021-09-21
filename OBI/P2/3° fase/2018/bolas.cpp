#include<bits/stdc++.h>
using namespace std ;

int b, qtd[10] ;

int main(){
    int n = 8 ;
    for(int i = 0, a ; i < n ; i++){
        cin >> a ;
        if((b&(1<<a))!=0) qtd[a]++ ;
        b |= (1<<a) ;
    }
    for(int i = 0 ; i < 10 ; i++){
        if(qtd[i]>=4){
            cout << "N\n" ;
            return 0 ;
        }
    }
    cout << "S\n" ;
}
