#include<bits/stdc++.h>
#define int long long
using namespace std ;

int n, k ;

int32_t main(){

    ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;

    cin >> n >> k ;

    priority_queue<int, vector<int>, greater<int>> d1, d2 ;
    vector<int> took ;

    for(int i = 1 ; i <= n ; i++){
        int d, t ; cin >> d >> t ;
        if(d == 2) d2.push(t) ;
        else d1.push(t) ;
    }

    int st = 0, sd = 0 ;

    while(true){
        if(sd >= k || d2.empty()) break ;
        sd += 2 ;
        int timer = d2.top() ;
        took.push_back(timer) ;
        st += timer ; d2.pop() ;
    }

    if(sd < k){
        while(true){
            if(sd >= k || d1.empty()) break ;
            sd++ ; st += d1.top() ; d1.pop() ;
        }
    }

    if(sd == k + 1 && d1.size()){
        int mn = d1.top() ; int mx = took.back() ;
        if(mn < mx){
            sd-- ;
            st -= (mx - mn) ;
            d1.pop() ; took.pop_back() ;
        }
    }

    while(!d1.empty() && took.size()){
        int l1 = d1.top() ; d1.pop() ;
        if(d1.empty()) break ;
        int l2 = d1.top() ; d1.pop() ;
        int ot = took.back() ;
        if(ot > l2 + l1){
            st -= (l2 + l1 - ot) ;
            took.pop_back() ;
        }
        else break ;
    }

    cout << st << "\n" ;

}
