#include<bits/stdc++.h>
using namespace std ;

const int maxn = 55 ;

int n, v[3*maxn], dif, ans ;

int main(){

    cin >> n ;

    for(int i = 1 ; i <= 2*n ; i++) cin >> v[i] ;

    ans = 11050 ;

    for(int i = 1 ; i <= 2*n ; i++){
        for(int j = 1 ; j <= 2*n ; j++){
                vector<int> att ;
                for(int k = 1 ; k <= 2*n ; k++){
                    if(k == i || k == j) continue ;
                    att.push_back(v[k]) ;
                }
                sort(att.begin(), att.end()) ;
                int dif = 0 ;
                for(int k = 0 ; k < att.size() - 1 ; k+=2){
                    dif += abs(att[k] - att[k+1]) ;
                }
                ans = min(ans, dif) ;
        }
    }

    cout << ans << "\n" ;

}
