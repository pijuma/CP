#include<bits/stdc++.h>
using namespace std ;
 
const int maxn = 101 ;
const int maxv = 1e5 ;
 
int x[maxn], n, dp[maxv+3] ;
vector<int> ans ;
 
//dp[i] � possivel usar a soma i? 1:0
 
int main(){
 
    cin >> n ;
 
    for(int i = 1 ; i <= n ; i++) cin >> x[i] ;
 
    dp[0] = 1 ;
 
    for(int i = 1 ; i <= n ; i++){
 
        for(int j = maxv ; j > 0 ; j--){
 
            if(j >= x[i]) dp[j] |= dp[j - x[i]] ;
 
        }
 
    }
 
    for(int i = 1 ; i <= maxv ; i++){
 
        if(dp[i] != 0) ans.push_back(i) ;
 
    }
 
    cout << ans.size() << endl;
 
    for(int i = 0 ; i < ans.size() ; i++) cout << ans[i] << " " ;
 
}
