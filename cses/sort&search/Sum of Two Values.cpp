#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 2e5 + 1 ;
 
int n, x, a ;
map< long long, int > p ;
 
int main(){
 
    cin >> n >> x ;
 
    for(int i = 1 ; i <= n ; i++){
 
        cin >> a ;
 
        if(p.find(x - a) != p.end()){
 
            cout << p[x-a] << " " << i ;
            return 0;
        }
        p[a] = i ;
 
    }
 
    cout << "IMPOSSIBLE" ;
 
}
