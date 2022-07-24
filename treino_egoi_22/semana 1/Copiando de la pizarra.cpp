// https://www.hackerrank.com/contests/oifem-2021-final-dia-2/challenges/copiando-de-la-pizarra/problem
// primo p divisor de n + 1 q divida tb n! + 1 e (n+1)!
// acha tds divs de n 
#include<bits/stdc++.h>
#define int long long
using namespace std ; 

int n, t ; 

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

    cin >> t ; 

    while(t--){
        cin >> n ;
        vector<int> ans ; 

        int x = n + 1 ; 

        for(int i = 2 ; i * i <= x ; i++){
            if(x%i == 0) ans.push_back(i) ; 
            while(x%i == 0) x /= i ;
        }

        if(x > 1) ans.push_back(x) ; 

        bool ok = 0 ; 
        
        for(auto a : ans){
            if(a <= (n+1) && a > n) ok = 1 ; 
        }

        cout << (ok ? "SI\n" : "NO\n") ; 
    }

}
