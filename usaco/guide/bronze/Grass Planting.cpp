#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5 + 5 ;

int n, diam, dp[maxn] ;
vector<int> grafo[maxn] ;

int main(){

    ifstream cin("planting.in");
    ofstream cout("planting.out");

    cin >> n ;

    for(int i = 1 ; i < n ; i++){
        int a, b ; cin >> a >> b ;
        grafo[a].push_back(b) ; grafo[b].push_back(a) ;
    }

    for(int i = 1 ; i <= n ; i++) diam = max(diam, (int)grafo[i].size() + 1) ;

    cout << diam << "\n" ;

}
