#include<bits/stdc++.h>
using namespace std ;
 
int n, a, b, qtd, last ;
 
int main(){
 
    cin >> n ;
 
    vector<pair<int, int>> kra ;
 
    for(int i = 1 ; i <= n ; i++){
        cin >> a >> b ;
        kra.push_back({a, 1}), kra.push_back({b, -1}) ;
    }
 
    sort(kra.begin(), kra.end()) ;
 
    for(pair<int,int> a : kra){
        last += a.second ;
        qtd = max(qtd, last) ;
    }
 
    cout << qtd << "\n" ;
 
}
