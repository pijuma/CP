#include<bits/stdc++.h>
using namespace std ; 

// f(x) - qtd de intervalos q tem mdc <= x 

long long n, l, r, res, x ;
map<long long, long long> velho, novo ; 

int mdc(int a, int b){return (b == 0 ? a : mdc(b, a%b)) ;}

int main(){

    cin >> n >> l >> r ; 
    for(int i = 1 ; i <= n ; i++){
        cin >> x ;
        novo.clear() ; velho[0]++ ; 
        // velho = sufixo de mdc + colocando o atual 
        // no max log mdcs diferentes nlogn
        for(auto a : velho){
            long long val = a.first, qtd = a.second ; 
            int _mdc = mdc(val, x) ; // novo mdc é o mdc entre o atual e o sufixo testado 
            
            if(_mdc <= l) res += (r - l + 1)*qtd ; // vai ser incluido de f(l) até f(r)
            else if(_mdc >= l && _mdc <= r) res += (r - _mdc + 1)*qtd ; // vai ser incluido de f(_mdc) até f(r)
            novo[_mdc] += qtd ; // a freq do _mdc aumenta na qtd q tinha do val
        }
        velho = novo ; // passa a ser o velho
    }
    
    cout << res << "\n" ;
}
