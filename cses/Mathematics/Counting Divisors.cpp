#include<bits/stdc++.h>
using namespace std ;
 
int n ;
vector<int> d ;
 
int divi(int x){
 
    d.clear() ;
 
    for(int i = 1 ; i * i <= x ; i++){
 
        if(x/i != i && x%i == 0) d.push_back(x/i), d.push_back(i) ;
        else if(x%i == 0)d.push_back(i) ;
 
    }
 
    return d.size() ;
 
}
 
int main(){
 
    int t ;
 
    cin >> t ;
 
    while(t--){
 
        cin >> n ;
 
        cout << divi(n) << endl ;
 
    }
 
}
