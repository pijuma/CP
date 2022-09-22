#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5 + 5 ;
const int maxx = 110 ;

struct P{
    int x, y ;
};

int n, b ;
vector<int> xs, ys ;
P pto[maxx] ;

// testa tds os ptos como sendo o corte - tds os x's
// e tds as combs de y's
// conta p todos e pega o mlr caso

int main(){

    ifstream cin("balancing.in");
    ofstream cout("balancing.out");

    cin >> n >> b ;

    for(int i = 1 ; i <= n ; i++){
        cin >> pto[i].x >> pto[i].y ;
        xs.push_back(pto[i].x), ys.push_back(pto[i].y) ;
    }

    int ans = n ;

    for(auto a : xs){
        for(auto b : ys){
            int c1 = 0, c2 = 0, c3 = 0, c4 = 0 ;
            for(int i = 1 ; i <= n ; i++){
                if(pto[i].x <= a && pto[i].y <= b) c1++ ;
                else if(pto[i].x <= a && pto[i].y > b) c2++ ;
                else if(pto[i].x > a && pto[i].y > b) c3++ ;
                else c4++ ;
            }
            ans = min(ans, max({c1, c2, c3, c4})) ;
        }
    }

    cout << ans << "\n" ;

}
