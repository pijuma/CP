#include<bits/stdc++.h>
using namespace std ;

const int maxn = 110 ;

int n, m, x ;
string s[3*maxn] ;

int main(){

    ifstream cin("cownomics.in");
    ofstream cout("cownomics.out");

    cin >> n >> m ;

    for(int i = 0 ; i < 2*n ; i++) cin >> s[i] ;

    for(int i = 0 ; i < m ; i++){
        map<char,int> app ;
        bool ok = 1 ;
        for(int j = 0 ; j < n ; j++) app[s[j][i]]++ ;
        for(int j = n ; j < 2*n ; j++) if(app[s[j][i]]) ok = 0 ;
        x += ok ;
    }

    cout << x << "\n" ;

}
