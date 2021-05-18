#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 1 ;
int n, v[maxn], pos[maxn], pai[maxn] ;
vector<int> seq ;
vector<int>pilha ;
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> v[i] ;
        seq.push_back(v[i]) ;
 
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]) ;
 
        int p = it - pilha.begin() ;
 
        if(it == pilha.end()) pilha.push_back(v[i]) ;
        else *it = v[i] ;
 
        pos[p] = i ;
 
        if(p == 0) pai[i] = -1 ;
        else pai[i] = pos[p-1] ;
    }
 
    cout << pilha.size() << endl ;
 
}
